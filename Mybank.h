#ifndef _MYBANK_H
#define _MYBANK_H
#define COLS 2 
#define ROWS 50
#include<stdlib.h>
#include <time.h>
extern float arr[ROWS][COLS];
int Opening_an_account(float initial_amount);
void Balance_inquiry(int Account_Number);
void Deposit(int Account_Number);
void Withdrawal(int Account_Number);
void Close(int Account_Number);
void Rate_interest(float Percentage_interest);
void Print();
void Close_all_accounts();










#endif
