cmake_minimum_required(VERSION 3.25)

project(RageMenu)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    GD_VERSION 2.204
    SOURCES src/main.cpp
)

target_resources(${PROJECT_NAME}
    logo.png
    resources/rage-menu.png
)
