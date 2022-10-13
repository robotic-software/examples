#include "Ping_v2.hpp"

using namespace std;

/*
    void Ping::start() {}
    void Ping::tick() {}
    void Ping::stop() {}
*/

void Ping_v2::start() {    
    LOG_INFO("Start function");
    tickPeriodically();
}

void Ping_v2::tick() {
    LOG_INFO("Tick");

    auto proto = tx_ping().initProto();
    proto.setMessage(get_message());
    tx_ping().publish();

    
}

void Ping_v2::stop() {
    LOG_INFO("Stop");
}



