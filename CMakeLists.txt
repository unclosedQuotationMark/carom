cmake_minimum_required(VERSION 3.25)

project(carom VERSION 0.1.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(carom
    src/main.cpp
    src/controls/app.cpp
    src/graphics/simulation_view.cpp
    src/controls/camera_controller.cpp
    src/physics/engine.cpp
)

target_include_directories(carom PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(carom PRIVATE
    SFML::System
    SFML::Graphics
    SFML::Window
)
