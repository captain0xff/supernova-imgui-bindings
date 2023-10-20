cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (WIN32)
	link_libraries(mingw32 SDL2main SDL2 SDL2_image supernova imgui)
else ()
	link_libraries(supernova imgui)
endif()

set(SRC_PATH ../src)
set(SOURCES main.cpp ${SRC_PATH}/super_gui.cpp)

add_executable(main ${SOURCES})
