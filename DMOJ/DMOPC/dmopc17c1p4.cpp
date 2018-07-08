#include<bits/stdc++.h>

using namespace std;

int g[5000];
int h[5000];
int q[5000];
int t[5000];

long long dp[5001][2];

int main() {

    int N, H;
    scanf("%d %d", &N, &H);

    for (int i = 0; i < N; i++) {
        int cg, ch, cq, ct;
        scanf("%d %d %d %d", &cg, &ch, &cq, &ct);
        g[i] = cg;
        h[i] = ch;
        q[i] = cq;
        t[i] = ct;
    }

    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            dp[j][0] = max(dp[j][1], dp[j][0]);
            long long c1 = 0;
            long long c2 = 0;
            if (h[i] <= j) {
                 c1 = dp[j - h[i]][0] + g[i];
            }
            if (h[i]+t[i] <= j) {
                c2 = dp[j - t[i]][1] + q[i];
            }

            dp[j][1] = max(c1, c2);
        }
    }

    printf("%lld", max(dp[H][0], dp[H][1]));

    return 0;
}