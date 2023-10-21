#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int Options();
char plane[13][6];
int seats[13][6];
int row;
char seat;
char choice;
string ticket;

void intro()
{
    cout << "Rows 1 & 2 are First Class." << endl;
    cout << "Rows 3 through 7 are Business Class." << endl;
    cout << "Rows 8 through 13 are Economy Class." << endl;
    cout << "All seats marked with * are available for reservation." << endl;
    cout << "All seats marked with X are occupied." << endl << endl;
}

void init_seats()
{
        for(int a = 0; a < 13; a++)
    {
        for(int b = 0; b < 6; b++)
        {
            plane[a][b] = '*';
            seats[a][b] = 0;
        }
    }
}

void seating_arrangements()
{
    cout << "     \tA\tB\tC\tD\tE\tF" << endl;
    for(int a = 0; a < 13; a++)
    {
        cout << "Row: " << (a + 1) << "\t";
        for(int b = 0; b < 6; b++)
        {
            cout << plane[a][b] << "\t";
        }
        cout << endl;
    }
}

void purchasing()
{
        intro();
        cout << "Enter ticket type. (FC, BC, EC): ";
        cin >> ticket;

        cout<<"Desired Row: ";
        cin>>row;

        cout<<"Desired seat (A,B,C,D,E or F): ";
        cin>>seat;
        cout << endl;

            if(ticket == "FC")
            {
                if(row == 1 || row == 2)
                {
                    if(seats[row-1][seat-65] == 0)
                    {
                        seats[row-1][seat-65] = 1;
                        plane[row-1][seat-65] = 'X';
                    }
                    else if(seats[row-1][seat-65] == 1)
                    {
                        cout << "Seat " << row << seat << " is already occupied." << endl;
                    }
                }
                else
                {
                    cout << "Wrong Class" << endl;
                }

            }
            else if(ticket == "BC")
            {
                if(row == 3 || row == 4 || row == 5 || row == 6|| row == 7)
                {
                    if(seats[row-1][seat-65] == 0)
                    {
                        seats[row-1][seat-65] = 1;
                        plane[row-1][seat-65] = 'X';
                    }
                    else if(seats[row-1][seat-65] == 1)
                    {
                        cout << "Seat " << row << seat << " is already occupied." << endl;
                    }
                }
                else
                {
                    cout << "Wrong Class" << endl;
                }
            }
            else if(ticket == "EC")
            {
                if(row == 8 || row == 9 || row == 10|| row == 11|| row == 12|| row == 13)
                {
                    if(seats[row-1][seat-65] == 0)
                    {
                        seats[row-1][seat-65] = 1;
                        plane[row-1][seat-65] = 'X';
                    }
                    else if(seats[row-1][seat-65] == 1)
                    {
                        cout << "Seat " << row << seat << " is already occupied." << endl;
                    }
                }
                else
                {
                    cout << "Wrong Class" << endl;
                }
            }
            cout << endl;
            seating_arrangements();
            cout << endl << endl;
            cout << "Would you like to reserve another seat? ";
            cin >> choice;
}

int main()
{
    int menu;
    init_seats();
    cout << "Welcome to Nondescript Airlines!" << endl << endl;
    intro();
    do
    {
        menu = Options();
        switch(menu)
        {
            case 1:
                cout << "Purchase a Seat\n";
                cout << "Would you like to reserve a seat? ";
                cin >> choice;
                cout << endl;
                while(choice == 'Y' || choice == 'y')
                {
                    purchasing();
                }
                break;

            case 2:
                cout << "Display Seating Chart\n";
                cout << endl;
                seating_arrangements();
                break;

            case 3:
                cout << "Goodbye!\n";
                break;

            default: cout << "Wrong Number\n";
        }
    }while(menu != 3);

return 0;
}

int Options()
{
    int MenuChoice;
        cout << endl << endl;
        cout << " Airline Options\n";
        cout << "1. Purchase a seat.\n";
        cout << "2. Display Seating Chart.\n";
        cout << "3. Quit.\n";
        cin >> MenuChoice;
        cout << endl << endl;
    return MenuChoice;
}
