cmake_minimum_required(VERSION 3.5)
project(PeparationLearning)

set(CMAKE_CXX_STANDARD 14)

# CMAKE MODULE SETUP.f
#####################
# Paths that are searched when `include(...)` is called.
# 添加include 命令所搜索的路径
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/3rdparty/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/3rdparty/libprocess/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/3rdparty/stout/cmake)
list(
        APPEND
        CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/3rdparty/libprocess/cmake/macros)

# Macros.
# ${CMAKE_SOURCE_DIR}/cmake
include(Common)
# ${CMAKE_SOURCE_DIR}/3rdparty/libprocess/cmake/macros
include(External)
# ${CMAKE_SOURCE_DIR}/3rdparty/libprocess/cmake/macros
include(PatchCommand)
# ${CMAKE_SOURCE_DIR}/3rdparty/cmake
include(Versions)
# ${CMAKE_SOURCE_DIR}/3rdparty/cmake
include(cotire)

# Configuration.
# ${CMAKE_SOURCE_DIR}/cmake
include(StartConfigure)
# ${CMAKE_SOURCE_DIR}/cmake
include(CompilationConfigure)
# ${CMAKE_SOURCE_DIR}/3rdparty/libprocess/cmake
include(ProcessConfigure)

# SUBDIRECTORIES.
#################
add_subdirectory(3rdparty)

add_subdirectory(src)
add_subdirectory(knowledge)
