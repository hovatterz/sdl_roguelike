cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME c_refresh)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(${PROJECT_NAME})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/sds)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

message(STATUS "sdl2_image: ${INTERFACE_INCLUDE_DIRECTORIES}")
message(STATUS "includes: ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}")

set(SOURCE_FILES src/main.c)
add_executable(c_refresh ${SOURCE_FILES})
target_link_libraries(c_refresh PRIVATE SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)
