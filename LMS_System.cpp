#include <iostream>
using namespace std;
#include <conio.h>

#define print(a) cout << a << "\n";
#define input(a, b)    \
    cout << a << "\n"; \
    cin >> b;

int car1 = 0;
int car2 = 0;

char start()
{
    char out = 'x';
    cout << "\033[2J\033[1;1H"; // Clear the screen
    car1 = 0;
    car2 = 0;

    print("*             *  *******  *         ******    *****   *         *  *******")
    print(" *     *     *   *        *        *         *     *  **       **  *")
    print("  *   * *   *    ****     *       *         *       * * *     * *  ****")
    print("   * *   * *     *        *        *         *     *  *   * *   *  *")
    print("    *     *      *******  *******   ******    *****   *    *    *  *******")

    print("\nUs A to move Car 1, and L to move Car 2.")
    print("The car to reach the finish line first will win!!")
    print("\nPRESS [SPACE] to start the game......")
    print("\n------------------------------------------------------")
    print("0")
    print(" ----    ----    ----    ----    ----    ----    ----")
    print("X")
    print("------------------------------------------------------")
    out = tolower(getch());

    return out;
}

void move(char key)
{
    key = tolower(key);
    cout << "\033[2J\033[1;1H"; // Clear the screen
    if (key == 'a')
    {
        car1 += 1;
        print("\n------------------------------------------------------")
        for (int i = 0; i <= car1; i++)
        {
            cout << "\t";
        }
        print("0")
        print(" ----    ----    ----    ----    ----    ----    ----")
        for (int i = 0; i <= car2; i++)
        {
            cout << "\t";
        }
        print("X")
        print("------------------------------------------------------")
    }
    else if (key == 'l')
    {
        car2 += 1;
        print("\n------------------------------------------------------")
        for (int i = 0; i <= car1; i++)
        {
            cout << "\t";
        }
        print("0")
        print(" ----    ----    ----    ----    ----    ----    ----") 
        for (int i = 0; i <= car2; i++)
        {
            cout << "\t";
        }
        print("X")
        print("------------------------------------------------------")
    }
}

int main()
{
    char choice = 'o';
    char turn;
    char out = 'x';

        choice = start();
        if (choice == ' ')
        {
            cout << "\033[2J\033[1;1H"; // Clear the screen
            print("\n------------------------------------------------------")
            print("0")
            print(" ----    ----    ----    ----    ----    ----    ----")
            print("X")
            print("------------------------------------------------------")

            
            while (out != ' ')
            {
                
                turn = getch();
                move(turn);

                if (car1 == 5)
                {
                    cout << "Car 1 wins!!!" << endl;
                    print("Press [SPACE] to continue......")
                    out = getch();
                }
                else if (car2 == 5)
                {
                    cout << "Car 2 wins!!" << endl;
                    print("Press [SPACE] to continue......")
                    getch();
                }
            }
        }

}