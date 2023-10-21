/*
When you borrow money to buy a house, a car, or for some other purposes,then you typically repay it by making periodic payments. Suppose that the loan amount is L, r is the interest rate per year, m is the number of payments in a year, and the loan is for t years. Suppose that i = r/m and r is in decimal.
Then the periodic payment is:
R = Li
1 −(1 + i)−mt
You can also calculate the unpaid loan balance after making certain payments. For example, the unpaid balance after making k payments is:
L′ = R
[1 −(1 + i)−(mt−k)
i
]
, (3)
where R is the periodic payment. (Note that if the payments are monthly,
then m = 12 .)
Write a program that prompts the user to input the values of L, r, m, t,
and k. The program then outputs the appropriate values. Your program must contain at least two functions, with appropriate parameters, to calculate the periodic payments and the unpaid balance after certain payments. Make the program menu driven and use a loop so that the user can repeat the program for different values.*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

double L = 0; //loan amount
double r; // interest rate
double R; // periodic payment
double Lprime = 0.0; // unpaid balance
double i;
int k; // # of made payments
int M; // payments per year
int T; // # of years
char choice;

double periodic(double r, int M, double i, double L, double R, int T)//figure out R
{
    r = (r / 100);
    i = (double)(r / M);
    //double W = (1.0 - pow((1.0 + i), -(M * T)));
	R = (L * i) / (1 - (1 / pow((1 + i), (M * T))));
	return R;
}

double unpaid (double Lprime, double r, double R, double i, int M, int T, int k) //figure out Lprime
{
    //double X = (1.0 - pow(1.0 + i, -(M * T - k))); //contain the exponent section
    // Lprime = R * ((1 - pow(1 + i, -(M * T -k))) / i);
    r = (r / 100);
    i = (double)(r / M);
    Lprime = R * ((1 - pow(1 + i, -(M * T -k))) / i);
    return Lprime;
}

int main()
{
    while(1)
    {
        cout << "Enter (y) to find the periodic payment and unpaid balance after certain payments: ";
        cin >> choice;
        cout << endl;
        if (choice != 'Y' && choice != 'y')
            break;
        cout << "Please enter the loan amount: ";
        cout << "$";
        cin >> L;
        cout << endl;


        cout << "Please enter the annual percentage rate: ";
        cin >> r;
        cout << endl;

        cout << "Please enter the number of payments to be made per year: ";
        cin >> M;
        cout << endl;

        cout << "Please enter the number of years the loan is for: ";
        cin >> T;
        cout << endl;

        R = periodic(r, M, i, L, R, T);

        cout << "The periodic payment is: " << R << fixed << showpoint << setprecision(2);
        cout << endl;

        cout << "Please enter the number of payments that have been made: ";
        cin >> k;
        cout << endl;

        Lprime = unpaid(Lprime, r, R, i, M, T, k);

        cout << "The unpaid balance after " << k << " payment(s) is: " << Lprime << fixed << showpoint<< setprecision(2) << endl;
        cout << endl;
    }

}
