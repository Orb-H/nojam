#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    map<string, string> pw;
    string site, password;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> site >> password;
        pw.insert(make_pair(site, password));
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << pw[site] << "\n";
    }
}