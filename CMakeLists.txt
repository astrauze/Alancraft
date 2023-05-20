cmake_minimum_required(VERSION 3.20)

project(Alancraft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file(Config.h.in ${CMAKE_BINARY_DIR}/Config.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(FASTNOISE2_NOISETOOL OFF CACHE BOOL "" FORCE)
set(FASTNOISE2_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/imgui)
add_subdirectory(external/spdlog)
add_subdirectory(external/glm)
add_subdirectory(external/FastNoise2)
add_subdirectory(external/stb)

add_executable(${PROJECT_NAME}
	source/main.cpp
	source/Alancraft.cpp
	source/Application/Application.cpp
)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE glfw
	PRIVATE glad
	PRIVATE imgui
	PRIVATE spdlog
	PRIVATE glm
	PRIVATE FastNoise2
	PRIVATE stb
)