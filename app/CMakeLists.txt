
# 设置Cmake的最低版本号
cmake_minimum_required(VERSION 3.6.0)

PROJECT(enlu-allpack)

# 引入opencv 头文件
set(detour_HDRS ./src/main/cpp/include)
INCLUDE_DIRECTORIES(. ${detour_HDRS} )


# 定义自己写的总库
# include the source cpp files
# AUX_SOURCE_DIRECTORY( . SRC_LIST )
AUX_SOURCE_DIRECTORY( ./src/main/cpp SRC_LIST )

# ADD_LIBRARY(sqliteUtil SHARED ${SRC_LIST})
add_library(sqliteUtil SHARED
    ${CMAKE_SOURCE_DIR}/src/main/cpp/sqliteUtil.cpp
    ${CMAKE_SOURCE_DIR}/src/main/cpp/sqlite3.c
    )
# add_library(sqlite3 SHARED ${CMAKE_SOURCE_DIR}/src/main/cpp/sqlite3.c)

# set_target_properties(sqlite3 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libsqlite3.so )

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a" ) #设置库的后缀

# 如果需要其他NDK原生库的话，可自行在此处添加
find_library(log-lib log)


# 将第三方库以及自己写的库关联到需要用的NDK原生库中
target_link_libraries( sqliteUtil ${log-lib} -ldl )