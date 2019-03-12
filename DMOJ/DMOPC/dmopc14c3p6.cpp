#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> problems;
int dp[10001];

int main() {

    int N, T;

    scanf("%d%d", &N, &T);

    for (int i = 0; i < N; i++) {
        int pp, vp, pa, va, pg, vg;
        scanf("%d%d%d%d%d%d", &pp, &vp, &pa, &va, &pg, &vg);
        vector<pair<int, int>> customer;
        customer.push_back(make_pair(pg, vg));
        customer.push_back(make_pair(pa, va));
        customer.push_back(make_pair(pp, vp));
        problems.push_back(customer);
    }

    sort(problems.begin(), problems.end());
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < N; i++) {
        for (int k = T; k >= problems[i][2].first; k--) {
            for (int j = 0; j < 3; j++) {
                if (k >= problems[i][j].first ) {
                    if (dp[k] < dp[k - problems[i][j].first] + problems[i][j].second) {
                        dp[k] = dp[k - problems[i][j].first] + problems[i][j].second;
                    }
                }
            }
        }
    }

    printf("%d\n", dp[T]);
    return 0;
}