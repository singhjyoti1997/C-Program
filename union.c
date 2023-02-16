#include <stdio.h>
union  record
{
    char cricketer_name[20];
    int cricketer_age;
    int cricketer_testmt;
    int cricketer_avrun;
};
struct cricketers
{
    char cricketer_name[20];
    int cricketer_age;
    int cricketer_testmt;
    int cricketer_avrun;
};
int main()
{
    union record record1;
    {
        printf("size of Union- \n");
        printf("%lu\n", sizeof(record1.cricketer_name));
        printf("%lu\n", sizeof(record1.cricketer_age));
        printf("%lu\n", sizeof(record1.cricketer_testmt));
        printf("%lu\n", sizeof(record1.cricketer_avrun));
        printf("%lu\n", sizeof(union record));
    }
    struct cricketers record2;
    {
        printf("size of Structure-\n");
        printf("%lu\n", sizeof(record2.cricketer_name));
        printf("%lu\n", sizeof(record2.cricketer_age));
        printf("%lu\n", sizeof(record2.cricketer_testmt));
        printf("%lu\n", sizeof(record2.cricketer_avrun));
        printf("%lu\n", sizeof(struct cricketers));
    }
}