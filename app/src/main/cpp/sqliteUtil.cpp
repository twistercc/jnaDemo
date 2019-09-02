#include "stdio.h"
#include <iostream>
#include <stdlib.h>
#include "sqlite3.h"

using namespace std;
extern "C"
int create_alarm (){
    sqlite3* db;
    int res = sqlite3_open("/sdcard/test.db", &db);
    if (res != SQLITE_OK) {
        cout << "Open database fail: " << sqlite3_errmsg(db);
    } else {
        cout << "Open database success:" << endl;
    }
    const char* sql = "CREATE TABLE weather_alarm(" \
            "id TEXT PRIMARY KEY NOT NULL, " \
            "category TEXT, " \
            "city TEXT," \
            "code INT," \
            "content TEXT," \
            "createTime TEXT," \
            "date TEXT," \
            "district TEXT," \
            "level INT," \
            "levelName TEXT," \
            "province TEXT," \
            "publish TEXT," \
            "source TEXT," \
            "typeId INT," \
            "typeName TEXT," \
            "updateTime TEXT" \
            ");";
    char* errmsg = nullptr;
    res = sqlite3_exec(db, sql, 0, 0, &errmsg);
    if (SQLITE_OK == res) {
        cout << "create alarm table succeed.\n" << endl;
    } else {
        cout << "create alarm error: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    sqlite3_close(db);
    return 0;
}


extern "C"
int insert_alarm (){
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("/sdcard/test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    const char* sql = "INSERT INTO weather_alarm (id, category, city, code, content, createTime, date, district, level, levelName, province, publish, source, typeId, typeName, updateTime) " \
            " VALUES ('20190816_0001_00', 'adminarea', '北京', 1, '市气象台2019年8月15日21时40分发布大风蓝色预警信号：预计，当前至16日20时，北京地区将有4、5级偏北风，阵风可达8级左右，请注意防范。（预警信息来源：国家预警信息发布中心）', '2019-08-16','2019-08-16', '北京', 1, '蓝色', '北京', '2019-08-16', 'weatherhefeng', 0, '大风', '2019-08-16 19:10:24'); ";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "insert_alarm error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "insert_alarm successfully\n");
    }
    sqlite3_close(db);
    return 0;
}


extern "C"
int updateById_alarm(char* id, char* field, char* value){
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("/sdcard/test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    const char* sql = "INSERT INTO weather_alarm (id, category, city, code, content, createTime, date, district, level, levelName, province, publish, source, typeId, typeName, updateTime) " \
            " VALUES ('20190816_0001_00', 'adminarea', '北京', 1, '市气象台2019年8月15日21时40分发布大风蓝色预警信号：预计，当前至16日20时，北京地区将有4、5级偏北风，阵风可达8级左右，请注意防范。（预警信息来源：国家预警信息发布中心）', '2019-08-16','2019-08-16', '北京', 1, '蓝色', '北京', '2019-08-16', 'weatherhefeng', 0, '大风', '2019-08-16 19:10:24'); ";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "insert_alarm error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "insert_alarm successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

extern "C"
int select_callback(void*para , int nCount, char** pValue, char** pName) {
    /*****************************************************************************
          sqlite 每查到一条记录，就调用一次这个回调
          para是你在 sqlite3_exec 里传入的 void * 参数, 通过para参数，你可以传入一些特殊的指针（比如类指  针、结构指针），然后在这里面强制转换成对应的类型（这里面是void*类型，必须强制转换成你的类型才可用）。然后操作这些数据
          nCount是这一条(行)记录有多少个字段 (即这条记录有多少列)
          char ** pValue 是个关键值，查出来的数据都保存在这里，它实际上是个1维数组（不要以为是2维数组），每一个元素都是一个 char* 值，是一个字段内容（用字符串来表示，以/0结尾）
          char ** pName 跟pValue是对应的，表示这个字段的字段名称, 也是个1维数组
     *****************************************************************************/
    string s;
    for(int i=0;i<nCount;i++){
        s+=pName[i];
        s+=":";
        s+=pValue[i];
        s+="\n";
    }
    cout<<s<<endl;
    return 0;
}

extern "C"
int select_alarm(){
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("/sdcard/test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    const char* sql = "INSERT INTO weather_alarm (id, category, city, code, content, createTime, date, district, level, levelName, province, publish, source, typeId, typeName, updateTime) " \
            " VALUES ('20190816_0001_00', 'adminarea', '北京', 1, '市气象台2019年8月15日21时40分发布大风蓝色预警信号：预计，当前至16日20时，北京地区将有4、5级偏北风，阵风可达8级左右，请注意防范。（预警信息来源：国家预警信息发布中心）', '2019-08-16','2019-08-16', '北京', 1, '蓝色', '北京', '2019-08-16', 'weatherhefeng', 0, '大风', '2019-08-16 19:10:24'); ";
    /* Execute SQL statement */

    int sqlite3_exec(sqlite3*, const char *sql,sqlite3_callback, void *,char **errmsg);
//    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "insert_alarm error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "insert_alarm successfully\n");
    }
    sqlite3_close(db);
    return 0;
}