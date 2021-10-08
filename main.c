#include <stdio.h>
#include <stdlib.h>

//product list

//1. Product names
const char ProductNames[5][40] = {"Milk",
                                  "Cheese",
                                  "Yogurt",
                                  "butter",
                                  "ice"
                                  };



//2. Product prices
const float product_price[5] = {90.00,
                                130.00,
                                40.00,
                                110.00,
                                50.00
                                };

//3. Product_reference
const int product_Ref[5] = {0,1,2,3,4};

//functions
void print_product_list();  //printing the product list
int choiceReference(int choice);
float PriceReference(int ref);

float price_for_one_choice(int unitPrice,int quantity);


int main()
{

    print_product_list();

    //asking from the customer about purchasing till customer decide to exit
    char answer;
    float cart = 0.0;

    do{

            int choice;
            int quantity = 0;


                printf("Enter the product you want (Ref.No): ");
                scanf("%d", &choice);

                if(choice>=0 && choice<5){
                    printf("Enter the Quantity: ");
                    scanf("%d", &quantity);

                    int ref = choiceReference(choice);
                    float unitPrice = PriceReference(ref);
                    float choicePrice = price_for_one_choice(unitPrice,quantity);
                    cart+= choicePrice;

                    printf("your bill is %.2f \n\n", cart);


                    printf("Do you want to buy more: ");
                    scanf(" %c", &answer);

                }

    }while(answer == 'y' || answer == 'Y');

    printf("\n\n\n");
    printf("Your total cost is %.2f\n", cart);


    return 0;
}

void print_product_list(){

    printf("Welcome to Dairy shop");
    printf("\n\n\n");

    printf("Product\tPrice\tRef.No");
    printf("\n");

    for(int i=0; i<5; i++){ //number of names
       printf("%s\t%.2f\t%d", ProductNames[i],product_price[i],product_Ref[i]);
       printf("\n");
    }
    printf("\n\n\n");

}

int choiceReference(int choice){

    for(int i=0; i<5; i++){
        if(choice == i){
            return product_Ref[i];
        }
    }
}

float PriceReference(int ref){
    for(int i=0; i<5; i++){
        if(ref == i){
            return product_price[i];
        }
    }

}


float price_for_one_choice(int unitPrice,int quantity){
     float choicePrice = unitPrice * quantity;
     return choicePrice;
}
