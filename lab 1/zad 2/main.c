#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <time.h>
#include <string.h>

struct Rec {
  int id;
  char name[8];
  char desc[15];
};

struct Rec2 {
  int id;
  char name[18];
  char desc[80];
};

int main()
{
    clock_t time1, time2, time3;
    int rc;
    int rc2;
    int max = 1000000;
    sqlite3 *db;
    char loc[] = ":memory:";
    char *err_msg = 0;

    char *sql = "INSERT INTO Rece VALUES (?1,?2,?3)";

    char c1[8] = "aaaaa";
    char c2[15] = "aaaaa";

    sqlite3_stmt *stmt;

    rc=sqlite3_open(loc, &db);

    rc=sqlite3_exec(db, "CREATE TABLE Rece (id integer PRIMARY KEY, name varchar(8), desc varchar(15));", NULL, NULL, NULL);

    if (rc)
    {
      fprintf(stderr, "Database create table error: %s\n", sqlite3_errmsg(db));
      return 1;
    }

    rc2=sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

    if (rc2)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_exec(db, "BEGIN", NULL, NULL, NULL);
    time1 = clock();
    for (int i = 0; i < max; ++i)
    {
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, c1, 9, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c2, 16, SQLITE_STATIC);

        rc=sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
          fprintf(stderr,"Database insert error\n");
        }
        sqlite3_reset(stmt);
    }
    sqlite3_exec(db, "END", NULL, NULL, NULL );

    time2 = clock();
    printf("wepchniecie do pamieci, %f\n", ((float)time2-(float)time1)/CLOCKS_PER_SEC);

    sqlite3_exec(db, "SELECT * Rece WHERE id === 999999", 0, 0, &err_msg);

    time3 = clock();
    printf("wyszukanie w pamieci, %f\n", ((float)time3-(float)time2)/CLOCKS_PER_SEC);

    sqlite3_close(db);



    sqlite3 *db2;

    char loc2[] = "test.db";

    rc=sqlite3_open(loc2, &db2);

    rc=sqlite3_exec(db2, "CREATE TABLE Rece (id integer PRIMARY KEY, name varchar(8), desc varchar(15));", NULL, NULL, NULL);

    if (rc)
    {
      fprintf(stderr, "Database create table error: %s\n", sqlite3_errmsg(db2));
      return 1;
    }

    rc2=sqlite3_prepare_v2(db2, sql, strlen(sql), &stmt, NULL);

    if (rc2)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db2));
        return 1;
    }

    sqlite3_exec(db2, "BEGIN", NULL, NULL, NULL);
    time1 = clock();
    for (int i = 0; i < max; ++i)
    {
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, c1, 9, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c2, 16, SQLITE_STATIC);

        rc=sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
          fprintf(stderr,"Database insert error\n");
        }
        sqlite3_reset(stmt);
    }
    sqlite3_exec(db2, "END", NULL, NULL, NULL );

    time2 = clock();
    printf("wepchniecie do pamieci, %f\n", ((float)time2-(float)time1)/CLOCKS_PER_SEC);

    sqlite3_exec(db2, "SELECT * Rece WHERE id === 999999", 0, 0, &err_msg);

    time3 = clock();
    printf("wyszukanie w pamieci, %f\n", ((float)time3-(float)time2)/CLOCKS_PER_SEC);

    sqlite3_close(db2);




    sqlite3 *db3;

    rc=sqlite3_open(loc, &db3);

    rc=sqlite3_exec(db3, "CREATE TABLE Rece (id integer PRIMARY KEY, name varchar(18), desc varchar(80));", NULL, NULL, NULL);

    if (rc)
    {
      fprintf(stderr, "Database create table error: %s\n", sqlite3_errmsg(db3));
      return 1;
    }

    rc2=sqlite3_prepare_v2(db3, sql, strlen(sql), &stmt, NULL);

    if (rc2)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db3));
        return 1;
    }

    sqlite3_exec(db3, "BEGIN", NULL, NULL, NULL);
    time1 = clock();
    for (int i = 0; i < max; ++i)
    {
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, c1, 16, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c2, 81, SQLITE_STATIC);

        rc=sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
          fprintf(stderr,"Database insert error\n");
        }
        sqlite3_reset(stmt);
    }
    sqlite3_exec(db3, "END", NULL, NULL, NULL );

    time2 = clock();
    printf("wepchniecie do pamieci, %f\n", ((float)time2-(float)time1)/CLOCKS_PER_SEC);

    sqlite3_exec(db3, "SELECT * Rece WHERE id === 999999", 0, 0, &err_msg);

    time3 = clock();
    printf("wyszukanie w pamieci, %f\n", ((float)time3-(float)time2)/CLOCKS_PER_SEC);

    sqlite3_close(db3);



    sqlite3 *db4;

    char loc3[] = "test2.db";

    rc=sqlite3_open(loc3, &db4);

    rc=sqlite3_exec(db4, "CREATE TABLE Rece (id integer PRIMARY KEY, name varchar(18), desc varchar(80));", NULL, NULL, NULL);

    if (rc)
    {
      fprintf(stderr, "Database create table error: %s\n", sqlite3_errmsg(db4));
      return 1;
    }

    rc2=sqlite3_prepare_v2(db4, sql, strlen(sql), &stmt, NULL);

    if (rc2)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db4));
        return 1;
    }

    sqlite3_exec(db4, "BEGIN", NULL, NULL, NULL);
    time1 = clock();
    for (int i = 0; i < max; ++i)
    {
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, c1, 16, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c2, 81, SQLITE_STATIC);

        rc=sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
          fprintf(stderr,"Database insert error\n");
        }
        sqlite3_reset(stmt);
    }
    sqlite3_exec(db4, "END", NULL, NULL, NULL );

    time2 = clock();
    printf("wepchniecie do pamieci, %f\n", ((float)time2-(float)time1)/CLOCKS_PER_SEC);

    sqlite3_exec(db4, "SELECT * Rece WHERE id === 999999", 0, 0, &err_msg);

    time3 = clock();
    printf("wyszukanie w pamieci, %f\n", ((float)time3-(float)time2)/CLOCKS_PER_SEC);

    sqlite3_close(db4);
}
