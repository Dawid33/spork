cmake_minimum_required(VERSION 3.16)
project(spork)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#include(ExternalProject)
#set_directory_properties(PROPERTIES EP_UPDATE_DISCONNECTED true)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        QUIET)

include_directories(src/include)

add_executable(spork
        src/main.cpp
        src/window.cpp
        src/world_canvas.cpp
        src/status_console.cpp
        )

target_link_libraries(spork
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        OpenGL::GL 
        OpenGL::GLU
        GLUT::GLUT
        )