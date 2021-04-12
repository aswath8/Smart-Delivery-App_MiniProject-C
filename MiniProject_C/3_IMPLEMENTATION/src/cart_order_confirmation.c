#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"smart_delivery.h"
int cart(int total)
{
    int ch,confirm;
    printf("\n--------------Cart----------------\n");
    printf("Your Total Order Amount is %d\n", total);
    printf("Do You wish to order (y=1/n=0):");
    scanf("%d", &ch);
    if (ch == 1) {
        printf("Please choose the location");
        int res=location();
        if(res==0)
            printf("\nThank You for your order!! Your delivery is on the way\n");
    }
    else if (ch == 0) {
        printf("Do You want to exit (yes=1) or Go back (press 0)");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("\nOops! Your order is cancelled!! Exiting..");
            printf("Thank You visit us again!\n");
            return 1;
        }
        else {
            printf("Thank You\n");
        }
    }
    else {
        printf("\nPlease Enter the ");
        printf("correct choice\n\n");
        cart(total);
    }
}