#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    string explosion;
    int ex_size, in_size, pos = 0, j = 0;
    char res[1000001] = {0,};
    int match[1000001] = {0,};

    getline(cin, input);
    getline(cin, explosion);
    in_size = input.length();
    ex_size = explosion.length();

    for (int i = 0; i < in_size; i++, j++) {
        res[j] = input[i];

        if (input[i] == explosion[pos]) {
            match[j] = ++pos;
            if (pos == ex_size) {
                j -= ex_size;
                pos = match[j];
            }
        } else {
            match[j] = (pos = 0);
            if (input[i] == explosion[pos]) {
                match[j] = ++pos;
            }
        }
    }

    res[j] = 0;

    if (j == 0)
        cout << "FRULA";
    else
        cout << res;
}