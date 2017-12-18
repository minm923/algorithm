CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(mysvr CXX)

# 依赖库
include("${PROJECT_SOURCE_DIR}/../../dep/CMakedep.txt")

# 公共源码
SET(GAME_COMM_PATH "${PROJECT_SOURCE_DIR}/../base")

INCLUDE_DIRECTORIES(${GAME_COMM_PATH}/xxtea)

#协议文件目录
SET(GAME_PROTOCOL_PATH "${PROJECT_SOURCE_DIR}/../../protocol")

INCLUDE_DIRECTORIES(${GAME_PROTOCOL_PATH}/cpp_src)

# 当前工程头文件搜索目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/framework)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/model)

SET(NAME mysvr)

# 生成的二进制文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../run/${NAME}/bin)

set(CMAKE_CXX_COMPILER "g++")
IF (${CMAKE_BUILD_TYPE} MATCHES DEBUG)

    SET(CMAKE_CXX_FLAGS "-g -D_DEBUG  -Wno-old-style-cast -Wall -Wextra -ffast-math -m64 -Wno-reorder -Wno-invalid-offsetof -Wno-array-bounds -finput-charset=UTF-8  -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-missing-field-initializers -Wno-sign-compare -pthread -lz")

    #SET(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wwrite-strings -march=native -rdynamic")

ELSE ()
    SET(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra -ffast-math -m64 -Wno-reorder -Wno-invalid-offsetof -Wno-array-bounds -finput-charset=UTF-8  -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-missing-field-initializers -Wno-sign-compare -pthread")
ENDIF ()

# 链接选项
SET(CMAKE_EXE_LINKER_FLAGS "-rdynamic -Wl,-Bstatic -Wl,-Bdynamic -lstdc++ -lpthread -ldl -lrt")

# 源文件搜索
FILE(GLOB_RECURSE SourceFiles 
        "${PROJECT_SOURCE_DIR}/*.cpp" 
        "${PROJECT_SOURCE_DIR}/*.cc")


#查找boost库
#FIND_PACKAGE(Boost REQUIRED)
#INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

#FIND_PACKAGE(Protobuf REQUIRED)
#INCLUDE_DIRECTORIES(${Protobuf_INCLUDE_DIRS})

#生成可执行文件
ADD_EXECUTABLE(${NAME} ${SourceFiles})

TARGET_LINK_LIBRARIES(${NAME} ${DEP_LIB_LISTS})

