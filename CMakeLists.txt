cmake_minimum_required(VERSION 4.1)
project(PhysicsSim_)

set(CMAKE_CXX_STANDARD 23)

add_executable(PhysicsSim_ main.cpp)

find_package(raylib REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
