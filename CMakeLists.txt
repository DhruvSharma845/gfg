cmake_minimum_required(VERSION 3.0.0)
project(gfg VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(googletest-release-1.12.1)
enable_testing()
include_directories(googletest-release-1.12.1/googletest/include)

include_directories(headers)

add_executable(gfg main.cpp tests.cpp)
target_link_libraries(gfg PRIVATE gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
