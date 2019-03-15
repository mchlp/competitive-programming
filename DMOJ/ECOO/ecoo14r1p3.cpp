#include <bits/stdc++.h>

using namespace std;

char words[31][31];
bool marked[31][31];
int R, C, M;
vector<string> clues;
vector<string> notfound;


int main() {

    int _ = 5;
    while (_--) {
        clues.clear();
        notfound.clear();
        memset(marked, false, sizeof marked);

        scanf("%d%d", &R, &C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char c;
                scanf(" %c", &c);
                words[j][i] = c;
            }
        }

        scanf("%d\n", &M);
        for (int i = 0; i < M; i++) {
            string s;
            getline(cin, s);
            s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); }), s.end());
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
                            if (clue[k] != words[i + k][j]) {
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
                            if (clue[k] != words[i][j + k]) {
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
                            if (clue[k] != words[i + k][j + k]) {
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
                            if (clue[k] != words[i - k][j + k]) {
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
            if (!nextWord) {
                notfound.push_back(clue);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!marked[j][i]) {
                    printf("%c", words[j][i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}