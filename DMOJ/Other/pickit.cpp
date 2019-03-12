#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
map<vector<int>, int> dp;

int getScore(vector<int> search) {
    if (dp.count(search) == 0) {
        int maxScore = 0;
        for (int i = 1; i < search.size() - 1; i++) {
            vector<int> testVector = search;
            testVector.erase(testVector.begin() + i);
            maxScore = max(maxScore, getScore(testVector) + search[i - 1] + search[i] + search[i + 1]);
        }
        dp[search] = maxScore;
    }
    return dp[search];
}

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
        printf("%d\n", getScore(nums));
    }
    return 0;
}