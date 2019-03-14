#include <bits/stdc++.h>

using namespace std;

vector<bool> dna;

int main() {
    int _=10;
    while (_--) {
        string s1, s2;
        cin >> s1 >> s2;

        dna.clear();

        for (int i=0; i<s1.size(); i++) {
            if (s1[i] == 'A' || s1[i] == 'T') {
                dna.push_back(true);
            } else {
                dna.push_back(false);
            }
        }

        bool flip;
        int t = 2;
        bool found = false;
        while (t--) {
            if (found) {
                break;
            }
            if (t == 1) {
                flip = true;
            } else {
                flip = false;
            }
            for (int i = 0; i < 7; i++) {
                int front = i;
                int back = i + 7;
                vector<char> msg;
                bool good = true;
                while (back < dna.size()) {
                    int c = 0;
                    for (int j = 0; j < 8; j++) {
                        if (flip == dna[front + j]) {
                            c += pow(2, 7-j);
                        }
                    }
                    if ((c <= 'Z' && c >= 'A' ) || c == ' ') {
                        msg.push_back(c);
                    } else {
                        good = false;
                        break;
                    }
                    front += 8;
                    back += 8;
                }
                if (good) {
                    found = true;
                    for (int i=0; i<msg.size(); i++) {
                        printf("%c", msg[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

    }

    return 0;
}