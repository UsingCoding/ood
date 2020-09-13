#include "DecoyDuck.hpp"
#include <memory>

#include "../../DanceBehavior/NoDance/NoDance.hpp"
#include "../../FlyBehavior/NoFly/NoFly.hpp"
#include "../../FlyCounter/NoFlyCounter/NoFlyCounter.hpp"

DecoyDuck::DecoyDuck(): Duck(std::make_unique<NoFly>(), std::make_unique<NoDance>(), std::make_unique<NoFlyCounter>())
{

}
