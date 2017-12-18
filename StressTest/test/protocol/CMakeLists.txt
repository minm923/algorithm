CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(partysvr CXX)

SET(THIRD_LIB_PATH "${PROJECT_SOURCE_DIR}/../dep")
INCLUDE_DIRECTORIES(${THIRD_LIB_PATH}/google/include)

#协议文件目录
SET(GAME_PROTOCOL_PATH "${PROJECT_SOURCE_DIR}")
INCLUDE_DIRECTORIES(${GAME_PROTOCOL_PATH}/cpp_src)

SET(NAME twproto)

IF (${CMAKE_BUILD_TYPE} MATCHES DEBUG)
    # DEBUG版本编译选项
    SET(CMAKE_CXX_FLAGS "-g -D_DEBUG -DDEBUG -Wall -Wextra -Werror -Wno-unused-parameter -fno-strict-aliasing -fstack-protector-all -Wno-missing-field-initializers -Wno-sign-compare -Wno-deprecated")
ELSE ()
    # RELEASE版本编译选项
	SET(CMAKE_CXX_FLAGS "-g -O2 -Wall -Wextra -ffast-math -m64 -Wno-reorder -Wno-invalid-offsetof -Wno-array-bounds -finput-charset=UTF-8  -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-missing-field-initializers -Wno-sign-compare")
ENDIF ()

# 链接选项
SET(CMAKE_EXE_LINKER_FLAGS "-rdynamic -Wl,-Bstatic -Wl,-Bdynamic -lstdc++ -lpthread -ldl -lz -lrt")

# 源文件搜索
FILE(GLOB_RECURSE SourceFiles
        "${GAME_PROTOCOL_PATH}/cpp_src/*.cpp"
        "${GAME_PROTOCOL_PATH}/cpp_src/*.cc"
        )

#生成库文件
ADD_LIBRARY(${NAME} STATIC ${SourceFiles})
