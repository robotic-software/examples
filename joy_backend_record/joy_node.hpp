#include <string>
#include "engine/alice/alice_codelet.hpp"
#include "messages/joystick_state.capnp.h"

namespace isaac {

    class Joy : public alice::Codelet {
        public:
            void start() override;
            void tick() override;

            ISAAC_PROTO_RX(JoystickStateProto, trigger);
    };

} 

ISAAC_ALICE_REGISTER_CODELET(isaac::Joy)
