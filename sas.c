#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/****************************************struct account*****************************/
struct account {
	char id_card[10];
	char lastname[20];
	char firstname[20];
	float amount;
};
/***********************************************************************************/
struct account Tab_C[1000];
int all_account = 0;
/*****************************************function Clean****************************/

void cleanCls(){
	system("cls||clear");
}
/***********************************************************************************/

/*************************************fonctions*************************************/

/****************************struct account Tab_C[all_account]***************************/
bool add_account(int n){

	int i;

	for (i = 0 ; i < n; i++){
		printf("Enter The national ID : ");
		scanf("%s", Tab_C[all_account].id_card);

		printf("Enter The lastname : ");
		scanf("%s", Tab_C[all_account].lastname);

		printf("Enter The firstlastname : ");
		scanf("%s", Tab_C[all_account].firstname);

		printf("Enter The amount : ");
		scanf("%f", &Tab_C[all_account].amount);
		all_account++;
	}
	return true;
}
/************************************fonction Deposit**********************************/
bool Deposit(char id_card[10]) {

}

/***********************************fonction operation*******************************/
bool operations(){
	int _choice_, i;
	char id_card[10];
	float operationamount;

	printf("Enter The id_card of account : ");
	scanf("%s", id_card);

	cleanCls();
	do {
		printf("\n\n\n\n");
		printf("\t  1. Deposit \n \n \n");
		printf("\t  2. withdraw \n \n \n");
		printf("\t  0. Main Menu \n \n");
		printf("Enter Your choice : ");
		scanf("%d", &_choice_);

		switch (_choice_) {
			case 1 :
				cleanCls();
					for(i = 0; i < all_account; i++) {
						if (strcmp(id_card, Tab_C[i].id_card) == 0) {
							printf("Enter The operation amount to Deposit : ");
							scanf("%f", &operationamount);
							Tab_C[i].amount += operationamount;

							printf("Your New Amount is : %g MAD \n", Tab_C[i].amount);
						}
					}
				break;
			case 2 :
				cleanCls();
				for(i = 0; i < all_account; i++) {
						if (strcmp(id_card, Tab_C[i].id_card) == 0) {
							printf("Enter The operation amount to withdraw : ");
							scanf("%f", &operationamount);
							if (Tab_C[i].amount >= operationamount)
								Tab_C[i].amount -= operationamount;
							else
								printf("Your balance is less than %f MAD \n", operationamount);

							printf("Your amount is : %f MAD\n \n \n", Tab_C[i].amount);
						}
					}
				break;
			default : printf("Your choice don't exist \n");
		}
	}while (_choice_ != 0);
	cleanCls();
}
/****************************************************************************************************************************/


/*************************************************display fonction*******************************************************/
void display() {
	cleanCls();
    struct account temp_account;
    char id_card[10];
	int _choice, __choice, i, j;
	do {
		printf("\t  1. sorting by amount \n ");
		printf("\t  2. sorting by lastname \n ");
		printf("\t  3. Search by id_card \n ");
		printf("\t  0. Main Menu \n \n \n");
		printf("What is your choice : \n");
		scanf("%d", &_choice);
/**************************************************display condition********************************************************************/
		switch (_choice) {
			case 1 :
				printf("\t \t \t 1. Ascending Order \n \n \n");
				printf("\t \t \t 2. Descending Order \n \n \n");
				printf("Enter your choice : ");
				scanf("%d", &__choice);
                switch (__choice) {
					case 1 :
						printf("You have chosen the sort by ----> amount ----> Ascending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(Tab_C[j].amount < Tab_C[j+1].amount)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}
						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;

					case 2 :
						printf("You have chosen the sort by ----> amount ----> Descending Order \n");
                        struct account temp_account;
						for(i = 0 ; i > all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(Tab_C[j].amount < Tab_C[j+1].amount)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}

						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;
				}
				break;
			case 2 :
                printf("\t \t \t 1. Ascending Order \n \n \n");
				printf("\t \t \t 2. Descending Order \n \n \n");
				printf("Enter your choice : ");
				scanf("%d", &__choice);
				switch (__choice) {
					case 1 :
						printf("You have chosen the sort by ----> lastname ----> Ascending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(strcmp(Tab_C[j].lastname, Tab_C[j+1].lastname) < 0){
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}
						printf("\n\n\n\t\t\tCIN \t lastname \t firstname \t MONTANT\n\n");


						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;
					case 2 :
						printf("You have chosen the sort by ----> lastname ----> Descending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(strcmp(Tab_C[j].lastname, Tab_C[j+1].lastname) > 0)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}


						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;
				}

				break;
			case 3 :
				cleanCls();
					int i ;
					char id_card[10];
					bool get_it=false;
					printf("Entrer The id_card : ");
					scanf("%s",id_card);
					for(i = 0; i < all_account; i++) {
						if (strcmp(id_card, Tab_C[i].id_card) == 0) {
							get_it=true;
						}
					}
						if (get_it)
							printf("find it \n \n");
						else
							printf("not found \n \n");
				break;
		}
	}while (_choice != 0);
}
/********************************************************************************************************************/
int main(){
	int choice, allNewaccount, i;
	char data[50], id_card[10];



//**************************************Main Menu********************************************************************/

	do {

		printf("\t\t 1. Introduce an account \n\n");
		printf("\t\t 2. Enter multiple accounts \n\n");
		printf("\t\t 3. Operations \n\n");
		printf("\t\t 4. Consultation \n\n");
		printf("\t\t 5. Loyalty \n\n");
		printf("\t\t 0. EXIT \n\n");

		printf("Entrer your choice : ");
		scanf("%d", &choice);

		switch (choice) {
			case 1 :
				cleanCls();
				if(add_account(1)){
					printf("Your account has been successfully created ");
				} else {
					printf("Error 404 !");
				}
				break;
			case 2 :
				printf("Enter the number of accounts that you wanna create : ");
				scanf("%d", &allNewaccount);
				add_account(allNewaccount);
				break;
			case 3 :
				operations();
				break;
			case 4 :
				display();
				break;
			case 5 :
				cleanCls();
				break;
		}


	} while(choice != 0);


	return 0;
}

