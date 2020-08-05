cmake_minimum_required(VERSION 3.0)

project (Tracer)

file(GLOB_RECURSE Tracer_SOURCES "src/*.cpp")
file(GLOB_RECURSE Tracer_HEADERS "src/*.h")

set (Tracer_INCLUDE_DIRS "")
foreach (_headerFile ${Tracer_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Tracer_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Tracer_INCLUDE_DIRS)

add_executable (TracerExe ${Tracer_SOURCES})
target_include_directories(TracerExe PRIVATE ${Tracer_INCLUDE_DIRS})
