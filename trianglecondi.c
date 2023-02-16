#include <stdio.h>
int main()
{
    int side_a, side_b, side_c;
    printf("Enter the sides of triangle:-");
    scanf(" %d %d %d", &side_a, &side_b, &side_c);
    if (side_a + side_b > side_c && side_b + side_c > side_a && side_a + side_c > side_b)
    {
        printf(" triangle is valid\n");
     if  (side_a == side_b && side_b == side_c)
      printf("triangle is equilataral \n");
    else if (side_a == side_b || side_b == side_c || side_c == side_a)
        printf("triangle is isoclecles\n");
    else if (side_a * side_a + side_b * side_b == side_c * side_c ||
        side_b * side_b + side_c * side_c == side_a * side_a ||side_c * side_c + side_a * side_a == side_b * side_b)
        printf("triangle is right angle\n");
    else
        printf("triangle is scalene\n");
    }
    else
        printf("triangle is not valid");
   return 0 ;
 
}
