cmake_minimum_required(VERSION 3.25)

project(RageMenu VERSION 1.0.0)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    GD_VERSION 2.206
    
    SOURCES
        src/main.cpp
        
    RESOURCES
        logo.png
        resources/rage-menu.png
)
