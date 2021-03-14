#include <iostream>

using namespace std;

int main() {
    int g, p, count = 0, tmp;
    int gi[100001], prev[100001] = {0,};

    cin >> g >> p;
    for (int i = 1; i <= g; i++)
        prev[i] = i;
    for (int i = 0; i < p; i++)
        cin >> gi[i];
    
    for (int i = 0; i < p; i++) {
        tmp = gi[i];

        while (tmp != prev[tmp])
            tmp = prev[tmp];
        
        if (tmp) {
            prev[tmp] = prev[gi[i]] = tmp - 1;
            count++;
        } else
            break;
    }

    cout << count;
}