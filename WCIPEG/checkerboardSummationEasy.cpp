#include <bits/stdc++.h>

#define MAXN 3002

using namespace std;

int white[MAXN][MAXN];
int black[MAXN][MAXN];

vector<string> tokens;

bool prefixed = false;

int main() {

    int M, N;

    scanf("%d %d\n", &M, &N);

    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            white[i][j] = 0;
            black[i][j] = 0;
        }
    }

    while (!cin.eof()) {
        tokens.clear();
        string in;
        getline(cin, in);
        stringstream ss(in);
        string token;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 3) {
            int r = stoi(tokens[0]);
            int c = stoi(tokens[1]);
            int x = stoi(tokens[2]);

            if (r == 0 && c == 0) {
                continue;
            }

            if (r % 2 == c % 2) {
                white[r][c] = x;
            } else {
                black[r][c] = x;
            }
        } else {
            if (!prefixed) {
                for (int i=0; i<=M; i++) {
                    for (int j=1; j<=N; j++) {
                        white[i][j] += white[i][j-1];
                        black[i][j] += black[i][j-1];
                    }
                }

                for (int i=0; i<=N; i++) {
                    for (int j=1; j<=M; j++) {
                        white[j][i] += white[j-1][i];
                        black[j][i] += black[j-1][i];
                    }
                }
                prefixed = true;
            }

            int r1 = stoi(tokens[0]);
            int c1 = stoi(tokens[1]);
            int r2 = stoi(tokens[2]);
            int c2 = stoi(tokens[3]);

            if (r1 == 0 && r2 == 0 && c1 == 0 && c2 == 0) {
                break;
            }

            long long sum = 0;

            int w = white[r2][c2] - white[r1-1][c2] - white[r2][c1-1] + white[r1-1][c1-1];
            int b = black[r2][c2] - black[r1-1][c2] - black[r2][c1-1] + black[r1-1][c1-1];

            if (r1 % 2 == c1 % 2) {
                sum += w;
                sum -= b;
            } else {
                sum += b;
                sum -= w;
            }

            cout << sum << endl;
        }
    }

    return 0;
}