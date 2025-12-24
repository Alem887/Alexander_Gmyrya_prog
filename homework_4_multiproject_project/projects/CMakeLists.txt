cmake_minimum_required(VERSION 3.2...3.27.5)

project(homework_4_multiproject_project)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(obuchaika)
add_subdirectory(sort)
add_subdirectory(sort_test)

set (CMAKE_SUPPRESS_REGENERATION true)