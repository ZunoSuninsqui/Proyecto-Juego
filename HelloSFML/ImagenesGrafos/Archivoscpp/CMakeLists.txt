cmake_minimum_required(VERSION 3.28)
project(HelloSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloSFML main.cpp
        Button.cpp
        Button.h
        Escena.cpp
        Escena.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio)
