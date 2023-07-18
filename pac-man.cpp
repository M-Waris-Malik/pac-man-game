#include <iostream>
#include <conio.h>
#include <windows.h>

#define H 16
#define W 41

using namespace std;

int food_collect = 0;
bool game_end = false;
int py = 1, px = 1;  // these variables represent pacman coordinate
int gy1 = 1, gx1 = 38, gy2 = 13, gx2 = 1;  // these variables represent ghosts coordinate

void game_result()
{
    // this function checks if you won the game or not
    system("cls");
    if (food_collect == 500)
    {
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t        Congratulations!\n";
        cout << "\t\t\t       You won the game!\n";
        cout << "\t\t\t     Your total score is " << food_collect << endl;
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t       You lost the game!\n";
        cout << "\t\t\t     Your total score is " << food_collect << endl;
    }
}

void move_ghosts()
{
    if (gy1 == 1 && gx1 > 1)
    {
        gx1--;  // this statement moves the 1st ghost coordinate to the left side
    }
    else if (gx1 == 1 && gy1 < 7)
    {
        gy1++;  // this statement moves the 1st ghost coordinate to the down side
    }
    else if (gy1 == 7 && gx1 < 38)
    {
        gx1++;  // this statement moves the 1st ghost coordinate to the right side
    }
    else if (gx1 == 38 && gy1 > 1)
    {
        gy1--;  // this statement moves the 1st ghost coordinate to the up side
    }

    if (gy2 == 13 && gx2 < 38)
    {
        gx2++;  // this statement moves the 2nd ghost coordinate to the right side
    }
    else if (gx2 == 38 && gy2 > 7)
    {
        gy2--;  // this statement moves the 2nd ghost coordinate to the up side
    }
    else if (gy2 == 7 && gx2 > 1)
    {
        gx2--;  // this statement moves the 2nd ghost coordinate to the left side
    }
    else if (gx2 == 1 && gy2 < 13)
    {
        gy2++;  // this statement moves the 2nd ghost coordinate to the down side
    }
}

void user_input()
{
    // this function is used to take user input
    char c1;
    if (kbhit())
    {
        c1 = getch();

        switch (c1)
        {
        case 72:
            py--;
            break;  // cursor up
        case 80:
            py++;
            break;  // cursor down
        case 75:
            px--;
            break;  // cursor left
        case 77:
            px++;
            break;  // cursor right
        }
    }
}

void setup(char playfield[][W])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (playfield[i][j] == '#')
            {
                playfield[i][j] = ' ';
            }
            if (playfield[i][j] == '@')
            {
                playfield[i][j] = '.';
            }
        }
    }
    if (playfield[py][px] == '.')
    {
        food_collect++;
    }
    if (playfield[py][px] == '*')
    {
        py = 1;
        px = 1;
    }
    playfield[py][px] = '#';
    playfield[gy1][gx1] = '@';
    playfield[gy2][gx2] = '@';

    if (playfield[py][px] == '@')
    {
        game_end = true;
    }
}

void draw_playfield(char playfield[][W])
{
    cout << "\n\n\n\n";
    for (int i = 0; i < H; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < W; j++)
        {
            cout << playfield[i][j];
        }
        cout << "\n";
    }
    cout << "Score is " << food_collect << endl;
}

int main()
{
    char playfield[H][W] = {
        "****************************************",
        "* .....................................*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*......................................*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*..*..*..*..*..*..*..*..*..*..*..*..*..*",
        "*......................................*",
        "****************************************"
    };
    int i = 100;
    while (!game_end)
    {
        system("cls");
        setup(playfield);
        user_input();
        move_ghosts();
        draw_playfield(playfield);
        Sleep(200);
        if (i < 1000)
            i = i + 100;
        else
            i = 100;
    }

    game_result();
    return 0;
}

