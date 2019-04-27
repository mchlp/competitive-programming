#include <bits/stdc++.h>

using namespace std;

char grid[6][6];
unordered_set<string> words;
bool vis[6][6];

vector<pair<int, int>> dir = {{-1, -1},
                              {0,  -1},
                              {1,  -1},
                              {1,  0},
                              {1,  1},
                              {0,  1},
                              {-1, 1},
                              {-1, 0}};

bool dfs(int r, int c, string word, int index) {
    if (grid[r][c] != 0 && grid[r][c] == word[index]) {
        if (!vis[r][c]) {
            vis[r][c] = true;
            if (index == word.size() - 1) {
                return true;
            }
            bool found = false;
            for (pair<int, int> d : dir) {
                if (dfs(r + d.first, c + d.second, word, index + 1)) {
                    found = true;
                    break;
                }
            }
            vis[r][c] = false;
            return found;
        }
    }
    return false;
}

bool find(string word) {
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (grid[i][j] == word[0]) {
                memset(vis, false, sizeof vis);
                if (dfs(i, j, word, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {

    int _ = 5;
    while (_--) {
        memset(grid, 0, sizeof grid);
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                cin >> grid[i][j];
            }
        }

        words.clear();

        int score = 0;
        int numgood = 0;
        int numnfound = 0;
        int numshort = 0;
        int numrepeat = 0;

        int numwords;
        cin >> numwords;
        for (int i = 0; i < numwords; i++) {
            string word;
            cin >> word;

            if (word.length() < 3) {
                numshort++;
            } else if (words.count(word) > 0) {
                numrepeat++;
            } else if (!find(word)) {
                numnfound++;
            } else {
                numgood++;
                if (word.length() == 3 || word.length() == 4) {
                    score += 1;
                } else if (word.length() == 5) {
                    score += 2;
                } else if (word.length() == 6) {
                    score += 3;
                } else if (word.length() == 7) {
                    score += 4;
                } else {
                    score += 11;
                }
            }
            words.insert(word);
        }

        printf("Your score: %d (%d good, %d not found, %d too short, %d repeated)\n", score, numgood, numnfound,
               numshort, numrepeat);
    }

    return 0;
}