#include "Ping.hpp"

namespace isaac {

void Ping::start() {
  tickPeriodically();
}

void Ping::tick() {
  LOG_INFO(get_mymessage().c_str());
}

}  // namespace isaac
