#include<stdio.h>
int main()
{
    int yr, ref_yr=2001, diff_yr, lp_yr, nm_yr,tday ,day;

printf("Enter the year:-");
scanf("%d",&yr);
diff_yr=yr-ref_yr;
lp_yr=diff_yr/4;
nm_yr=diff_yr-lp_yr;
tday=((nm_yr*365)+(lp_yr*366));
day= tday%7;
if(day==0)
printf("Monday\n");
else if(day==1)
printf("Tuesday\n");
else if(day==2)
printf("Wednesday\n");
else if(day==3)
printf("thursday\n");
else if (day==4)
printf("Friday\n");
else if(day==5)
printf("Saturday\n");
else if(day==6)
printf("sunday");
return 0;
}