#include <bits/stdc++.h>

using namespace std;

int R, C, K;
bool cat[28][28];
int dp[28][28];

int main() {

    memset(cat, false, sizeof cat);
    memset(dp, 0, sizeof dp);

    scanf("%d%d", &R, &C);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d%d", &y, &x);
        cat[x][y] = true;
    }

    dp[1][1] = 1;
    cat[1][1] = true;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= R; j++) {
            if (!cat[i][j]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    printf("%d\n", dp[C][R]);

    return 0;
}