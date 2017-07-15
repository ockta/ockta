cmake_minimum_required(VERSION 3.0)
project(ockta)

# GLFW
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(libs/glfw)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")

# Includes
include_directories(
    include/
    libs/glfw/include/
    libs/glad/include/
    libs/glm/)

# Add GLAD as a library
add_library(glad libs/glad/src/glad.c)

# Sources
file(GLOB PROJECT_SOURCES src/*.cpp)

add_definitions(-DGLFW_INCLUDE_NONE)
add_executable(ockta ${PROJECT_SOURCES})
target_link_libraries(ockta glfw glad)
