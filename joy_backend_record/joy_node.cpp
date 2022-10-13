#include <iostream>
#include "joy_node.hpp"

using namespace std;

namespace isaac {

	void Joy::start() {
		tickPeriodically();
	}

	void Joy::tick() {
		
		/*
		JoystickStateProto::Reader proto = rx_trigger().getProto();
		//cout<< "proto: " << proto.getAxes() << endl;
		cout<< "proto: " << proto.hasButtons() << endl;
		*/

		/*
		JoystickStateProto::Reader proto = rx_trigger().processLatestNewMessage();
		cout<< "proto: " << proto.hasButtons() << endl;
		*/
		
		//receive
		rx_trigger().processLatestNewMessage (
			[this](auto feedback_proto, int64_t, int64_t) {
	 			cout << "Size: " << feedback_proto.getAxes().size() << endl;
				cout << "Asse 0: " << feedback_proto.getAxes()[0].getX() << " " << feedback_proto.getAxes()[0].getY() << endl;
				cout << "Asse 1: " << feedback_proto.getAxes()[1].getX() << " " << feedback_proto.getAxes()[1].getY() << endl;
			}
		);		
	}

}  // namespace isaac
