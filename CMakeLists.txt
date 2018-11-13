cmake_minimum_required(VERSION 3.10)
project(TAP)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES
        "TAP/src/*.h"
        "TAP/src/*cpp"
    )

#link_libraries(ws2_32 wsock32)

add_executable(TAP ${SOURCE_FILES})