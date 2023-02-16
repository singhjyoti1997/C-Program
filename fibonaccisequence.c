#include <stdio.h>
void fibo (int );
int main()
{
  int num;
  printf("Enter number of terms in Fibonacci sequence:-");
  scanf("%d", &num);
  fibo(num);
  return 0;
}
void fibo (int n)
{
  int n1 = 0, n2 = 1, n3, i;
  printf("%d %d", n1, n2);
  for (i = 3; i <= n; i++)
  {
    n3 = n1 + n2;
    printf(" %d", n3);
    n1 = n2;
    n2 = n3;
  }
}