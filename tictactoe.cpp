#include <iostream>
using namespace std;

char Arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}, player = 'X';
int x = 0, check = 0, num_enter[9], num;

void draw_example(void);              // To Draw T-T-T Board
char winner(void);                   // For Giving/Returning Winner(which is Character)
int check_repetition(int num, int x); // For checking Repetition of entered number acts like a Database(of already entered number)
void get_input(void);                 // For taking Input from user and put X/O in the Array
void toggle_player(void);             // For Switching/Toggling Players

int main()
{
    int counter = 0;
    cout << "------Welcome------" << endl;
    cout << "----Tic-Tac-Toe----" << endl
         << endl;
    draw_example();
    cout << "Player 1 -> X" << endl;
    cout << "Player 2 -> O" << endl;
    while (1)
    {
        counter++;
        get_input();
        draw_example();
        if (winner() == 'X')
        {
            cout << "Player 1 Wins" << endl;
            break;
        }
        if (winner() == 'O')
        {
            cout << "Player 2 Wins" << endl;
            break;
        }
        if ((winner() == '/') && (counter == 9))
        {
            cout << "Match-Tie" << endl;
            break;
        }
        toggle_player();
    }
    return 0;
}

void draw_example(void)
{
    cout << endl;
    cout << "     |     |      " << endl;
    cout << "  " << Arr[0] << "  |  " << Arr[1] << "  |  " << Arr[2] << endl;
    cout << "_____|_____|_____ " << endl;
    cout << "     |     |      " << endl;
    cout << "  " << Arr[3] << "  |  " << Arr[4] << "  |  " << Arr[5] << endl;
    cout << "_____|_____|_____ " << endl;
    cout << "     |     |      " << endl;
    cout << "  " << Arr[6] << "  |  " << Arr[7] << "  |  " << Arr[8] << endl;
    cout << "     |     |      " << endl
         << endl;
}

char winner(void)
{
    // For First Player
    // Checking Rows
    if (player == 'X')
    {
        if ((Arr[0] != ' ') && (Arr[0] == Arr[1]) && (Arr[1] == Arr[2]))
            return 'X';
        if ((Arr[3] != ' ') && (Arr[3] == Arr[4]) && (Arr[4] == Arr[5]))
            return 'X';
        if ((Arr[6] != ' ') && (Arr[6] == Arr[7]) && (Arr[7] == Arr[8]))
            return 'X';
        // Checking for Columns
        if ((Arr[0] != ' ') && (Arr[0] == Arr[3]) && (Arr[3] == Arr[6]))
            return 'X';
        if ((Arr[1] != ' ') && (Arr[1] == Arr[4]) && (Arr[4] == Arr[7]))
            return 'X';
        if ((Arr[2] != ' ') && (Arr[2] == Arr[5]) && (Arr[5] == Arr[8]))
            return 'X';
        // Checking for Diagonals
        if ((Arr[0] != ' ') && (Arr[0] == Arr[4]) && (Arr[4] == Arr[8]))
            return 'X';
        if ((Arr[2] != ' ') && (Arr[2] == Arr[4]) && (Arr[4] == Arr[6]))
            return 'X';
    }
    // For Second Player
    // Checking Rows
    if (player == 'O')
    {
        if ((Arr[0] != ' ') && (Arr[0] == Arr[1]) && (Arr[1] == Arr[2]))
            return 'O';
        if ((Arr[3] != ' ') && (Arr[3] == Arr[4]) && (Arr[4] == Arr[5]))
            return 'O';
        if ((Arr[6] != ' ') && (Arr[6] == Arr[7]) && (Arr[7] == Arr[8]))
            return 'O';
        // Checking for Columns
        if ((Arr[0] != ' ') && (Arr[0] == Arr[3]) && (Arr[3] == Arr[6]))
            return 'O';
        if ((Arr[1] != ' ') && (Arr[1] == Arr[4]) && (Arr[4] == Arr[7]))
            return 'O';
        if ((Arr[2] != ' ') && (Arr[2] == Arr[5]) && (Arr[5] == Arr[8]))
            return 'O';
        // Checking for Diagonals
        if ((Arr[0] != ' ') && (Arr[0] == Arr[4]) && (Arr[4] == Arr[8]))
            return 'O';
        if ((Arr[2] != ' ') && (Arr[2] == Arr[4]) && (Arr[4] == Arr[6]))
            return 'O';
    }
    return '/';
}

int check_repetition(int num, int x)
{
    int c = 0;
    for (int i = x - 1; i >= 0; i--)
    {
        // cout << num_enter[i];
        if (num == num_enter[i - 1])
        {
            c = 1;
            // break;
        }
    }
    return c;
}

void get_input(void)
{
    cout << "Enter the Number: ";
    cin >> num;
    num_enter[x] = num;
    x++;
    if (x > 1)
        check = check_repetition(num, x);
    if (check == 0)
    {
        // for loop can be used for below process, but it takes O(n) and less lines of code
        // these if takes O(1)
        if (num == 1)
            Arr[0] = player;
        else if (num == 2)
            Arr[1] = player;
        else if (num == 3)
            Arr[2] = player;
        else if (num == 4)
            Arr[3] = player;
        else if (num == 5)
            Arr[4] = player;
        else if (num == 6)
            Arr[5] = player;
        else if (num == 7)
            Arr[6] = player;
        else if (num == 8)
            Arr[7] = player;
        else if (num == 9)
            Arr[8] = player;
    }
    else
    {
        cout << "Number already Entered!" << endl;
        x--;
        get_input();
    }
}

void toggle_player(void)
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}
