#include<bits/stdc++.h>

#define MAXN 245701

bool dp[MAXN];

int main() {

    memset(dp, false, sizeof dp);
    dp[0] = true;
    int N, s;
    int sm = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &s);
        sm += s;
        for (int j = MAXN; j > 0; j--) {
            if (j >= s) {
                dp[j] = dp[j] || (dp[j - s]); // check
            }
        }
    }

    int target = sm / 2;
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            printf("%d\n", abs(i-(sm-i)));
            return 0;
        }
    }

    return 0;
}