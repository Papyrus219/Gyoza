cmake_minimum_required(VERSION 3.22)
project(Gyoza)

set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON)

FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SRC src/*cpp)
set(SOURCES ${SRC})
add_executable(Gyoza ${SOURCES})
target_link_libraries(Gyoza PRIVATE SFML::Graphics PRIVATE SFML::Audio)
