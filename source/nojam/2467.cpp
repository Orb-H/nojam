#include <iostream>

#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int main() {
    int n;
    long long value[100000];
    int left, right, min_left, min_right, min;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> value[i];
    
    left = 0;
    right = n - 1;
    min_left = left;
    min_right = right;
    min = abs(value[left] + value[right]);

    while (left < right) {
        if (min > abs(value[left] + value[right])) {
            min = abs(value[left] + value[right]);
            min_left = left;
            min_right = right;
        }

        if (abs(value[left + 1] + value[right]) > abs(value[left] + value[right - 1]))
            right--;
        else
            left++;
    }

    cout << value[min_left] << " " << value[min_right];
}