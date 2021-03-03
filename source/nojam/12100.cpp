#include <iostream>

using namespace std;

int n;
int board[20][20];

int find(int depth) {
    int max = 0, tmp, tmp2;
    if (depth == 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                max = board[i][j] > max ? board[i][j] : max;
        
        return max;
    } else {
        int before[20][20];
        int k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                before[i][j] = board[i][j];
        
        // R
        for (int i = 0; i < n; i++) {
            k = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j]) {
                    tmp2 = board[i][j];
                    board[i][j] = 0;
                    if (tmp2 == board[i][k])
                        board[i][k--] <<= 1;
                    else if (board[i][k])
                        board[i][--k] = tmp2;
                    else
                        board[i][k] = tmp2;
                }
            }
        }

        tmp = find(depth + 1);
        max = tmp > max ? tmp : max;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = before[i][j];

        // U
        for (int i = 0; i < n; i++) {
            k = 0;
            for (int j = 0; j < n; j++) {
                if (board[j][i]) {
                    tmp2 = board[j][i];
                    board[j][i] = 0;
                    if (tmp2 == board[k][i])
                        board[k++][i] <<= 1;
                    else if (board[k][i])
                        board[++k][i] = tmp2;
                    else
                        board[k][i] = tmp2;
                }
            }
        }

        tmp = find(depth + 1);
        max = tmp > max ? tmp : max;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = before[i][j];

        // L
        for (int i = 0; i < n; i++) {
            k = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j]) {
                    tmp2 = board[i][j];
                    board[i][j] = 0;
                    if (tmp2 == board[i][k])
                        board[i][k++] <<= 1;
                    else if (board[i][k])
                        board[i][++k] = tmp2;
                    else
                        board[i][k] = tmp2;
                }
            }
        }

        tmp = find(depth + 1);
        max = tmp > max ? tmp : max;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = before[i][j];

        // D
        for (int i = 0; i < n; i++) {
            k = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (board[j][i]) {
                    tmp2 = board[j][i];
                    board[j][i] = 0;
                    if (tmp2 == board[k][i])
                        board[k--][i] <<= 1;
                    else if (board[k][i])
                        board[--k][i] = tmp2;
                    else
                        board[k][i] = tmp2;
                }
            }
        }

        tmp = find(depth + 1);
        max = tmp > max ? tmp : max;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = before[i][j];
        
        return max;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    cout << find(0);
}