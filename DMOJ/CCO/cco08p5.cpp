// TODO: WIP

#include<bits/stdc++.h>

using namespace std;

#define MAXN 5000000
#define MAXC 201

int candy[MAXC];

int dp[MAXN];

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
        dp[i] = target;
    }

    for (int i=0; i<maxC; i++) {
        for (int j=target; j>=0; j--) {
            if (candy[i] > 0) {
                for (int k=1; k<=min(candy[i], j-1); k++) {
                    dp[j] = min(dp[j], ((dp[j-k] - candy[i]*k)+target)%target);
                }
            }
        }
    }

    printf("%d %d\n", dp[target], target);

    return 0;
}