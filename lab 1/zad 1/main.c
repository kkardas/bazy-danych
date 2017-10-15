#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>

struct Rec {
  int id;
  char name[20];
  char desc[90];
};

int main()
{
    clock_t time1, time2, time3;
    int rc;
    int rc2;
    int max = 1000000;
    int search_id = 999999;
    sqlite3 *db;
    char loc[] = ":memory:";
    char *err_msg = 0;
    struct rusage memory;

    char* name_temp = "Bazy danych";
    char* name_desc = "Lab 1";

    char *sql = "INSERT INTO Rece VALUES (?1,?2,?3)";

    struct Rec* rece = malloc(sizeof(struct Rec)*max);

    if(rece==NULL) {
        fprintf(stderr,"Mem alloc error\n");
        return 1;
    }

    time1 = clock();
    for(int i=0; i< max; ++i)
    {
        rece[i].id = i;
        strncpy(rece[i].name, name_temp, 20);
        strncpy(rece[i].desc, name_desc, 90);
    }

    time2 = clock();

    for(int i=0; i<max; ++i)
    {
        if(rece[i].id == search_id)
        {
            printf("Znalezione");
        }
    }

    time3 = clock();

    getrusage(RUSAGE_SELF, &memory);

    printf("Wypelnianie danych zajelo: %f\n", ((float)time2-(float)time1)/CLOCKS_PER_SEC);
    printf("Przeszukiwanie danych zajelo: %f\n", ((float)time3-(float)time2)/CLOCKS_PER_SEC);
    printf("Max memory usage[kB]: %ld\n", memory.ru_maxrss);
    free(rece);
}
