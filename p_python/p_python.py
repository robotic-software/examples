from isaac import *

# A Python codelet for proportional control
# For comparison, please see the same logic in C++ at "ProportionalControlCpp.cpp".
#
# We receive odometry information, from which we extract the x position. Then, using refence and
# gain parameters that are provided by the user, we compute and publish a linear speed command
# using `control = gain * (reference - position)`
class ProportionalControlPython(Codelet):
    def start(self):
        
        # This part will be run once in the beginning of the program
        self.x = 0.0
        self.t = 1.0
        
        # We can tick periodically, on every message, or blocking. See documentation for details.
        self.tick_periodically(0.01)
        self.gain = self.config["gain"]
        self.tx = self.isaac_proto_tx("StateProto", "cmd")    
        
    def tick(self):    
        reference = self.config["desired_position_meters"]
        
        # Compute the control action
        control = self.gain * (reference - self.x)
        self.x = self.x + control*0.01        
        
        self.show("position (m)", self.x)
    
        tx_message = self.tx.init()
        data = tx_message.proto.init('data', 2)
        data[0] = self.x    # linear speed
        data[1] = 0.0       # This simple example sets zero angular speed
        self.tx.publish()
        

def main():
    app = Application("apps/examples/p_python/p_python.app.json")
    app.nodes["p_python"].add(ProportionalControlPython)
    
    app.run()
    print("Main")


if __name__ == '__main__':
    main()