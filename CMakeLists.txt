cmake_minimum_required(VERSION 3.0)
project(Nyx VERSION 0.1 DESCRIPTION "Nyx description")

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_library(Nyx SHARED

    lib/FileManager/src/File.cpp
    lib/FileManager/src/Loader.cpp
    lib/FileManager/src/Parser.cpp

    lib/FormatParser/src/JSONParser.cpp
    lib/FormatParser/src/XMLParser.cpp

    )

target_include_directories(Nyx

    PUBLIC lib/FileManager/inc/
    PUBLIC lib/FormatParser/inc/

    )
