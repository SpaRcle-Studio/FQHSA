cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

option(LIB_OPT "Compile shared libraries (ON) or static (OFF)" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GroupSources.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/AutoCollect.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/MakeLibrary.cmake)

option(Fast-Quick-Hull-THREAD_POOL_OPT "thread pool enabled (ON) or disabled (OFF)" ON)
project(Fast-Quick-Hull-Prj)
add_subdirectory(src)