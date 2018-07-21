// TODO: WIP

#include<bits/stdc++.h>

using namespace std;

#define MAXN 50000
#define MAXC 201

int candy[MAXC];

int dp[MAXC][MAXN];

int main() {

    memset(candy, 0, sizeof candy);

    int N;
    int tCal = 0;
    int maxC = 0;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int K, C;
        scanf("%d %d", &K, &C);
        candy[C] += K;
        tCal += C * K;
        maxC = max(C, maxC);
    }

    int target = tCal/2;

    for (int i=0; i<MAXN; i++) {
        dp[0][i] = target;
    }

    for (int i=1; i<=maxC; i++) {
        if (candy[i] > 0) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= min(candy[i], j); k++) {
                    if (dp[i-1][j - k] - (i * k) >= 0) {
                        dp[i][j] = min(dp[i-1][j],(dp[i-1][j - k] - (i * k)));
                    }
                }
            }
        } else {
            for (int j=0; j<= target; j++) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("%d\n", dp[maxC][target]*2);

    return 0;
}