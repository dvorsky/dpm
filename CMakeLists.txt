cmake_minimum_required(VERSION 3.14)
project(dpm)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/fmt)

add_executable(dpm src/main.cpp src/manifest/Manifest.h src/manifest/Manifest.cpp)

target_link_libraries(dpm PRIVATE fmt stdc++fs)
