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

find_package(PkgConfig REQUIRED)
pkg_search_module(GLM REQUIRED glm)
find_package(Qt5 COMPONENTS
       Core
       Gui
       Widgets
       QUIET)

add_executable(spork images.qrc)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/game)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui/menu_bar)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/ui/control_panel)

target_include_directories(spork PRIVATE ${GLM_INCLUDE_DIRS})

IF(Qt5_FOUND)
    message("Linking with existing QT5 libraries...")
    target_link_libraries(spork
            Qt5::Core
            Qt5::Gui
            Qt5::Widgets
            ${GLM_LIBRARY_DIRS})
ELSE()
    message("QT5 not found, building from source")
    ExternalProject_Add(qt5_build
            GIT_REPOSITORY  "https://github.com/qt/qt5"
            GIT_TAG         v6.2.3
            CONFIGURE_COMMAND "${PROJECT_BINARY_DIR}/qt5_build-prefix/src/qt5_build/configure" "--prefix=$PWD/qtbase")
    add_dependencies(spork qt5_build)
    # add_library(qt5 SHARED IMPORTED)
    # set_property(TARGET qt5 PROPERTY IMPORTED_LOCATION ${DEPS)
ENDIF()


