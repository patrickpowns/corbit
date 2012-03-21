/*
"Auditorium" program designed on 11/03/2012 by Patrick Melanson, Ms Odecki's class
This program stores price and availability about seats in an auditorium, which contains 30x50 seats
It can also determine the value of all seats, or just sold seats, in a n auditorium
Additionally, it can sell blocks of seats, or calculate the price of a block of seats
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

//global declarations
struct auditorium {
	int price;
	bool sold;
};

auditorium seat[50][30];

void DisplayAuditorium();
int NumSold();
int TotalValue();
int SoldValue();
void SellBlock (int y, int n, int x);
int BlockPrice (int y, int n, int x);

int main() {

	int iSold;
	int iTotalValue;
	int iSoldValue;

	//n indicates the number of seats to be operated on
	int x;  //x indicates the starting seat
	int y;  //y indicates the row

	enum cost {LOW = 10, MED = 15, HIGH = 20};
	//initializing seat values, first 5 rows cost $20, next 15 rows cost $15, last 10 rows cost $10
	for (x = 0; x <= 50; x++) {
		for (y = 0; y < 5; y++)
			seat[y][x].price = HIGH;

		for (y = 5; y < 20; y++)
			seat[y][x].price = MED;

		for (y = 20; y < 30; y++)
			seat[y][x].price = LOW;
	}

	DisplayAuditorium();
	printf ("The cost of 50 seats in row 2, starting at seat 1 is:  $%4d\n", BlockPrice (2, 50, 1) );
	SellBlock (2, 50, 1);

	printf ("The cost of 50 seats in row 12, starting at seat 1 is: $%4d\n", BlockPrice (12, 50, 1) );
	SellBlock (12, 50, 1);

	printf ("The cost of 50 seats in row 22, starting at seat 1 is: $%4d\n", BlockPrice (22, 50, 1) );
	SellBlock (22, 50, 1);

	printf ("The cost of 6 seats in row 10, starting at seat 25 is: $%4d\n", BlockPrice (10, 6, 25) );
	SellBlock (10, 6, 25);

	printf ("The cost of 6 seats in row 11, starting at seat 25 is: $%4d\n", BlockPrice (11, 6, 25) );
	SellBlock (11, 6, 25);


	iSold = NumSold();
	printf ("The total number of seats sold is: %4d\n", iSold );
	printf ("the number of seats unsold is: %4d\n\n", (50 * 30) - iSold);
	system ("pause");
	system ("cls");
	DisplayAuditorium();


	iTotalValue = TotalValue();
	iSoldValue = SoldValue();
	printf ("The total value of all seats in the auditorium is: $%d\n", iTotalValue );
	printf ("The total value of all sold seats in the auditorium is: $%d\n", iSoldValue );

	//calculate the percentage of seats sold
//	Printf (" % f.1 % % of the seats in the auditorium are sold", PutaVariableOrCalculationHere);
	//Calculate the percentage of the value sold
//	Printf (" % f.1 % % of the value of the auditorium is sold", PutaVariableOrCalculationHere);

	cout << endl;
	system ("pause");
	return (0);
}

void DisplayAuditorium() {

	int y;
	int x;

	printf ("%56s", "STAGE\n\n");

	for (y = 0; y < 30; y++) {
		printf ("Row %2d |", y + 1);
		for (x = 0; x < 50; x++)
			if (seat[y][x].sold == true)
				printf (" X");
			else if (seat[y][x].sold == false)
				printf (" _");
		printf (" Value: %d Row: %d\n", seat[y][x].price, y);
	}

	printf ("\n");
}

int NumSold() {

	int iSold = 0;

	int y;
	int x;

	for (y = 0; y < 30; y++)
		for (x = 0; x < 50; x++)
			if (seat[y][x].sold == true)
				iSold++;

	return (iSold);
}

int TotalValue() {

	int iValue = 0;

	int y;
	int x;

	for (y = 0; y < 30; y++)
		for (x = 0; x < 50; x++)
			iValue += seat[y][x].price;

	return (iValue);
}

int SoldValue() {

	int iSold = 0;

	int y;
	int x;

	for (y = 0; y < 30; y++)
		for (x = 0; x < 50; x++)
			if (seat[y][x].sold == true)
				iSold += seat[y][x].price;

	return (iSold);
}

void SellBlock (int y, int n, int x) {

	int i;

	for (i = 0; i < n; i++)
		seat[y][x + i].sold = true;
}

int BlockPrice (int y, int n, int x) {

	int iValue = 0;

	int i;

	for (i = 0; i < n; i++)
		iValue += seat[y][x + i].price;

	return (iValue);
}
