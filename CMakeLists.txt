cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(zelda)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(game/deps/fmt)
add_subdirectory(game/deps/raylib)
add_subdirectory(game/deps/raylib-cpp)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif()

file(GLOB RESOURCES ${PROJECT_SOURCE_DIR}/game/res/*)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/game/src/*.cpp)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/game/include/*.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/game/include
)
target_link_libraries(${PROJECT_NAME} fmt raylib raylib_cpp)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/game/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
    DEPENDS ${RESOURCES})