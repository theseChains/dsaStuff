cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello VERSION 1.0)

file (GLOB_RECURSE dsa_SOURCES CONFIGURE_DEPENDS "dsaStudy/*.cpp")
file (GLOB_RECURSE dsa_HEADERS CONFIGURE_DEPENDS "dsaStudy/*.h")

set (dsa_INCLUDE_DIRS "")
foreach (_headerFile ${dsa_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND dsa_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES dsa_INCLUDE_DIRS)

add_executable(app ${dsa_SOURCES})
target_include_directories(app PRIVATE ${dsa_INCLUDE_DIRS})
