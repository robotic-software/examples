/*
Copyright (c) 2018, NVIDIA CORPORATION. All rights reserved.

NVIDIA CORPORATION and its licensors retain all intellectual property
and proprietary rights in and to this software, related documentation
and any modifications thereto. Any use, reproduction, disclosure or
distribution of this software and related documentation without an express
license agreement from NVIDIA CORPORATION is strictly prohibited.
*/
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "engine/alice/alice_codelet.hpp"
#include "engine/alice/tools/parse_command_line.hpp"
#include "engine/gems/image/color.hpp"
#include "engine/gems/image/io.hpp"
#include "engine/gems/image/utils.hpp"
#include <iostream>
#include <string>

#include <unistd.h>

namespace isaac {


// Render an image with a projection model
class PinholeImageNode : public alice::Codelet {
 public:
  void tick() override {
    show("image", [&](sight::Sop& sop) {
      geometry::Pinhole<double> pinhole;
      pinhole.dimensions = image_.dimensions();
      pinhole.center = get_center();
      pinhole.focal = get_focal();
      sop.transform = sight::SopTransform(get_world_T_camera(), pinhole);
      sop.add(image_);
    });
  }

  void start() override {
    tickPeriodically();
    LoadPng(get_path(), image_);
  }

  // Transformation from the camera frame to the world
  ISAAC_PARAM(Pose3d, world_T_camera,
              (Pose3d{SO3d::FromAxisAngle({1.0, 0.0, 0.0}, Pi<double>) *
                          SO3d::FromAxisAngle({0.0, 1.0, 0.0}, Pi<double> / 2) *
                          SO3d::FromAxisAngle({0.0, 0.0, 1.0}, Pi<double> / 2),
                      Vector3d(0.0, 0.0, 1.0)}));
  
  ISAAC_PARAM(Vector2d, center, Vector2d(270.0, 480.0));
  ISAAC_PARAM(Vector2d, focal, Vector2d(270.0, 270.0));
  ISAAC_PARAM(std::string, path);
  ISAAC_PARAM(std::string, name);

 protected:
  Image3ub image_;
};


class SinVis : public alice::Codelet {
  public:
    void start() override {
      x = 0.0;
      amplitude = 1.0;
      current_time = 0.0;
      freq = 3.0;
      tickPeriodically();
    }

    void tick() override {
      
      current_time += 0.01;
      x = amplitude * ( sin( 2*M_PI*(1/freq)*current_time ) ); 
      show( "sin_plot", x);


    }

  private:
    double x;
    double amplitude;
    double freq;
    double current_time;
};


void ImageToSight(alice::Application& app) {
  
  auto pinhole = app.createMessageNode("pinhole")->addComponent<PinholeImageNode>();
  pinhole->async_set_name("pinhole");
  pinhole->async_set_path("/home/jcacace/Desktop/isaac-dev/engine/engine/gems/image/data/stairs.png");
  pinhole->async_set_tick_period("2hz");

  auto sin_vis = app.createMessageNode("SinVis")->addComponent<SinVis>();
  sin_vis->async_set_tick_period("10hz");

}

}  // namespace isaac

ISAAC_ALICE_REGISTER_CODELET(isaac::PinholeImageNode);
ISAAC_ALICE_REGISTER_CODELET(isaac::SinVis);

int main(int argc, char** argv) {

  isaac::alice::Application app(isaac::alice::ParseApplicationCommandLine("visualization"));
  
  app.loadFromText(R"???(
{
  "modules": ["sight"],
  "config": {
    "websight": {
      "WebsightServer": {
        "port": 3000,
        "ui_config": {
          "windows": {
            "Pinnole View": {
              "renderer": "2d",
              "channels": [
                { "name": "visualization/pinhole/isaac.PinholeImageNode/image" }
              ]
            }
          }
        }
      }
    }
  }
})???");

  isaac::ImageToSight(app);
  app.runBlocking();

  return 0;
}
