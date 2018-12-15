#include<bits/stdc++.h>

using namespace std;

int dp[1002][10002];
int N, C;

int main() {
    scanf("%d %d", &N, &C);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            long long newVal;

            if (i == 0) {
                newVal = 0;
            } else {
                if (i == 1) {
                    if (j == 0) {
                        newVal = 1;
                    } else {
                        newVal = 0;
                    }
                } else {
                    newVal = dp[i][j - 1];
                    newVal %= 1000000007;
                    newVal += + dp[i - 1][j];
                    newVal %= 1000000007;
                    if (j >= i) {
                        newVal -= dp[i - 1][j - i];
                        newVal += 1000000007;
                        newVal %= 1000000007;
                    }
                }
            }
            newVal %= 1000000007;
            dp[i][j] = newVal;
        }
    }
    printf("%d", dp[N][C]);

    return 0;
}