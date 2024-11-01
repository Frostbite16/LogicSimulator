cmake_minimum_required(VERSION 3.15)
project(firstSFML)

set(CMAKE_CXX_STANDARD 14)


include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(firstSFML main.cpp)
target_link_libraries(firstSFML -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d)