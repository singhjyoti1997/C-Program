#include<stdio.h>
int main()
{
    int length_a,length_b,length_c,width_a,width_b,width_c, m,peri1,peri2,peri3 ;
	printf("Enter the three length's consecutively of rectangle:-");
	scanf("%d %d %d",&length_a,&length_b,&length_c);
    printf("Enter the three width's consecutively of rectangle:-");
    scanf("%d %d %d",&width_a,&width_b,&width_c);
	peri1=2*length_a+2*width_a;
	peri2=2*length_b+2*width_b;
	peri3=2*length_c+2*width_c;
	m=(peri1>peri2&&peri1>peri3)?(peri1):((peri2>peri1&&peri2>peri3)?peri2:peri3);
	printf("Rectangle has the highest perimeter is -%d",m);
    return 0 ;
	
}