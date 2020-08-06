cmake_minimum_required(VERSION 3.0)

# Name of project:
project (Tracer)

# Specify std library
ADD_DEFINITIONS(-std=c++11)

file(GLOB_RECURSE Tracer_SOURCES "src/*.cpp")
file(GLOB_RECURSE Tracer_HEADERS "src/*.h")

# Add all folders containing header files to Include Path
set (Tracer_INCLUDE_DIRS "")
foreach (_headerFile ${Tracer_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Tracer_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Tracer_INCLUDE_DIRS)

add_executable (Tracer ${Tracer_SOURCES})

target_include_directories(Tracer PRIVATE ${Tracer_INCLUDE_DIRS})
