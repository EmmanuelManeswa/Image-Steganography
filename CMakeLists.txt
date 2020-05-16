cmake_minimum_required(VERSION 3.16.4)

project(image-steganography)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Qml Quick REQUIRED)

qt5_add_resources(qml_QRC gui/qml.qrc)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)
include_directories(third_party/sha256/include)

file(GLOB SOURCES "src/*.cpp" "third-party/sha256/src/*.cpp")

add_executable(ImSteg ${SOURCES} ${qml_QRC})

target_link_libraries(ImSteg ${OpenCV_LIBS})
target_link_libraries(ImSteg Qt5::Qml Qt5::Quick)
