#include <stdio.h>
#include <stdlib.h>

struct cricketers
{
  char cricketer_name[20];
  int cricketer_age;
  int cricketer_testmt;
  int cricketer_avrun;
};
int main()
{
  int i, n, j, temp;
  struct cricketers a[20];
  printf("Enter the number of record of the cricketers-\n");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Enter the Cricketers name:-");
    scanf("%s", &a[i].cricketer_name);
    printf("Enter the Cricketers age:-");
    scanf("%d", &a[i].cricketer_age);
    printf("Enter the Cricketers test matches:-");
    scanf("%d", &a[i].cricketer_testmt);
    printf("Enter the Cricketers average run:-");
    scanf("%d", &a[i].cricketer_avrun);
  }
  printf("Record of Cricketers-\n\n");
  for (i = 0; i < n; i++)
  {
    printf("Cricketers name:-%s\n", a[i].cricketer_name);
    printf("Cricketers age:-%d\n", a[i].cricketer_age);
    printf("Cricketers test matches:-%d\n", a[i].cricketer_testmt);
    printf("Cricketers average run:-%d\n", a[i].cricketer_avrun);
  }
  printf(" Cricketers ascending order of average runs:-\n");
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (a[i].cricketer_avrun > a[j].cricketer_avrun)
      {
        temp = a[i].cricketer_avrun;
        a[i].cricketer_avrun = a[j].cricketer_avrun;
        a[j].cricketer_avrun = temp;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    printf(" %d\n", a[i].cricketer_avrun);
  }

  return 0;
}
