CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(partysvr CXX)

include("${PROJECT_SOURCE_DIR}/../../dep/CMakedep.txt") # 依赖库

#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platut)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platutil)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platshm)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/uidcreater)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platnetlog)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platalgorithm/hash)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platalgorithm/skiplist)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platalgorithm/rand)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/torm)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/xxtea)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/memory_pool)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/dirty)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/curl)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/redis)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/luaseri)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/monitor)

#协议文件目录
SET(GAME_PROTOCOL_PATH "${PROJECT_SOURCE_DIR}/../../protocol")

INCLUDE_DIRECTORIES(${GAME_PROTOCOL_PATH}/cpp_src)
INCLUDE_DIRECTORIES(${GAME_PROTOCOL_PATH}/comm_inc)

SET(NAME twbase)

IF (${CMAKE_BUILD_TYPE} MATCHES DEBUG)
    SET(CMAKE_CXX_FLAGS "-g -D_DEBUG -DDEBUG -Wall -Wextra -ffast-math -m64 -Wno-reorder -Wno-invalid-offsetof -Wno-array-bounds -finput-charset=UTF-8  -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-missing-field-initializers -Wno-sign-compare")
ELSE ()
    SET(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra -ffast-math -m64 -Wno-reorder -Wno-invalid-offsetof -Wno-array-bounds -finput-charset=UTF-8  -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-missing-field-initializers -Wno-sign-compare")
ENDIF ()

# 链接选项
SET(CMAKE_EXE_LINKER_FLAGS "-rdynamic -Wl,-Bstatic -Wl,-Bdynamic -lstdc++ -lpthread -ldl -lz -lrt")

# 源文件搜索
FILE(GLOB_RECURSE SourceFiles
#        "${PROJECT_SOURCE_DIR}/platut/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platform/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platutil/*.cpp"
#        "${PROJECT_SOURCE_DIR}/torm/*.cpp"
#        "${PROJECT_SOURCE_DIR}/dirty/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platshm/*.cpp"
#        "${PROJECT_SOURCE_DIR}/uidcreater/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platnetlog/*.cpp"
        "${PROJECT_SOURCE_DIR}/xxtea/*.cpp"
#        "${PROJECT_SOURCE_DIR}/memory_pool/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platalgorithm/hash/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platalgorithm/skiplist/*.cpp"
#        "${PROJECT_SOURCE_DIR}/curl/*.cpp"
#        "${PROJECT_SOURCE_DIR}/redis/*.cpp"
#        "${PROJECT_SOURCE_DIR}/luaseri/*.cpp"
#        "${PROJECT_SOURCE_DIR}/platalgorithm/rand/*.cpp"
#        "${PROJECT_SOURCE_DIR}/monitor/*.cpp")
    )

#生成可执行文件
ADD_LIBRARY(${NAME} STATIC ${SourceFiles})

TARGET_LINK_LIBRARIES(${NAME} ${DEP_LIB_LISTS})

