#include<stdio.h>
int main()
{
    float wt_kg ,ht_mts ,bmi;
    printf("Enter the value of weight(kg) and height(mts) of person-");
    scanf("%f%f",&wt_kg,&ht_mts);
    bmi=wt_kg/(ht_mts*ht_mts);
    if (bmi<=15)
    printf("Person is Starvation");
     else if (bmi >=15.1 && bmi<=17.5)
    printf("Person is Anorexic");
    else if(bmi>= 17.6 && bmi <=18.5)
    printf("Person is Underweight");
    else if(bmi>=18.6 && bmi<=24.9)
    printf("Person is Ideal");
    else if(bmi>=25 && bmi<=29.9)
    printf("Person is Overweight");
    else if(bmi>=30 && bmi<=39.9)
    printf("Person is Obese");
    
    else
    printf("Person is Morbidity Obese");
    return 0;
}