#include <stdio.h>
void customer_belows_100();
struct customer_bank
{
    char customer_ac_name[20];
    int customer_ac_number;
    int customer_ac_balence;
};
 struct customer_bank a[200];
int main()
{
    int i, n;
    
    printf("Enter the number of  data of customers in a bank\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the customer account name:-");
        scanf("%s", &a[i].customer_ac_name);
        printf("Enter the Customer account number:-");
        scanf("%d", &a[i].customer_ac_number);
        printf("Enter the Customer bank balence:-");
        scanf("%d", &a[i].customer_ac_balence);
    }
    printf("Costomer Bank record -\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Customer account name:-%s\n", a[i].customer_ac_name);
        printf("Customer account number:-%d\n", a[i].customer_ac_number);
        printf("Customer bank balence:-%d\n", a[i].customer_ac_balence);
    }
    printf("\ncustomer with a balance below Rs 100");
    customer_belows_100();

    return 0;
}
void customer_belows_100()
{
 int i ;
  for(i=0;i<200;i++)
{
    {
		if (a[i].customer_ac_balence < 100 && a[i].customer_ac_balence> 0)
		{
			printf("\nCustomer account name:- %s", a[i].customer_ac_name);
			printf("\n Customer Account Number : %d",a[i].customer_ac_number);
		}
	}
} }

