#include <stdio.h>
#include <string.h>
#include <ctype.h>// Libraries used
int root();
int user();
int cartadder();
int cartremover();//functions used
int item[6] = {5, 3, 7, 2, 10,1}; /*This defines the amount of items, basically an array:item [0] = football, 
item [1] =helmet, item [2] =cricket_ball, item [3] =cricket_bat,item [4] =boots, item [5] =Ar47 */
int cart[6]={0,0,0,0,0,0};
char choice,count;
int itemchoice, newvalue,cost;
int football = 5,helmet= 3,cricket_ball=7,cricket_bat= 2, boots=10,Ar47=1; //Global variables used
int main(int argc, char *argv[]) //main function to check how the program is accessed as
{  
     if (argc >= 2 && strcmp(argv[1], "root") == 0) 
    {
    root();
    }
    else
    {
    user();
    }
    return 0;
} 

// User function

int user(){
    printf("\n \n");
    printf("Would you like to buy items? Y or N: ");
    scanf("%c", &choice);
    getchar();
    count = tolower((int)choice);
    if (count == 'y') {
           do{
                printf("Which item would you like to buy \n");
                printf("1. Football [In stock : %d] \n2. Helmet [In stock : %d] \n3. Cricket Ball [In stock : %d]\n4. Cricket Bat [In stock : %d] \n5. Boots [In stock : %d]\n6. Ar47 [In stock : %d]\n", item[0], item[1], item[2], item[3], item[4], item[5]);
                printf("enter your choice: ");
                scanf("%d", &itemchoice);
                
                if (itemchoice < 1 || itemchoice > 6) {
                    printf("Invalid input. Please enter a number from 1 to 6.\n");
                    printf("You have been logged out \n");
                    break;
                }
                else{
                    cartadder();
                }
                printf("\n Options : \n  \t Check cart and finalize [E] \n \t Continue shopping [C] \n \t Your choice: ");
                scanf("%c", &choice);
                getchar();
                count = tolower((int)choice);
                if(count == 'e')
                {
                    printf("Your cart is:  \n");
                    printf("1. Football [1000 each] : %d \n2. Helmet [2000 each]: %d \n3. Cricket Ball [100 each]: %d\n4. Cricket Bat [1500 each] : %d \n5. Boots [800 each]: %d\n6. Ar47 [45000 each]: %d\n", cart[0], cart[1], cart[2], cart[3], cart[4], cart[5]);
                    cost = 1000* cart[0] + 2000 * cart[1] + 100 * cart[2] + 1500 * cart[3] + 800* cart[4] + 45000* cart[5];
                    printf("\n \n Total cost : %d \n \n",cost);
                    printf("Do you wish to continue[C] or finalize[F] or edit amount [E]: ");
                    scanf(" %c", &choice);
                    getchar();
                    count = tolower((int)choice);
                    if (count == 'c') {
                    continue;
                    } else if (count == 'e') {
                        printf("Which item you want to modify: ");
                        scanf("%d", &itemchoice);
                        cartremover();
                    } else if (count == 'f'){
                    printf("Congrats, you paid %d to get your items \n",cost);
                    return 0;
                    }
                else {
                printf("Invalid input\n");
                break;
            }
                }   
            }
            while (1);
    }
    else
    {
        printf("logging out \n");
        return 0;
    }
}


int root()
{
    printf("Would you like to change the amount of items as root? Y or N: ");
    scanf("%c", &choice);
    getchar();
    count = tolower((int)choice);
    if (count == 'y') {
        do{
            printf("Which item would you like to change/restock? \n");
            printf("1. Football [In stock : %d] \n2. Helmet [In stock : %d] \n3. Cricket Ball [In stock : %d]\n4. Cricket Bat [In stock : %d] \n5. Boots [In stock : %d]\n6. Ar47 [In stock : %d]\n", item[0], item[1], item[2], item[3], item[4], item[5]);
            printf("enter the no: ");
            scanf("%d", &itemchoice);
            if (itemchoice < 1 || itemchoice > 6) {
            printf("Invalid input. Please enter a number from 1 to 6.\n");
            printf("You have been logged out \n");
            break;
            }
            printf("What is the new value of that item: ");
            scanf("%d", &newvalue);
            item[itemchoice - 1] = newvalue;
            printf("New values are :\n \n \n");
            printf("1. Football [In stock : %d] \n2. Helmet [In stock : %d] \n3. Cricket Ball [In stock : %d]\n4. Cricket Bat [In stock : %d] \n5. Boots [In stock : %d]\n6. Ar47 [In stock : %d]\n", item[0], item[1], item[2], item[3], item[4], item[5]);          
            printf("\n Would you like to continue changing [C], Exit [E] or log as user[U]: ");
            scanf(" %c", &choice);
            getchar();
            count = tolower((int)choice);
            if (count == 'c') {
                continue;
            } else if (count == 'e') {
                break;
            } else if (count == 'u'){
                user();
                break;
            } else {
                printf("Invalid input\n");
                break;
            }
        } while (1);
        return 0;
    }
    else
    {   printf("You have been logged out \n");
        return 0;
    }
}


int cartadder()
{
    
    do{
        printf("Enter how many of the item you want to add in your cart: ");
        scanf("%d", &newvalue);
        getchar();
        if ((int)newvalue <= item[itemchoice - 1] && (int) newvalue >= 0) {
            printf("%d of this item has been added to your cart \n", newvalue);
            cart[itemchoice - 1] = cart[itemchoice-1] +newvalue;
            item[itemchoice - 1] = item[itemchoice - 1] - newvalue;
            break;
        }
        printf("Invalid amount, please re-enter the amount [R] or exit [E]: ");
        scanf(" %c", &choice); 
        getchar();  
        count = tolower((int)choice);
        if (count == 'e') {
            printf("Going back\n");
            break;
        }
    }
    while (1);

}
int cartremover()
{
    do{
        printf("Enter new value of item:");
        scanf("%d", &newvalue);
        getchar();
        if ((int)newvalue <= (item[itemchoice - 1] + cart[itemchoice-1]) && (int) newvalue >= 0) {
            printf("\n Congrats change accepted \n", newvalue);
            if(newvalue < cart[itemchoice-1]){
                item[itemchoice - 1] = item[itemchoice - 1] + cart[itemchoice - 1] - newvalue;
                cart[itemchoice -1] = newvalue;
                break;
            }
            else{
                item[itemchoice - 1] = item[itemchoice - 1] - cart[itemchoice - 1] + newvalue;
                cart[itemchoice-1] = newvalue;
                break;
            }
        }
        printf("Invalid amount, please re-enter the amount [R] or exit [E]: ");
        scanf(" %c", &choice); 
        getchar();  
        count = tolower((int)choice);
        if (count == 'e') {
            printf("Going back\n");
            break;
        }
    }
    while (1);
}
