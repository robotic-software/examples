/*
Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.

NVIDIA CORPORATION and its licensors retain all intellectual property
and proprietary rights in and to this software, related documentation
and any modifications thereto. Any use, reproduction, disclosure or
distribution of this software and related documentation without an express
license agreement from NVIDIA CORPORATION is strictly prohibited.
*/
#pragma once

#include "engine/alice/alice_codelet.hpp"
#include "messages/differential_base.capnp.h"

namespace isaac {
	namespace examples {

		// Skeleton for tutorial in the first ISAAC webinar.
		// For the complete version, please check GoalGenerator.hpp.
		class MyGoalGenerator : public alice::Codelet {
			public:
				void start() override;
				void tick() override;

				//Goal2Proto is a datastructure used to exchange messages of navigation goal type
				/*

					struct Goal2Proto {
						# The goal expressed in Pose2
						goal @0: Pose2dProto;
						# the tolerance radius of the goal.
						tolerance @1: Float32;
						# name of the frame the goal is.
						goalFrame @2: Text;
						# Whether or not we should stop the robot. If set to true all the other parameters will be ignored
						stopRobot @3: Bool;
					}

					defined in: //messages/differential_base.capnp
				*/
				ISAAC_PROTO_TX(Goal2Proto, my_goal);

				/*# A status update which is sent continuously as a reply to receiving a goal message. This can be
				# used to keep track if the robot has arrived at the destination.
				struct Goal2FeedbackProto {
					# Remaining relative pose to the goal, or identity in case hasGoal is false.
					robotTGoal @0: Pose2dProto;
					# Whether the robot currently has a goal
					hasGoal @1: Bool;
					# Whether the robot considers himself to be arrived at the target
					hasArrived @2: Bool;
					# Whether the robot considers himself to not move anymore
					isStationary @3: Bool;
				}

				defined in: //messages/differential_base.capnp
				*/
				ISAAC_PROTO_RX(Goal2FeedbackProto, goal_feedback);

				/*Add new param to specify the location*/
				ISAAC_PARAM(Vector2d, desired_location, Vector2d(3.3, 4.4) );
		};

	}  // namespace tutorials
}  // namespace isaac

ISAAC_ALICE_REGISTER_CODELET(isaac::examples::MyGoalGenerator);
