cmake_minimum_required (VERSION 2.6)	# CMake 最低版本号要求
project (class_template)	# 项目信息

# include_directories("${PROJECT_BINARY_DIR}")
#message(STATUS "log: PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}")
#message(STATUS "log: CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
aux_source_directory(. DIR_SRCS)	# 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
message(STATUS "log: DIR_SRCS ${DIR_SRCS}")
add_executable(main ${DIR_SRCS})	# 指定生成目标

