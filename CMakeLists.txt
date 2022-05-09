cmake_minimum_required(VERSION 3.14)

project(Algorithms LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(INCLUDE_DIRECTORIES
    $CMAKE_CURRENT_DIR/BreadFirstSearch.hpp
    $CMAKE_CURRENT_DIR/DepthFirstSearch.hpp
    )
add_executable(Algorithms
  main.cpp
)
target_link_libraries(Algorithms Qt${QT_VERSION_MAJOR}::Core)
