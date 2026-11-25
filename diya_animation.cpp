#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

void display(char diya[15][41])
{
    system("cls");

    cout << "\n       SELF BUILDING DIYA\n\n";

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 41; j++)
        {
            cout << diya[i][j];
        }
        cout << endl;
    }
}

int main()
{
    char diya[15][41];

    // Create an empty canvas
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 41; j++)
        {
            diya[i][j] = ' ';
        }
    }

    // Draw the flame
    diya[1][20] = '*';
    diya[2][19] = '/';
    diya[2][20] = '|';
    diya[2][21] = '\\';
    diya[3][20] = '*';

    // Draw first half of diya
    for(int i = 0; i <= 5; i++)
    {
        diya[5+i][20-i] = '\\';
    }

    for(int j = 15; j <= 20; j++)
    {
        diya[11][j] = '_';
    }

    display(diya);

    cout << "\n   First half completed!";

    this_thread::sleep_for(chrono::seconds(2));

    // Automatically draw the second half
    for(int i = 0; i <= 5; i++)
    {
        diya[5+i][20+i] = '/';

        display(diya);

        this_thread::sleep_for(
            chrono::milliseconds(500)
        );
    }

    // Complete the base
    for(int j = 21; j <= 25; j++)
    {
        diya[11][j] = '_';

        display(diya);

        this_thread::sleep_for(
            chrono::milliseconds(200)
        );
    }

    // Final output
    display(diya);

    cout << "\n       HAPPY DIWALI!\n";
    cout << "   Your Diya is Complete!\n";

    return 0;
}
