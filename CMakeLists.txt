cmake_minimum_required(VERSION 3.31)

set(PROJECT_NAME c_refresh)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(${PROJECT_NAME})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/sds)

# include_directories(${INCLUDE_DIRS})
# file(GLOB_RECURSE LIB_SRC_FILES include/*/*.c)
# add_library(${PROJECT_NAME}_LIB STATIC ${LIB_SRC_FILES})
# install(TARGETS ${PROJECT_NAME}_LIB DESTINATION lib)

# Install library headers
# file(GLOB_RECURSE LIB_INC_FILES include/*/*.h)
# install(FILES ${LIB_INC_FILES} DESTINATION include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES src/main.c)
add_executable(c_refresh ${SOURCE_FILES})
target_link_libraries(c_refresh ${SDL2_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_LIB)
