#include <bits/stdc++.h>

using namespace std;

char words[31][31];
bool marked[31][31];
int R, C, M;
vector<string> clues;


int main() {

    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        memset(marked, false, sizeof marked);
        for (int j = 0; j < C; j++) {
            char c;
            scanf(" %c", &c);
            words[i][j] = c;
        }
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
        clues.push_back(s);
    }

    for (string clue : clues) {
        bool nextWord = false;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                int tries = 2;
                while (tries--) {
                    // across
                    bool good = true;
                    for (int k = 0; k < clue.size(); k++) {
                        if (i + k > C - 1) {
                            good = false;
                            break;
                        }
                        if (clue[i + k] != words[i + k][j]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        for (int k = 0; k < clue.size(); k++) {
                            marked[i + k][j] = true;
                        }
                        nextWord = true;
                    }

                    // vertical
                    good = true;
                    for (int k = 0; k < clue.size(); k++) {
                        if (j + k > R - 1) {
                            good = false;
                            break;
                        }
                        if (clue[j + k] != words[i][j + k]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        for (int k = 0; k < clue.size(); k++) {
                            marked[i][j + k] = true;
                        }
                        nextWord = true;
                    }

                    // diagonal 1
                    good = true;
                    for (int k = 0; k < clue.size(); k++) {
                        if (j + k > R - 1 || i + k > C - 1) {
                            good = false;
                            break;
                        }
                        if (clue[j + k] != words[i + k][j + k]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        for (int k = 0; k < clue.size(); k++) {
                            marked[i + k][j + k] = true;
                        }
                        nextWord = true;
                    }

                    // diagonal 2
                    good = true;
                    for (int k = 0; k < clue.size(); k++) {
                        if (j + k > R - 1 || i - k < 0) {
                            good = false;
                            break;
                        }
                        if (clue[j + k] != words[i - k][j + k]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        for (int k = 0; k < clue.size(); k++) {
                            marked[i - k][j + k] = true;
                        }
                        nextWord = true;
                    }

                    reverse(clue.begin(), clue.end());
                }
            }
            if (nextWord) {
                break;
            }
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (!marked[i][j]) {
                printf("%c", words[i][j]);
            }
        }
    }
    return 0;
}