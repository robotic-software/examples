/*
Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.

NVIDIA CORPORATION and its licensors retain all intellectual property
and proprietary rights in and to this software, related documentation
and any modifications thereto. Any use, reproduction, disclosure or
distribution of this software and related documentation without an express
license agreement from NVIDIA CORPORATION is strictly prohibited.
*/
#include "MyGoalGenerator.hpp"
#include "messages/math.hpp"
namespace isaac {
namespace examples {

void MyGoalGenerator::start() {
	tickPeriodically();
}

void MyGoalGenerator::tick() {
	
	auto goal_proto = tx_my_goal().initProto();

	//set params: (from the Goal2Proto definition)
	//For any proto messages, a set of convenient methods are provided to set their fields
	goal_proto.setStopRobot(false);
	goal_proto.setTolerance(0.1); //10 cm
	goal_proto.setGoalFrame("world");

	//ToProto(Pose2d::Translation(1.1, 2.2), goal_proto.initGoal());
	ToProto( Pose2d::Translation(get_desired_location()), goal_proto.initGoal());
	tx_my_goal().publish(); 
	
	//receive
	rx_goal_feedback().processLatestNewMessage (
		[this](auto feedback_proto, int64_t, int64_t) {
			const bool arrived = feedback_proto.getHasArrived();
				if ( arrived ) 
					LOG_INFO("Arrived!");
				else
					LOG_INFO("Going to the target!");

				show("arrived", arrived ? 1.0 : -1.0 );
		});
		}
	}  // namespace examples
}  // namespace isaac
