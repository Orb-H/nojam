#include <iostream>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

int arr[2001];
int pal[2001][2001] = {0,};

int is_palindrome(int s, int e) {
    if (s == e) return 3;
    if (e - s == 1) return (arr[s] == arr[e]) * 2 + 1;

    if (!pal[s][e])
        pal[s][e] = is_palindrome(s + 1, e - 1) & ((arr[s] == arr[e]) * 2 + 1);

    return pal[s][e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, e, tmp;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << is_palindrome(s, e) / 2 << "\n";
    }
}