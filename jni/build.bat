rmdir /s /q build
mkdir build
cd src/jni
call header.bat
cd ..\..\build
cmake ..
cmake --build .
cd ..
copy build\src\jni\Debug\aotlex_jni.dll ..