# CMakeLists.txt for solarSim
# 16-04-2025 by madpl

cmake_minimum_required(VERSION 4.0.1)
project(solarSim)
add_definitions(-Os -march=native -std=c++23)

file(GLOB_RECURSE SOURCE ./source/*)

find_package(SFML 2.5 REQUIRED
	COMPONENTS system window graphics)

find_package(TGUI REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
	sfml-system sfml-window sfml-graphics tgui)
