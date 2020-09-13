#include "DecoyDuck.hpp"
#include <memory>

#include "../../DanceBehavior/NoDance/NoDance.hpp"
#include "../../FlyBehavior/NoFly/NoFly.hpp"

DecoyDuck::DecoyDuck(): Duck(std::make_unique<NoFly>(), std::make_unique<NoDance>())
{

}
