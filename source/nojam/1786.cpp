#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string T, P;
    int fail[1000001];
    int loc, i;
    vector<int> found;

    getline(cin, T);
    getline(cin, P);

    fail[(i = 0)] = (loc = -1);
    while (i < P.length()) {
        if (loc == -1 || (loc >= 0 && P[loc] == P[i]))
            fail[++i] = ++loc;
        else
            loc = fail[loc];
    }

    loc = i = 0;
    while (i < T.length()) {
        if (loc == -1 || (loc >= 0 && T[i] == P[loc])) {
            if (++loc == P.length()) {
                found.push_back(i - P.length() + 2);
                loc = fail[loc];
            }
            i++;
        } else
            loc = fail[loc];
    }

    cout << found.size() << "\n";
    for (int i = 0; i < found.size(); i++)
        cout << found[i] << " ";
}