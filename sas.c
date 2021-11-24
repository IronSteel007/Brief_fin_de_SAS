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
int nbraccount = 0;
/*****************************************function Clean****************************/

void cleanCls(){
	system("cls||clear");
}
/***********************************************************************************/

/*************************************fonctions*************************************/

/****************************struct account Tab_Tab_C[nbraccount]***************************/
bool addaccount(int n){

	int i;

	for (i = 0 ; i < n; i++){
		printf("Enter The national ID : ");
		scanf("%s", Tab_C[nbraccount].id_card);

		printf("Enter The lastname : ");
		scanf("%s", Tab_C[nbraccount].lastname);

		printf("Enter The firstlastname : ");
		scanf("%s", Tab_C[nbraccount].firstname);

		printf("Enter The amount : ");
		scanf("%f", &Tab_C[nbraccount].amount);
		nbraccount++;
	}
	return true;
}
/***************************************************************************************/
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
		printf("\t \t \t 1. Deposit \n \n \n");
		printf("\t \t \t 2. withdraw \n \n \n");
		printf("\t \t \t 00. Main Menu \n \n");
		printf("Enter Your choice : ");
		scanf("%d", &_choice_);

		switch (_choice_) {
			case 1 :
				cleanCls();
					for(i = 0; i < nbraccount; i++) {
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
				for(i = 0; i < nbraccount; i++) {
						if (strcmp(id_card, Tab_C[i].id_card) == 0) {
							printf("Enter The operation amount to withdraw : ");
							scanf("%f", &operationamount);
							if (Tab_C[i].amount >= operationamount)
								Tab_C[i].amount -= operationamount;
							else
								printf("Your balance is less than %g MAD \n", operationamount);

							printf("Your amount is : %g MAD\n \n \n", Tab_C[i].amount);
						}
					}
				break;
			default : printf("Your choice don't exist \n");
		}
	}while (_choice_ != 0);
	cleanCls();
}

/********************************************************************************************************/
void affichage() {
	cleanCls();

	int _choice, __choice;
	int sorting, i, j;
	do {
		printf("\t \t \t 1. sorting by lastname  \n \n \n");
		printf("\t \t \t 2. sorting by amount \n \n \n");
		printf("\t \t \t 3. Search by id_card \n \n \n");
		printf("\t \t \t 00. Main Menu \n \n \n");
		printf("What is your choice : \n");
		scanf("%d", &_choice);

		switch (_choice) {
			case 1 :
				printf("\t \t \t 1. Ascending Order \n \n \n");
				printf("\t \t \t 2. Descending Order \n \n \n");
				printf("Enter your choice : ");
				scanf("%d", &__choice);
				switch (__choice) {
					case 1 :
						printf("You have chosen the sort by ----> lastname ----> Ascending Order \n");
						struct account tempaccount;
						for(i = 0 ; i < nbraccount ; i++)
						{
						    for(j = 0 ; j < nbraccount-i-1 ; j++)
						    {
						        if(Tab_C[j].amount > Tab_C[j+1].amount)
						        {
						        	tempaccount = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=tempaccount;
						        }
						    }
						}
						for (i = 0 ; i < nbraccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;
/**************************************************affichage********************************************************************/
					case 2 :
						printf("You have chosen the sort by ----> lastname ----> Descending Order \n");
                        struct account temp_account;
						for(i = 0 ; i < nbraccount ; i++)
						{
						    for(j = 0 ; j < nbraccount-i-1 ; j++)
						    {
						        if(Tab_C[j].amount < Tab_C[j+1].amount)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}

/**************************************affichage********************************************************************/
						for (i = 0 ; i < nbraccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].id_card, Tab_C[i].lastname, Tab_C[i].firstname, Tab_C[i].amount);
						}
						break;
				}
				break;
			case 2 :

				break;
			case 3 :
				cleanCls();
					int i ;
					char id_card[10];
					bool get_it=false;
					printf("Entrer The id_card : ");
					scanf("%s",id_card);
					for(i = 0; i < nbraccount; i++) {
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
	int choice, nbrNewaccount, i;
	char data[50], id_card[10];



//**************************************Main Menu********************************************************************/

	do {

		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t 1. Introduce an account \n\n\n");
		printf("\t\t\t\t 2. Enter multiple accounts \n\n\n");
		printf("\t\t\t\t 3. Operations \n\n\n");
		printf("\t\t\t\t 4. Consultation \n\n\n");
		printf("\t\t\t\t 5. Loyalty \n\n\n");
		printf("\t\t\t\t 0. Quitter \n\n\n");

		printf("Entrer your choice : ");
		scanf("%d", &choice);

		switch (choice) {
			case 1 :
				cleanCls();
				if(addaccount(1)){
					printf("Your account has been successfully created ");
				} else {
					printf("Error 404 !");
				}
				break;
			case 2 :
				printf("Enter the number of accounts that you wanna create : ");
				scanf("%d", &nbrNewaccount);
				addaccount(nbrNewaccount);
				break;
			case 3 :
				operations();
				break;
			case 4 :
				affichage();
				break;
			case 6 :
				cleanCls();
				break;
		}


	} while(choice != 0);


	return 0;
}

