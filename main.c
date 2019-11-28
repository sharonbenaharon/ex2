#include <stdio.h>
#include "Mybank.h"


int main() {


	char action;
	float initial_amount;
	int Account_Number;

	printf("Please choose one of the following: \n O - Open an account \n B - Balance inquiry \n D - Deposit money \n W - cash withdrawal \n C - Account Closing \n I - Add interest \n P - Print open accounts and balance \n E - Close all accounts and sign out \n");
	scanf("%c", &action);
	float Percentage_interest;
	while (action != 'E') {
		switch (action) {
		case 'O':
			printf("Please enter the initial deposit amount: \n");
			scanf("%f", &initial_amount);
			Opening_an_account(initial_amount);
			break;
		case 'B':
			printf("Please enter account number: \n");
			scanf("%d", &Account_Number);
			Balance_inquiry(Account_Number);
			break;
		case 'D':
			printf("Please enter account number: \n");
			scanf("%d", &Account_Number);
			Deposit(Account_Number);
			break;
		case 'W':
			printf("Please enter account number: \n");
			scanf("%d", &Account_Number);
			Withdrawal(Account_Number);
			break;
		case 'C':
			printf("Please enter account number: \n");
			scanf("%d", &Account_Number);
			Close(Account_Number);
			break;
		case 'I':
			printf("What percentage of interest would you like to add?: \n");
			scanf("%f", &Percentage_interest);
			Rate_interest(Percentage_interest);
			break;
		case 'P':
			Print();
		default:
			printf("The action you selected is invalid. \n");
			break;
		}

		printf("Please choose one of the following: \n O - Open an account \n B - Balance inquiry \n D - Deposit money \n W - cash withdrawal \n C - Account Closing \n I - Add interest \n P - Print open accounts and balance \n E - Close all accounts and sign out \n");
		scanf(" %c", &action);

	}

	if (action == 'E') {
		Close_all_accounts();


	}
	return 0;
}
