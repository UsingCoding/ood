cmake_minimum_required(VERSION 3.10)
project(ood)

#set(CMAKE_CXX_STANDARD 20)

add_executable(
        strategy-task-1 src/Strategy/task1/main.cpp
        src/Strategy/task1/DanceBehavior/DanceWaltz/DanceWaltz.cpp
        src/Strategy/task1/DanceBehavior/MinuetDance/MinuetDance.cpp
        src/Strategy/task1/DanceBehavior/NoDance/NoDance.cpp
        src/Strategy/task1/Ducks/Duck/Duck.cpp
        src/Strategy/task1/Ducks/DecoyDuck/DecoyDuck.cpp
        src/Strategy/task1/Ducks/MallardDuck/MallardDuck.cpp
        src/Strategy/task1/Ducks/ReadHeadDuck/ReadHeadDuck.cpp
        src/Strategy/task1/FlyBehavior/FlyWithWings/FlyWithWings.cpp
        src/Strategy/task1/FlyBehavior/NoFly/NoFly.cpp
)
add_executable(
        strategy-task-2 src/Strategy/task2/main.cpp
        src/Strategy/task2/DanceBehavior/DanceWaltz/DanceWaltz.cpp
        src/Strategy/task2/DanceBehavior/MinuetDance/MinuetDance.cpp
        src/Strategy/task2/DanceBehavior/NoDance/NoDance.cpp
        src/Strategy/task2/Ducks/Duck/Duck.cpp
        src/Strategy/task2/Ducks/DecoyDuck/DecoyDuck.cpp
        src/Strategy/task2/Ducks/MallardDuck/MallardDuck.cpp
        src/Strategy/task2/Ducks/ReadHeadDuck/ReadHeadDuck.cpp
        src/Strategy/task2/FlyBehavior/FlyWithWings/FlyWithWings.cpp
        src/Strategy/task2/FlyBehavior/NoFly/NoFly.cpp
)

add_executable(
        strategy-task-3 src/Strategy/task3/main.cpp
        src/Strategy/task3/Ducks/Duck/Duck.cpp
        src/Strategy/task3/Ducks/DecoyDuck/DecoyDuck.cpp
        src/Strategy/task3/Ducks/MallardDuck/MallardDuck.cpp
        src/Strategy/task3/Ducks/ReadHeadDuck/ReadHeadDuck.cpp
        src/Strategy/task3/DanceBehavior/DanceBehavior.cpp
        src/Strategy/task3/DanceBehavior/DanceBehavior.hpp
        src/Strategy/task3/FlyBehavior/FlyBehavior.cpp
        src/Strategy/task3/FlyBehavior/FlyBehavior.hpp
)
add_executable(observer
        src/Observer/main.cpp
        src/Observer/Observer/IObserver.hpp
        src/Observer/Observer/Observable.hpp
        src/Observer/Observer/CObserverable.cpp
        src/Observer/Observer/CObserverable.hpp
        src/Observer/Display/Display/Display.cpp
        src/Observer/Display/Display/Display.hpp
        src/Observer/WeatherData/WeatherData.cpp
        src/Observer/WeatherData/WeatherData.hpp
        src/Observer/Display/StatsDisplay/StatsDisplay.cpp
        src/Observer/Display/StatsDisplay/StatsDisplay.hpp
        src/Observer/Counter/AverageCounter.cpp
        src/Observer/Counter/AverageCounter.hpp
        src/Observer/Counter/AverageWindDirectionMeter.cpp
        src/Observer/Counter/AverageWindDirectionMeter.hpp
        src/Observer/Display/ExpensiveDisplay/ExpensiveDisplay.cpp
        src/Observer/Display/ExpensiveDisplay/ExpensiveDisplay.hpp
        src/Observer/MemoryIndex/MemoryIndex.hpp)

