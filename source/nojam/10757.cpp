#include <iostream>
#include <string>
#include <vector>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define cut 1000000000000000000ULL

typedef unsigned long long ull;

using namespace std;

ull atoi(string s) {
    ull res = 0;

    for (int i = 0; i < s.length(); i++) {
        res *= 10;
        res += s[i] - '0';
    }

    return res;
}

int main() {
    vector<ull> a, b;
    int len_a, len_b;
    string s_a, s_b;
    ull tmp;
    int flag = 1;

    cin >> s_a >> s_b;

    while (s_a.length() > 18) {
        a.push_back(atoi(s_a.substr(s_a.length() - 18)));
        s_a = s_a.substr(0, s_a.length() - 18);
    }
    a.push_back(atoi(s_a));

    while (s_b.length() > 18) {
        b.push_back(atoi(s_b.substr(s_b.length() - 18)));
        s_b = s_b.substr(0, s_b.length() - 18);
    }
    b.push_back(atoi(s_b));

    len_a = a.size();
    len_b = b.size();

    if (len_a > len_b) {
        for (int i = 0; i < len_b; i++)
            a[i] += b[i];

        for (int i = 0; i < len_a; i++) {
            if (a[i] >= cut) {
                a[i] -= cut;
                if (i == len_a - 1) {
                    a.push_back(1ULL);
                    len_a++;
                }
                else
                    a[i + 1]++;
            }
        }

        for (int i = len_a - 1; i >= 0; i--) {
            if (flag) {
                cout << a[i];
                flag = 0;
            } else
                cout << to_string(a[i] + cut).substr(1);
        }
    } else {
        for (int i = 0; i < len_a; i++)
            b[i] += a[i];

        for (int i = 0; i < len_b; i++) {
            if (b[i] >= cut) {
                b[i] -= cut;
                if (i == len_b - 1) {
                    b.push_back(1ULL);
                    len_b++;
                }
                else
                    b[i + 1]++;
            }
        }

        for (int i = len_b - 1; i >= 0; i--) {
            if (flag) {
                cout << b[i];
                flag = 0;
            } else
                cout << to_string(b[i] + cut).substr(1);
        }
    }
}