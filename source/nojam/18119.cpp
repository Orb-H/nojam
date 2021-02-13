#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int main() {
    int n, m, o, count;
    vector<int> v;
    int cur = -1;
    string input;

    cin >> n >> m;

    v = vector<int>(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> input;

        for (int j = 0; j < input.length(); j++) {
            switch(input[j]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break;
                default:
                    v[i] |= 1 << (input[j] - 'a');
            }
        }
    }

    for (int i = 0; i < m; i++) {
        count = 0;
        cin >> o >> input;
        if (o == 1)
            cur &= ~(1 << (input[0] - 'a'));
        else
            cur |= 1 << (input[0] - 'a');
        
        for (int j = 0; j < n; j++)
            if ((cur & v[j]) == v[j])
                count++;
        cout << count << "\n";
    }
}