#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        string s;
        cin >> s;

        char firstChar = s[0];
        bool firstE = s[0] == 'E';
        string res = "";

        int numE = 0;
        int numS = 0;
        bool lastNotFirst = false;

        for (int j = 0; j < s.length(); j++) {

            char cur = s[j];
            if (cur == firstChar) {
                if (lastNotFirst) {
                    if (firstE) {
                        for (int k = 0; k < numS; k++) {
                            res += 'S';
                        }
                        for (int k = 0; k < numE; k++) {
                            res += 'E';
                        }
                        numE = 1;
                        numS = 0;
                    } else {
                        for (int k = 0; k < numE; k++) {
                            res += 'E';
                        }
                        for (int k = 0; k < numS; k++) {
                            res += 'S';
                        }
                        numE = 0;
                        numS = 1;
                    }
                } else {
                    if (firstE) {
                        numE++;
                    } else {
                        numS++;
                    }
                }
                lastNotFirst = false;
            } else {
                if (firstE) {
                    numS++;
                } else {
                    numE++;
                }
                lastNotFirst = true;
            }
        }

        if (firstE) {
            for (int k = 0; k < numS; k++) {
                res += 'S';
            }
            for (int k = 0; k < numE; k++) {
                res += 'E';
            }
        } else {
            for (int k = 0; k < numE; k++) {
                res += 'E';
            }
            for (int k = 0; k < numS; k++) {
                res += 'S';
            }
        }

        cout << res << "\n";
    }


    return 0;
}