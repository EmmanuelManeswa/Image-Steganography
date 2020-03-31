cmake_minimum_required(VERSION 3.16.4)

project(image-steganography)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)
include_directories(third_party/sha256/include)

file(GLOB SOURCES "src/*.cpp" "third-party/sha256/src/*.cpp")

add_executable(execute ${SOURCES})

target_link_libraries(execute ${OpenCV_LIBS})