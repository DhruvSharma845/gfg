cmake_minimum_required(VERSION 3.16)
project(gfg VERSION 0.2.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(googletest-release-1.12.1)
enable_testing()

add_executable(gfg main.cpp)

target_include_directories(gfg PRIVATE googletest-release-1.12.1/googletest/include)

target_include_directories(gfg PRIVATE headers headers_2)

target_link_libraries(gfg PRIVATE gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
