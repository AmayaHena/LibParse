cmake_minimum_required(VERSION 3.0)
project(LibParse VERSION 0.1 DESCRIPTION "LibParse description")

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

add_library(LibParse SHARED
    lib/fileManager/src/LoadFile.cpp
    lib/fileManager/src/File.cpp
    lib/fileManager/src/ParserFile.cpp
    lib/typeConv/src/basicConv.cpp
    lib/formatParser/src/jsonParser.cpp
    lib/formatParser/src/xmlParser.cpp
)
target_include_directories(LibParse
    PUBLIC lib/fileManager/inc/
    PUBLIC lib/typeConv/inc/
    PUBLIC lib/formatParser/inc/
    PUBLIC lib/typeConv/inc
)
