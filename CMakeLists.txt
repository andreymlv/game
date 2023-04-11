cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(zelda)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(deps/fmt)
add_subdirectory(deps/raylib)
add_subdirectory(lib)

file(GLOB RESOURCES ${PROJECT_SOURCE_DIR}/res/*)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/game/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} lib fmt raylib)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
    DEPENDS ${RESOURCES})