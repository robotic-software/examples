//Codelet header file 
#include "engine/alice/alice_codelet.hpp"
#include <iostream>
 #include "messages/ping.capnp.h"
//Do not use constructors or destructors:
//  You do not have access to any Isaac Robot Engine 
//  functionality (such as configuration) in the constructor.
class Ping_v2 : public isaac::alice::Codelet {
    public:
        void start() override; //Init stuff
        void stop() override; //Destroy stuff
        void tick() override; //Sene-plan-act3
        
        ISAAC_PARAM(std::string, message, "Ping");
        ISAAC_PROTO_TX(PingProto, ping);

};

ISAAC_ALICE_REGISTER_CODELET( Ping_v2 ); //Nome della classe