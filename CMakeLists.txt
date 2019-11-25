cmake_minimum_required(VERSION 3.0)
project(LibParse VERSION 0.1 DESCRIPTION "LibParse description")

include_directories(lib/inc/LoadFile lib/inc/File)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

add_library(LibParse SHARED
	lib/src/LoadFile/LoadFile.cpp
	lib/src/File/File.cpp
)
