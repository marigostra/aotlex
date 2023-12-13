
include_directories(${JNI_INCLUDE_DIRS})

add_library(aotlex_jni SHARED jni.cpp)

target_link_libraries(aotlex_jni LemmatizerLib)

