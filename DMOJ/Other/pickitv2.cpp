#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
int dp[210][201];
vector<int> remain[201][201];

int main() {
    while (true) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        nums.clear();
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            nums.push_back(x);
        }

        for (int i=0; i<201; i++) {
            for (int j=0; j<201; j++) {
                dp[i][j] = 0;
                remain[i][j].clear();
            }
        }

        for (int i=0; i<N-2; i++) {
            dp[3][i] = nums[i] + nums[i+1] + nums[i+2];
            remain[3][i] = nums;
            remain[3][1].erase(remain[3][1].begin() + i + 1);
        }
        for (int i=4; i<=N; i++) {
            for (int j=0; j<N-i+1; j++) {
                int maxBefore = 0;
                int maxIndex = 0;
                for (int k=j; k<j+4; k++) {
                    if (maxBefore < dp[i-1][k]) {
                        maxBefore = dp[i-1][k];
                        maxIndex = k+1;
                    }
                }

            }
        }

    }
    return 0;
}