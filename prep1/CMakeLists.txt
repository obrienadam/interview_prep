cmake_minimum_required(VERSION 2.8)

project(interview_prep)
add_executable(${PROJECT_NAME} "main.cpp" "crsgraph.h" "crsgraph.cpp")

add_executable("flood" "flood.cpp")
add_executable("first_occurence" "first_occurence.cpp")
add_executable("hourglass" "hourglass.cpp")
