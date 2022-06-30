#include <iostream>

using namespace std;
char IsWinning(char board[6][7])
{


    char Winner=' ';
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<7; j++)
        {
            if (board [i][j]=='X'&& board [i+1][j+1]=='X' &&board [i+2][j+2]=='X'&& board[i+3][j+3]=='X')
            {
                Winner='X';
                break;
            }
            else if (board [i][j]=='X'&& board [i+1][j-1]=='X' &&board [i+2][j-2]=='X'&& board[i+3][j-3]=='X')
            {
                Winner='X';
                break;
            }
            else if (board [i][j]=='O'&& board [i+1][j+1]=='O' &&board [i+2][j+2]=='O'&& board[i+3][j+3]=='O')
            {
                Winner='O';
                break;
            }
            else if (board [i][j]=='O'&& board [i+1][j-1]=='O' &&board [i+2][j-2]=='O'&& board[i+3][j-3]=='O')
            {
                Winner='O';
                break;
            }
            else if (board [i][j]=='X'&& board [i+1][j]=='X' &&board [i+2][j]=='X'&& board[i+3][j]=='X')
            {
                Winner='X';
                break;
            }
            else if (board [i][j]=='X'&& board [i][j+1]=='X' &&board [i][j+2]=='X'&& board[i][j+3]=='X')
            {
                Winner='X';
                break;
            }
            else if (board [i][j]=='O'&& board [i][j+1]=='O' &&board [i][j+2]=='O'&& board[i][j+3]=='O')
            {
                Winner='O';
                break;
            }
            else if (board [i][j]=='O'&& board [i+1][j]=='O' &&board [i+2][j]=='O'&& board[i+3][j]=='O')
            {
                Winner='O';
                break;
            }
        }
    }
    return Winner;
};
bool Insert (char board[6][7],char player,int column)
{
    bool empt = true;
    for (int i=5; i>-1; i--)
    {
        if (board[i][column] == ' ')
        {
            board[i][column] = player;
            return empt;
        }
        else if (board[i][column] != ' ' && i >0 )
        {
            continue;
        }
        else
        {
            cout<<"column is full"<<endl;
            empt = false;
            return empt;
        }
    }
}
void print(char board[6][7])
{
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<7; j++)
        {
            cout <<'[' << board[i][j] << ']';
        }
        cout << ""<< endl;
    }
    cout << "===============" <<endl;
}
int main()
{
    char player = 'X';
    int column;
    bool notFull= true;
    bool game = true;
    char board[6][7];
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<7; j++)
        {
            board[i][j]= ' ';
        }
    }
    print(board);
    while (game)
    {
        bool place = false;
        cout << "Its Player " << player << " turn."<<endl;
        do
        {
            do
            {
                cout << "please choose a column from 1 to 7 :"<<endl;
                cin >> column;
                column --;
            }
            while (column <0 || column >6);
            notFull =Insert(board,player,column);
        }
        while (!notFull);
        print(board);
        for (int i=0; i<6; i++)
        {
            for (int j=0; j<7; j++)
            {
                if((board[i][j]) ==' ')
                {
                    place = true;
                    break;
                };
            }
        }
        if (IsWinning(board) == ' ' && place == true)
        {
            if (player == 'X')
            {
                player = 'O';
            }
            else if (player == 'O')
            {
                player = 'X';
            }
        }
        else if (IsWinning(board) == ' ' && place == false)
        {
            cout << "It is a draw! " <<endl;
            game = false;
        }
        else
        {
            cout << "The Winner is Player " << player <<endl;
            game = false;
        }
    }


    return 0;
}
