#CMake minimum version number requirements.
cmake_minimum_required(VERSION 3.8)

#Project information.
project("EarlyEducationMachine")

# About version cycles.
# alpha: �Ѿ�����˹��ܣ�������ȱ�ݲ�����ȷ����������ڲ�׶�
# beta: ������ⷢ���汾�������������ܣ��Լ�һЩ��Ӱ��ʹ�õ� bug�����빫��׶�
# release: ��ʽ��
#
# About version numbers
# MAJOR: �����ع�
# MINOR: ��ɾ�Ĺ�����
# PATCH: debug
set(VERSION_MAJOR 0)                                        # ��Ŀ�汾
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(VERSION_EXTRA "alpha")
set(VERSION_DATA "20230320")

configure_file (                                            # ����һ������ͷ�ļ����������ݰ汾�ţ�
  "${PROJECT_SOURCE_DIR}/cconfig.hpp.in"                    #     ʹԴ��Ҳ����ʹ�� CMake ����
  "${PROJECT_BINARY_DIR}/cconfig.hpp"                       # ���У�_SOURCE_ Ϊ���̸�Ŀ¼
)                                                           #     _BINARY_ Ϊ build �ķ���Ŀ¼

string(CONCAT TARGET "${PROJECT_NAME}"                      # �����ִ���ļ�����
					 "_v${VERSION_MAJOR}"                   # ���� "monitor_v0.0.1.20230112_alpha"��
					 ".${VERSION_MINOR}"
					 ".${VERSION_PATCH}"
					 ".${VERSION_DATA}"
					 "_${VERSION_EXTRA}")

#Display version at compily time.
message(STATUS "[Version]: ${TARGET}")                      # ����ʱ��ʾ�汾��Ϣ

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
