
add_subdirectory (aot)
add_subdirectory (jni)

add_executable (aot-test aot.cpp)

target_link_libraries(aot-test LemmatizerLib)

