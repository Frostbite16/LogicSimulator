cmake_minimum_required(VERSION 3.15)
project(firstSFML)

set(CMAKE_CXX_STANDARD 14)


include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(firstSFML main.cpp
        Logic/LogicComponents/LogicComponent.cpp
        Logic/LogicComponents/LogicComponent.h
        Logic/LogicComponents/AndComponent.cpp
        Logic/LogicComponents/AndComponent.h
        Logic/LogicControl.cpp
        Logic/LogicControl.h
        Logic/LogicComponents/LogicPoint.cpp
        Logic/LogicComponents/LogicPoint.h
        Logic/LogicComponents/OrComponent.cpp
        Logic/LogicComponents/wire.cpp
        Logic/LogicComponents/wire.h
        Logic/LogicControl.cpp
        Logic/LogicControl.cpp
        Logic/LogicControl.cpp)
target_link_libraries(firstSFML -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d)