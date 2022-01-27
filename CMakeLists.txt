cmake_minimum_required(VERSION 3.16)
project(spork)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLM REQUIRED glm)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HPP_FILES ${PROJECT_SOURCE_DIR}/src/include/*.hpp)

add_executable(spork
        ${CPP_FILES}
        ${HPP_FILES})

target_include_directories(spork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/include" ${GLM_INCLUDE_DIRS})
target_link_libraries(spork
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${GLM_LIBRARY_DIRS})
