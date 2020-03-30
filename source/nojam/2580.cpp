#include <stdio.h>
#include <vector>

using namespace std;

typedef struct
{
    int i;
    int j;
} point;

int board[9][9] = {0};
vector<point> blank;

int find(int d)
{
    if (d >= blank.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        return 1;
    }
    else
    {
        point p = blank[d];
        int pos = (1 << 9) - 1;
        int r;

        //H,V
        for (int i = 0; i < 9; i++)
        {
            pos &= ~(1 << (board[p.i][i] - 1));
            pos &= ~(1 << (board[i][p.j] - 1));
        }
        //B
        int bi = (p.i / 3) * 3;
        int bj = (p.j / 3) * 3;
        for (int i = 0; i < 9; i++)
            pos &= ~(1 << (board[bi + i / 3][bj + i % 3] - 1));

        for (int i = 0; i < 9; i++)
        {
            if (pos & (1 << i))
            {
                board[p.i][p.j] = i + 1;
                r = find(d + 1);
                if (r == 1)
                    return 1;
                board[p.i][p.j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    point p;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &t);
            board[i][j] = t;
            if (t == 0)
            {
                p = {i, j};
                blank.push_back(p);
            }
        }

    find(0);
}