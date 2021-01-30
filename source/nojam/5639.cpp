#include <iostream>

using namespace std;

int arr[10001];

void print(int s, int e) {
    if (s > e) return;
    else {
        int tmp = s + 1;
        while (tmp <= e && arr[tmp] < arr[s]) tmp++;

        print(s + 1, tmp - 1);
        print(tmp, e);
        cout << arr[s] << "\n";
    }
}

int main() {
    int n = 0;

    while (true) {
        cin >> arr[n++];
        if (cin.eof()) break;
    }
    n--;

    print(0, n - 1);
}