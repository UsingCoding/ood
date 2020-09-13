#include "ReadHeadDuck.hpp"
#include <memory>

#include "../../DanceBehavior/MinuetDance/MinuetDance.hpp"
#include "../../FlyBehavior/FlyWithWings/FlyWithWings.hpp"
#include "../../FlyCounter/FlyCounter/FlyCounter.hpp"

ReadHeadDuck::ReadHeadDuck(): Duck(std::make_unique<FlyWithWings>(), std::make_unique<MinuetDance>(), std::make_unique<FlyCounter>())
{
}
