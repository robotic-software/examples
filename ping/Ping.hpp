#include <string>
#include "engine/alice/alice_codelet.hpp"

namespace isaac {

  class Ping : public alice::Codelet {
  public:
    // Has whatever needs to be run in the beginning of the program
    void start() override;
    // Has whatever needs to be run repeatedly
    void tick() override;

    // Message to be printed at every tick
    ISAAC_PARAM(std::string, mymessage, "Hello World!");
  };

}  // namespace isaac

ISAAC_ALICE_REGISTER_CODELET(isaac::Ping);
