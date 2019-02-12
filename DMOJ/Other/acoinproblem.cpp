#include <bits/stdc++.h>

using namespace std;

int N, V;
int coins[2001];
vector<pair<int, int>> queries[2001];
int dp[10001];
int answers[100001];

int main() {
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        coins[i + 1] = d;
    }
    for (int i = 0; i < V; i++) {
        int cost, limit;
        scanf("%d%d", &cost, &limit);
        queries[limit].emplace_back(make_pair(cost, i));
    }

    fill_n(dp, 10001, INT_MAX - 100);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {

        int coinValue = coins[i];
        for (int k = 1; k <= 10001; k++) {
            if (k >= coinValue) {
                dp[k] = min(dp[k], dp[k - coinValue] + 1);
            }
        }

        if (!queries[i].empty()) {
            for (int j = 0; j < queries[i].size(); j++) {
                answers[queries[i][j].second] = dp[queries[i][j].first] == INT_MAX - 100 ? -1 : dp[queries[i][j].first];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}