cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(stb STATIC
	stb_image.cpp
	stb_image_write.cpp
)

target_include_directories(stb
	PUBLIC .
)