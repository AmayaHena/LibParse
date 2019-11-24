cmake_minimum_required(VERSION 3.0)

project(LibParse)

set(SRCS
	main.cpp
	src/LibParse.cpp
	src/File/File.cpp
	src/LoadFile/LoadFile.cpp

    )

set(HEADERS
	inc/LibParse.hpp
	inc/File/File.hpp
	inc/LoadFile/LoadFile.hpp

    )

add_executable(LibParse ${SRCS} ${HEADERS})
target_include_directories(LibParse PUBLIC inc)
