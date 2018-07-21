#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> comp[6];
int dp[3001];
bool add[6];

int main() {

    memset(dp, 0, sizeof dp);

    int T, N, B;

    scanf("%d", &T);
    scanf("%d", &N);

    while (N--) {
        int c, v, t;
        scanf("%d %d %d", &c, &v, &t);

        pair<int, int> p;
        p.first = c;
        p.second = v;
        comp[t].push_back(p);
    }

    scanf("%d", &B);

    for (int i = 1; i <= T; i++) {
        for (int j = B; j >= 0; j--) {
            for (int k = 0; k < comp[i].size(); k++) {
                if (j - comp[i][k].first >= 0) {
                    if (dp[j - comp[i][k].first] + comp[i][k].second > dp[j]) {
                        dp[j] = dp[j - comp[i][k].first] + comp[i][k].second;
                        add[i] = true;
                    }
                    if (i == 0 && j == 0 ) {
                        dp[comp[i][k].first] = dp[comp[i][k].second];
                        add[i] = true;
                    }
                }
            }
        }
    }

    bool good = true;
    for (int i = 1; i <= T; i++) {
        if (!add[i]) {
            good = false;
            break;
        }
    }

    if (!good) {
        printf("-1\n");
    } else {
        int ans = 0;
        for (int i = 0; i <= B; i++) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }


    return 0;
}