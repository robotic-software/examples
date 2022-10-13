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
#include <unistd.h>


namespace isaac {

// Render a mesh in 3D and 2D projection view
class ping_no_json : public alice::Codelet {
 public:
  void tick() override {
    std::cout << "tick" << std::endl;
  }

  void start() override {
    tickPeriodically();
  }
};

}  // namespace isaac

ISAAC_ALICE_REGISTER_CODELET(ping_no_json);



int main(int argc, char** argv) {
  isaac::alice::Application app(isaac::alice::ParseApplicationCommandLine("ping_no_json"));
  app.loadFromText
  
  {
    "graph": {
        "nodes": [
            {
                "name": "ping_no_json",
                "components": [
                    {
                        "name": "ping_no_json",
                        "type": "ping_no_json"
                    }
                ]
            }   
        ],
        "edges": [

        ]
    },
    "config": {
        "ping_no_json": {
            "ping_no_json": {
                "tick_period": "10Hz"
            }
        }
    }
  
  })???");

  app.runBlocking();
  
  
  return 0;
}
