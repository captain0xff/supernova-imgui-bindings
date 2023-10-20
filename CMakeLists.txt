cmake_minimum_required(VERSION 3.10)

project(super_gui)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT ANDROID)
	set(CMAKE_INSTALL_PREFIX $ENV{PREFIX})
	include(GNUInstallDirs)
endif()

set(SRC_PATH src)
set(HEADERS ${SRC_PATH}/super_gui.h)
set(SOURCES ${SRC_PATH}/super_gui.cpp)

set(LIBS SDL2 supernova imgui)

if (NOT ANDROID)
	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)
	find_package(SDL2_mixer REQUIRED)
	find_package(SDL2_ttf REQUIRED)
	find_package(SDL2_net REQUIRED)
	find_package(supernova REQUIRED)
	find_package(imgui REQUIRED)
endif()

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -Wpedantic)

target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBS})

# Setting which header files should be supplied with the library
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

if (NOT ANDROID)
	install(TARGETS ${PROJECT_NAME}
			EXPORT "${PROJECT_NAME}-config"
			RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
			LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
			ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
			PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/supernova"
			PRIVATE_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/supernova"
			INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/supernova"
	)

	install(EXPORT "${PROJECT_NAME}-config" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

	export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_NAME}-exports.cmake")
endif()
