#include<bits/stdc++.h>

using namespace std;

int N, S;
int dp[1<<11][16];
int m[11];

int main() {
    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++) {
        scanf("%d", &m[i]);
        for (int j = 0; j <= S; j++) {
            // base case: only sparklers
            dp[1 << i][j] = (m[i] + j) * (m[i] + j) + j;
        }
    }

    int limit = 1 << N;
    for (int mask1 = 1; mask1 < limit; mask1++) {
        for (int mask2 = 1; mask2 < limit; mask2++) {
            if (mask1 & mask2) {
                continue;
            }
            int mask = mask1 | mask2;
            for (int i=0; i<N; i++) {
                if (mask & (1 << i)) {
                    continue;
                }
                int box = mask | (1<<i);
                for (int p=0; p<=S; p++) {
                    for (int q=0; q<=S-p; q++) {
                        for (int r = 0; r <= S - p - q; r++) {
                            dp[box][p+q+r] = max(dp[box][p + q + r], min(dp[mask1][p] * dp[mask2][q],
                                                                                         (m[i] + r) * (m[i] + r)) + r);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1<<N)-1][S]);
}