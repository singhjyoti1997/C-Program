#include<stdio.h>
int main()
{
    float x1,x2,x3,y1,y2,y3;
    printf(" Enter the Value of three points-\n");
    printf("(x1,y1)-");
    scanf("%f %f",&x1,&y1);
    printf("(x2,y2)-");
    scanf("%f %f",&x2,&y2);
    printf("(x3,y3)-");
    scanf("%f %f",&x3,&y3);
    if(((y2-y1)/(x2-x1))==((y3-y2)/(x3-x2)))
    {
        printf("the three points are collinear");
    }
    else
    {
        printf("the three points are not collinear");
    }
    return 0;

}

