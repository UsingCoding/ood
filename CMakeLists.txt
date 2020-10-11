cmake_minimum_required(VERSION 3.17)
project(ood)

set(CMAKE_CXX_STANDARD 20)

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
        src/Observer/Display/ExpensiveDisplay/ExpensiveDisplay.cpp
        src/Observer/Display/ExpensiveDisplay/ExpensiveDisplay.hpp
)

add_executable(observer_test
        src/Observer_test/main.cpp
        src/Observer_test/PriorityTest/Observable/MockObservable.cpp
        src/Observer_test/PriorityTest/Observer/MockObserver.cpp
        src/Observer_test/FewObservableTest/Observer/MockObserver.cpp
        src/Observer_test/FewObservableTest/Observer/MockObserver.hpp
        src/Observer/WeatherData/WeatherData.cpp
        src/Observer/WeatherData/WeatherData.hpp
)

include_directories(src/Catch2)