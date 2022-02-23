cmake_minimum_required(VERSION "3.4")

message("Using CMake version ${CMAKE_VERSION}")

project(process_launcher)

add_subdirectory(lib/yaml-cpp)  # The referencing to other CMake project
include_directories("inc/") # Directory with header files

file(GLOB SRC_FILES src/*.cpp) # Command to create variable for all source files
set(EXEC_NAME "launcher_exec") # Variable for executable name

add_executable(
        ${EXEC_NAME}
        ${SRC_FILES}
)

target_link_libraries(
        ${EXEC_NAME}
        PRIVATE
        yaml-cpp    # The target from yaml-cpp's CMakeLists.txt file
)