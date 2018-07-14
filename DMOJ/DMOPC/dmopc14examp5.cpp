#include<bits/stdc++.h>

using namespace std;

int teachers[51][1001][2];

int dp[1001][2];


int main() {

    int N, S;
    scanf("%d", &N);

    for (int i = 0; i < 1001; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i < N; i++) {
        int h, e, p;
        scanf("%d %d %d", &h, &e, &p);

        int ht=0;
        int t=0;

        for (int j=0; j<1001; j++) {
            if (j % p == 0 && j > 0) {
                t++;
                ht += h;
                h -= e;
                h  = h < 0 ? 0 : h;
            }
            teachers[i][j][0] = ht;
            teachers[i][j][1] = t;
        }
    }
    scanf("%d", &S);

    for (int i = 0; i < N; i++) {
        for (int j = S; j >= 0; j--) {
            for (int k=0; k <= j; k++) {
                if (dp[j][0] < dp[j-k][0] + teachers[i][k][0]) {
                    dp[j][0] = dp[j-k][0] + teachers[i][k][0];
                    dp[j][1] = dp[j-k][1] + teachers[i][k][1];
                } else if (dp[j][0] == dp[j-k][0] + teachers[i][k][0]) {
                    dp[j][1] = min(dp[j][1], dp[j-k][1] + teachers[i][k][1]);
                }
            }
        }
    }

    printf("%d\n%d", dp[S][0], dp[S][1]);

    return 0;
}