#include "Mybank.h"
#include <stdio.h>
float arr[ROWS][COLS] = { 0 };
int account_numbers[ROWS] = { 0 ,0,0,0,0};
int count = 0;

int  Opening_an_account(float initial_amount) {

	srand(time(NULL));
	int upper = 950;
	int lower = 901;
	int Account_Number;
	if (count >= 5) {
	return printf("No bank account available. \n");
	}
	else {
		for (int i = 0; i < ROWS;i++) {
		for (int j = 0; j < COLS; j++) {
			if (arr[i][j] == 0) {
				count++;
				arr[i][j] = 1;
				arr[i][j + 1] = initial_amount;
				Account_Number = (rand() % (upper-lower+1)+lower);
				account_numbers[i] = Account_Number;
				printf("the num_account is: %d \n ", account_numbers[i]);
				return Account_Number;
				break;
			}

		}
}
}
	}


void Balance_inquiry(int Account_Number) {
	int c = 0;
	for (int i = 0;i < ROWS; i++) {
		if (account_numbers[i] == Account_Number) {
			c++;
			for (int j = 0; j < COLS; j++) {
			printf("the balance is: %.2f \n ", arr[i][j + 1]);
			}
	}
	}
	if (c == 0) {
		printf("The account number you entered does not exist.\n");
	}
}
void Deposit(int Account_Number) {
	float deposit_amount;
	int c1 = 0;
	for (int i = 0; i < ROWS; i++) {
		if (account_numbers[i] == Account_Number) {
			c1++;
			for (int j = 0; j < COLS; j++) {
				printf("How much you want to deposit? ");
				scanf(" %f", &deposit_amount);
				arr[i][j + 1] = arr[i][j + 1] + deposit_amount;
				printf("the new deposit is: %.2f \n ", arr[i][j + 1]);
				break;
			}
	    }

	}
	if (c1 == 0) {
		printf("The account number you entered does not exist.\n");
	}
}
void Withdrawal(int Account_Number) {
	float withdrawal; 
	int c2 = 0;
	for (int i = 0; i < ROWS; i++) {
		if (account_numbers[i] == Account_Number){
			c2++;
			for (int j = 0; j < COLS; j++) {
				printf("How much cash would you like to withdraw?");
				scanf(" %f", &withdrawal);
				if (arr[i][j + 1] - withdrawal < 0) {
					printf("Not enough cash available for withdrawal.\n");
					break;
				}
			
				arr[i][j + 1] = arr[i][j + 1] - withdrawal;
				printf("the new deposit is: %.2f \n ", arr[i][j + 1]);
				break;
			}
		}

	}
	if (c2 == 0) {
		printf("The account number you entered does not exist.\n");
	}
	}
void Close(int Account_Number) {
	int c3 = 0;
	for (int i = 0; i < ROWS; i++) {
		if (account_numbers[i] == Account_Number){
			c3++;
			for (int j = 0; j < COLS; j++) {
				account_numbers[i] = 0;
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
				break;
			}
		}

	}

	if (c3 == 0) {
		printf("The account number you entered does not exist.\n");
	}
}
void Rate_interest(float Percentage_interest) {

	for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLS; j++) {
	if (arr[i][j] != 0) {
     arr[i][j + 1] = arr[i][j + 1] + ((arr[i][j+1]* Percentage_interest)/100);
				break;
			}

		}

	}
}
void Print() {
	for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLS; j++) {
	if (arr[i][j] == 1) {
	printf("Account Number: %d and balance: %.2f \t ", account_numbers[i], arr[i][j+1]);
	}
	}
	printf("\n ");
	}
}
void Close_all_accounts() {

	for(int i=0; i<ROWS ; i++){
account_numbers[i] = 0;
for(int j=0;j<COLS ;j++){
arr[i][j]=0;
}
}

	printf("All accounts were closed. Goodbye (:\n ");

}

