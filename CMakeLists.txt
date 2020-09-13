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
        src/Strategy/task2/FlyCounter/IFlyCounter.hpp
        src/Strategy/task2/FlyCounter/NoFlyCounter/NoFlyCounter.cpp
        src/Strategy/task2/FlyCounter/NoFlyCounter/NoFlyCounter.hpp
        src/Strategy/task2/FlyCounter/FlyCounter/FlyCounter.cpp
        src/Strategy/task2/FlyCounter/FlyCounter/FlyCounter.hpp
)

add_executable(
        strategy-task-3 src/Strategy/task3/main.cpp
        src/Strategy/task3/Ducks/Duck/Duck.cpp
        src/Strategy/task3/Ducks/DecoyDuck/DecoyDuck.cpp
        src/Strategy/task3/Ducks/MallardDuck/MallardDuck.cpp
        src/Strategy/task3/Ducks/ReadHeadDuck/ReadHeadDuck.cpp
)
add_executable(observer src/Observer/main.cpp)
include_directories(src/Catch2)