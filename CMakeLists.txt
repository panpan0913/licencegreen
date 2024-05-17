cmake_minimum_required(VERSION 3.12)
project(licencegreen)

set(CMAKE_CXX_STANDARD 14)

# 添加源文件
#add_executable(licencegreen main.cpp Decode.cpp Encode.cpp)
add_library(licencegreen SHARED main.cpp Decode.cpp Encode.cpp)
# 添加其他依赖库
#target_link_libraries(licencegreen)