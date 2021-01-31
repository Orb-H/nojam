#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int main() {
    int n;
    int arr[3];
    int max_val[2][3];
    int min_val[2][3];

    cin >> n;

    cin >> arr[0] >> arr[1] >> arr[2];
    
    for (int i = 0; i < 3; i++)
        max_val[1][i] = min_val[1][i] = arr[i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[j];
            max_val[0][j] = max_val[1][j];
            min_val[0][j] = min_val[1][j];
        }

        max_val[1][0] = max(max_val[0][0], max_val[0][1]) + arr[0];
        max_val[1][1] = max(max_val[0][0], max(max_val[0][1], max_val[0][2])) + arr[1];
        max_val[1][2] = max(max_val[0][1], max_val[0][2]) + arr[2];
        min_val[1][0] = min(min_val[0][0], min_val[0][1]) + arr[0];
        min_val[1][1] = min(min_val[0][0], min(min_val[0][1], min_val[0][2])) + arr[1];
        min_val[1][2] = min(min_val[0][1], min_val[0][2]) + arr[2];
    }

    cout << max(max_val[1][0], max(max_val[1][1], max_val[1][2])) << " " << min(min_val[1][0], min(min_val[1][1], min_val[1][2]));
}