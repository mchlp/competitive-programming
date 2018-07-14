#include<bits/stdc++.h>

using namespace std;

#define MAXN 101

int kArr[MAXN];
int cArr[MAXN];

int dp[500*MAXN];

int main() {

    int N;
    int candyCount = 0;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d %d", &kArr[i], &cArr[i]);
        candyCount += kArr[i];
    }

    for (int i=0; i<candyCount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i=0; i<N; i++) {
        for (int j=candyCount; j>=0; j--) {
            for (int k=1; k<=min(kArr[i], j); k++) {
                int newMin = 0;
                if (dp[j-k] >= cArr[i]*k) {
                    newMin = dp[j-k] - cArr[i]*k;
                } else {
                    newMin = (dp[j-k] - (dp[j-k]/cArr[i])*cArr[i]) + (k%2 * cArr[i]);
                }
                dp[j] = newMin;
            }
        }
    }

    return 0;
}