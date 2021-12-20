#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define DEBUG
class Solution
{
public:
    int checkWin(int i, int j, vector<string> &board)
    {
        if (board[i][j] == ' ')
        {
            return 0;
        }
        if (i - 1 >= 0 && i + 1 < 3 && board[i - 1][j] == board[i + 1][j] && board[i - 1][j] == board[i][j])
        {
            return board[i][j] == 'X' ? 1 : 2;
        }
        if (j - 1 >= 0 && j + 1 < 3 && board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1])
        {
            return board[i][j] == 'X' ? 1 : 2;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < 3 && j + 1 < 3)
        {
            if (board[i - 1][j - 1] == board[i][j] && board[i + 1][j + 1] == board[i][j])
            {
                return board[i][j] == 'X' ? 1 : 2;
            }
            if (board[i + 1][j - 1] == board[i][j] && board[i - 1][j + 1] == board[i][j])
            {
                return board[i][j] == 'X' ? 1 : 2;
            }
        }
        return 0;
    }
    bool validTicTacToe(vector<string> &board)
    {
        int countA, countB;
        countA = countB = 0;
        bool winA, winB;
        winA = winB = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    countA++;
                }
                if (board[i][j] == 'O')
                {
                    countB++;
                }
                int win = checkWin(i, j, board);
                if (win == 1)
                {
                    winA = true;
                }
                else if (win == 2)
                {
                    winB = true;
                }
            }
        }
        if (countB != countA && countB + 1 != countA)
        {
            return false;
        }
        if (winA && winB)
        {
            return false;
        }
        if (countA > countB && winB)
        {
            return false;
        }
        if (countA == countB && winA)
        {
            return false;
        }

        return true;
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> t1{{1, 2, 3}, {4, 0, 5}};
    cout << s.slidingPuzzle(t1) << endl;
    return 0;
}