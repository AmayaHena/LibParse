cmake_minimum_required(VERSION 3.9)
project(LibParse VERSION 0.1 DESCRIPTION "LibParse description")

add_library(LibParse SHARED
	src/LoadFile/LoadFile.cpp
	src/File/File.cpp
)

target_include_directories(LibParse PUBLIC inc
	inc/LoadFile/LoadFile.hpp
	inc/File/File.hpp
)
