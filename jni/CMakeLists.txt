
cmake_minimum_required(VERSION 3.5)
project(aot)

find_package(JNI)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

add_compile_options(--std=c++11)
add_compile_options(-fpic)

add_subdirectory (src)
