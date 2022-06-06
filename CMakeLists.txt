cmake_minimum_required(VERSION 3.0)

project(ThickAnalysis)

 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(src DIR_SRCS)

set(ThickAnalysis ${DIR_SRCS})

link_libraries("sqlite3")

add_executable(ThickAnalysis_o src/Logic.cpp src/mian.cpp  src/Analysis_1780.cpp  src/readsql.cpp src/Out.cpp src/Count.cpp src/parameter.cpp)