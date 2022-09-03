//Created by Hnin Thandar Aye

//Char Pointer , String and Array



#include<stdio.h>
#include<string.h>

int priceCalculation (int foodPrice,int number);

/*dollar per one
priceOfHamburger = $12;
priceOfSandwich = $3;
priceOfPizza = $7;
priceOfSpaghetti = $15;
priceOfSushi = $1;*/
int price[] = {12, 3, 7, 15, 1};

int numberOfOrder = 0;
int totalPrice = 0;
int pay = 0;

int main(){

char *order[5];

char *foodAvailable[] = {"Hamburger", "Sandwich", "Pizza", "Spaghetti", "Sushi"};
/*printf("size of foodAvailable = %d (pointer).\n",sizeof(foodAvailable));
printf("array length of foodAvailable = %d\n",sizeof(foodAvailable)/sizeof(foodAvailable[0]));

for(int i = 0; i < 5; i++){
  printf("index number = %d, memory address = %x, value = %s\n", i, &foodAvailable[i], foodAvailable[i]);
}*/

printf("\n Available Food: Hamburger, Sandwich, Pizza, Spaghetti, Sushi!\n\n\n");
printf("  Which one would you like to order today? ");

scanf("%s",order);


for(int i = 0; i < 5; i++){

  if (strcmp(order,foodAvailable[i]) == 0){
      printf("  Price per one %s is $%d.\n\n",foodAvailable[i],price[i]);
      printf("  How many numbers would you like to order? ");
      scanf("%d",&numberOfOrder);
      totalPrice = priceCalculation (price[i],numberOfOrder);
      printf("  Your order is %d %s and total cost is $%d.\n\n\n",numberOfOrder, foodAvailable[i], totalPrice);

      printf("  Please pay in USD: ");
      scanf("%d",&pay);

         if(pay > totalPrice){
            printf("  Take $%d change.\n  Thank you for order!\n  HAVE A NICE DAY!\n\n",pay - totalPrice);
         }else if(pay < totalPrice){
            printf("  Error in pay.\n");

            int payReamining = totalPrice - pay;
            int finishPay = 0;

            printf("  You need more pay of $%d.\n",payReamining);
            printf("  Please pay remain : ");
            scanf("%d",&finishPay);

            if(finishPay == payReamining){
               printf("  Thank you for order!\n  HAVE A NICE DAY!!\n\n");
            }else if(finishPay > payReamining){
             printf("  Take $%d change.\n  Thank you for order!\n  HAVE A NICE DAY!\n\n",finishPay - payReamining);
            }else{
             printf("  Error in pay again.\n  Your order is automatically canceled.\n");
             printf("  Please wait patiently until tomorrow.\n  Thank you.\n  HAVE A NICE DAY!\n\n");
            }
         }else{
          printf("  Thank you for order!\n  HAVE A NICE DAY!\n");
         }
  }
}

return 0;
}

int priceCalculation (int foodPrice,int number){
 int total = foodPrice * number;
 return total;
}
