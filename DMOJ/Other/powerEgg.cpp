#include<bits/stdc++.h>

using namespace std;

#define MAXN 33

// eggs, drops
long dp[MAXN][MAXN];

int main() {

    int T;
    scanf("%d", &T);

    for (int i=0; i<MAXN; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i=1; i<MAXN; i++) {
        for (int j=1; j<MAXN; j++) {
            dp[i][j] = 1 + dp[i-1][j-1] + dp[i][j-1];
        }
    }

    while (T--) {

        int N, K;
        scanf("%d %d", &N, &K);

        if (dp[K][MAXN-1] < N) {
            printf("Impossible\n");
        } else {
            for (int i = 0; i < MAXN; i++) {
                if (dp[K][i] >= N) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }

    return 0;
}