add_executable(observer_test
        src/Observer_test/main.cpp
        src/Observer_test/PriorityTest/Observable/MockObservable.cpp
        src/Observer_test/PriorityTest/Observer/MockObserver.cpp
        src/Observer_test/FewObservableTest/Observer/MockObserver.cpp
        src/Observer_test/FewObservableTest/Observer/MockObserver.hpp
        src/Observer/WeatherData/WeatherData.cpp
        src/Observer/WeatherData/WeatherData.hpp
        src/Observer_test/SafeObserversRemoving/Observer/MockObserver.cpp src/Observer_test/SafeObserversRemoving/Observer/MockObserver.hpp src/Observer_test/SafeObserversRemoving/Observable/MockObservable.cpp src/Observer_test/SafeObserversRemoving/Observable/MockObservable.hpp)

add_executable(decorator-beverage
        src/Decorator/Beverage/Beverage/IBeverage.hpp
        src/Decorator/Beverage/Beverage/Beverage.hpp
        src/Decorator/Beverage/Beverages/Coffee/Coffee.hpp
        src/Decorator/Beverage/Beverages/Cappuccino/Cappuccino.hpp
        src/Decorator/Beverage/Beverages/Latte/Latte.hpp
        src/Decorator/Beverage/Beverages/Tea/Tea.hpp
        src/Decorator/Beverage/Beverages/MilkShake/MilkShake.hpp
        src/Decorator/Beverage/Condiments/Condiments.hpp
        src/Decorator/Beverage/main.cpp
        src/Decorator/Beverage/Beverages/Latte/DoubleLatte.hpp
        src/Decorator/Beverage/Beverages/Cappuccino/DoubleCappuccino.hpp
        src/Decorator/Beverage/Beverages/Tea/CeylonTea.hpp
        src/Decorator/Beverage/Beverages/Tea/GreenTea.hpp
        src/Decorator/Beverage/Beverages/Tea/YellowTea.hpp
        src/Decorator/Beverage/Beverages/Tea/BergamotTea.hpp
        src/Decorator/Beverage/Beverages/MilkShake/SmallMilkShake.hpp
        src/Decorator/Beverage/Beverages/MilkShake/MediumMilkShake.hpp
        src/Decorator/Beverage/Beverages/MilkShake/BigMilkShake.hpp
        src/Decorator/Beverage/Condiments/Cream.hpp
        src/Decorator/Beverage/Condiments/Chocolate.hpp
        src/Utils/Strings.hpp
        src/Decorator/Beverage/Condiments/Liquor.hpp
        src/Decorator/Beverage/Condiments/ChocolateLiquor.hpp
        src/Decorator/Beverage/Condiments/WalnutLiquor.hpp)


add_executable(decorator-streams
        src/Decorator/Streams/main.cpp
        src/Decorator/Streams/Input/IInputDataStream.hpp
        src/Decorator/Streams/Output/IOutputDataStream.hpp
        src/Decorator/Streams/Output/MemoryOutputStream/MemoryOutputStream.cpp
        src/Decorator/Streams/Output/MemoryOutputStream/MemoryOutputStream.hpp
        src/Decorator/Streams/Input/MemoryInputStream/MemoryInputStream.cpp
        src/Decorator/Streams/Input/MemoryInputStream/MemoryInputStream.hpp
        src/Decorator/Streams/Application/TransformApplication.cpp
        src/Decorator/Streams/Application/TransformApplication.hpp
        src/Decorator/Streams/Output/CryptInputStream/CryptOutputDecoratorStream.cpp
        src/Decorator/Streams/Output/CryptInputStream/CryptOutputDecoratorStream.hpp
        src/Decorator/Streams/Output/CompressOutputDecoratorStream/CompressOutputDecoratorStream.cpp
        src/Decorator/Streams/Output/CompressOutputDecoratorStream/CompressOutputDecoratorStream.hpp
        src/Decorator/Streams/Input/DecompressInputStreamDecorator/DecompressInputStreamDecorator.cpp
        src/Decorator/Streams/Input/DecompressInputStreamDecorator/DecompressInputStreamDecorator.hpp
        src/Decorator/Streams/Input/DecryptInputStreamDecorator/DecryptInputStreamDecorator.cpp
        src/Decorator/Streams/Input/DecryptInputStreamDecorator/DecryptInputStreamDecorator.hpp)

include_directories(src/Catch2)
include_directories(src/Utils)