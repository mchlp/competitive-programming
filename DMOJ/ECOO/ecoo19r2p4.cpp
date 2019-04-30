#include <bits/stdc++.h>

using namespace std;

long long dp[1000002];
int relief[1000002];
deque<pair<int, int>> q;

int main() {
    freopen("DATA41.txt", "r", stdin);
    int _ = 10;
    while (_--) {

        q.clear();
        int N;
        int R, S;
        scanf("%d%d%d", &N, &R, &S);

        for (int i = 1; i <= N; i++) {
            dp[i] = LONG_LONG_MAX;
            scanf("%d", &relief[i]);
        }

        dp[1] = (long long) relief[1] * (S + R);
        q.push_back({1, relief[1]});

        for (int i = 2; i <= N; i++) {
            while (!q.empty()) {
                pair<int, long long> check = q.back();

                int before = min(relief[i], relief[check.first]);
                int remain = max(0, relief[i] - relief[check.first]);

                dp[i] = min(dp[i],
                            dp[check.first] + (long long) before * R * (i - check.first) +
                            (long long) remain * (S + R));

                if (check.second <= relief[i]) {
                    q.pop_back();
                } else {
                    break;
                }
            }

            while (!q.empty() && relief[i] >= q.back().second) {
                q.pop_back();
            }

            q.push_back({i, relief[i]});
        }
        printf("%lld\n", dp[N]);
    }

    return 0;
}