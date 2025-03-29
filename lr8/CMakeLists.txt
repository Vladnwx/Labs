cmake_minimum_required(VERSION 3.10)
project(MyProject)
file(GLOB SOURCES "*.cpp" "**/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})