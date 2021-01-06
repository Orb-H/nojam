#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    char c = -1;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (c == -1)
            c = s[0];
        else if (s[0] != c)
            c = -2;
    }
    
    if (c == -2)
        cout << "0\n";
    else
        cout << "1\n";
}