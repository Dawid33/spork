cmake_minimum_required(VERSION 3.16)
project(spork)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(ExternalProject)
# don't repeatedly build ExternalProjects.
set_directory_properties(PROPERTIES EP_UPDATE_DISCONNECTED true)
set(DEPS ${PROJECT_BINARY_DIR}/deps)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

IF (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt5\\5.15.2\\msvc2019_64\\lib\\cmake")
ELSE()
    find_package(PkgConfig REQUIRED)
ENDIF()

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Xml)

add_executable(spork images.qrc)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/game)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui/menu_bar)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui/control_panel)

target_include_directories(spork PRIVATE)

message("Linking with existing QT5 libraries...")
target_link_libraries(spork
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Xml)

