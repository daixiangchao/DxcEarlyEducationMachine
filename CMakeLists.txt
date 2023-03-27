#CMake minimum version number requirements.
cmake_minimum_required(VERSION 3.8)

#Project information.
project("EarlyEducationMachine")

# About version cycles.
# alpha: 已经完成了功能，但功能缺陷并不明确，进入测试内测阶段
# beta: 最早对外发布版本，包含完整功能，以及一些不影响使用的 bug，进入公测阶段
# release: 正式版
#
# About version numbers
# MAJOR: 用于重构
# MINOR: 增删改功能项
# PATCH: debug
set(VERSION_MAJOR 0)                                        # 项目版本
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(VERSION_EXTRA "alpha")
set(VERSION_DATA "20230320")

configure_file (                                            # 加入一个配置头文件（用来传递版本号）
  "${PROJECT_SOURCE_DIR}/cconfig.hpp.in"                    #     使源码也可以使用 CMake 变量
  "${PROJECT_BINARY_DIR}/cconfig.hpp"                       # 其中，_SOURCE_ 为工程根目录
)                                                           #     _BINARY_ 为 build 的发生目录

string(CONCAT TARGET "${PROJECT_NAME}"                      # 定义可执行文件名称
					 "_v${VERSION_MAJOR}"                   # （如 "monitor_v0.0.1.20230112_alpha"）
					 ".${VERSION_MINOR}"
					 ".${VERSION_PATCH}"
					 ".${VERSION_DATA}"
					 "_${VERSION_EXTRA}")

#Display version at compily time.
message(STATUS "[Version]: ${TARGET}")                      # 编译时显示版本信息

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    message(STATUS "[Compile mode]: debug")
    add_definitions(-DDEBUG)
    add_compile_options(-g)
else()
    message(STATUS "[Compile mode]: release")
    add_compile_options(-O2)
endif()

#Add common compilation options.
add_compile_options(
    -std=c++11
    -Wall
    -Wextra
)

###################################### Compile submodules #######################################
#add a subdirectory of math
add_subdirectory(Business/PuzzleGame/HuaRongDao)

###################################### Compile root mudule ######################################
#Specify the header file path when linking,equivalent to g++ -I.
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)
#Find source file and put it in the SRCS(variable)
aux_source_directory(. SRCS)
#Identify an executable file
add_executable(${PROJECT_NAME} ${SRCS})
#Link the target file with the executable file generated above
target_link_libraries(
    ${PROJECT_NAME}
    Business_PuzzleGame_HuaRongDao
)

