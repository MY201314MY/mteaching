#include <stdio.h>
#include "sqlite3.h"

static int callback(void *data, int argc, char *argv[], char *azColName[]){
    int i=0;
    
    for(;i<argc;i++){
        printf("%s = %s\r\n", azColName[i], argv[i]?argv[i]:"NULL");
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[])
{
    sqlite3 *db;
    int rc;

    printf("- - - - SQLite - - - -\r\n");

    rc = sqlite3_open("/home/root/mteaching.db", &db);
    if(rc){
        printf("Can't open database: %s\r\n", sqlite3_errmsg(db));
        return 1;
    }else{
        printf("Open SQLite successfully.\r\n");
    }

    char *sql = "SELECT * FROM storage";
    char *zErrMsg;

    rc = sqlite3_exec(db, sql, callback, (void*)NULL, &zErrMsg);
    if(rc != SQLITE_OK){
        printf("SQL Error!\r\n", zErrMsg);
    }else{
        printf("Operating done successfully.\r\n");
    }

    sqlite3_close(db);

    return 0;
}