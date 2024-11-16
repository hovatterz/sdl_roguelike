cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME roguelike)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
message(STATUS "test: ${WORKING_DIRECTORY} ${CMAKE_SOURCE_DIR} ${CMAKE_MODULE_PATH}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(${PROJECT_NAME})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/sds)

message(STATUS "test: ${CMAKE_SOURCE_DIR} ${CMAKE_MODULE_PATH}")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.c
                               src/dungeon.c
                               src/slist.c
                               src/tile.c)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}
                                      ${SDL2_IMAGE_LIBRARIES})

enable_testing()

add_executable(slist_test test/slist_test.c)
target_link_libraries(slist_test)

add_test(NAME slist_test_create COMMAND slist_test 0)
add_test(NAME slist_test_add COMMAND slist_test 1)
add_test(NAME slist_test_delete COMMAND slist_test 2)
add_test(NAME slist_test_count COMMAND slist_test 3)
