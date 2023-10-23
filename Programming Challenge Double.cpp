/*
Write a RainFall program that stores the total rainfall for each of 12 months into an array of doubles.
The program should have methods that return the following:
the total rainfall for the year
the average monthly rainfall
the month with the most rain
the month with the least rain
Input Validation: Do not accept negative numbers for monthly rainfall figures.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
const int Array_Size = 12;
double most, least, total, avg;
int month, a;
double rainfall[Array_Size];

double monthly(double rainfall[Array_Size])
{
    for(a = 0; a < 12; a++)
    {
        cout <<"Rainfall for month " << (a + 1) <<" : " << rainfall[a] << " inch(es)" << endl;
    }
    cout << endl;
return 0;
}

double mostest(double rainfall[Array_Size])
{
    month = 0;
    most = rainfall[0];
    for(a = 1; a < 12; a++)
    {
        if(rainfall[a] > most)
        {
            most = rainfall[a];
            month = a;
        }
    }
    cout << "Month " << (month + 1) << " has the highest rainfall amount of " << most << "." << endl;
return 0;
}

double leastest(double rainfall[Array_Size])
{
    month = 0;
    least = rainfall[0];
    for(a = 1; a < 12; a++)
    {
        if(rainfall[a] < least)
        {
            least = rainfall[a];
            month = a;
        }
    }
    cout << "Month " << (month + 1) << " has the lowest rainfall amount of " << least << "." << endl;
return 0;
}

double allRain(double rainfall[Array_Size])
{
    total = 0;
    for(a = 0; a < 12; a++)
    {
        total += rainfall[a];
    }
    return total;
}

double rainAVG(double rainfall[Array_Size])
{
    double avg;
    avg = allRain(rainfall)/12;
    return avg;
}
int main()
{
    cout << fixed << showpoint << setprecision(2);
    for(a = 0; a < 12; a++)
    {
        cout << "Enter Rainfall(in inches) for month " << (a + 1) << " : ";
        cin >> rainfall[a];
        while (rainfall[a] < 0)
        {
            cout << "No negative numbers." << endl;
            cin >> rainfall[a];
        }
    }

    monthly(rainfall);
    mostest(rainfall);
    leastest(rainfall);
    cout << "\nThe total rainfall for the entire year(in inches) was: " << allRain(rainfall);
    cout << "\nThe average rainfall for the entire year was " << rainAVG(rainfall) << " inches per month.";

return 0;
}
