#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> flowers;
vector<int> bad[301];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        flowers.push_back(make_pair(a, b));
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        bad[a - 1].push_back(b - 1);
        bad[b - 1].push_back(a - 1);
    }

    long long maxBeauty = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                long long beauty = 0;
                beauty += flowers[i].second;
                if (i != j && find(bad[i].begin(), bad[i].end(), j) == bad[i].end()) {
                    beauty *= flowers[j].first;
                    beauty += flowers[j].second;
                }
                if (i != k && k != j && find(bad[i].begin(), bad[i].end(), k) == bad[i].end() &&
                    find(bad[j].begin(), bad[j].end(), k) == bad[j].end()) {
                    beauty *= flowers[k].first;
                    beauty += flowers[k].second;
                }
                if (beauty > maxBeauty) {
                    maxBeauty = beauty;
                }
            }
        }
    }


    printf("%lld\n", maxBeauty);
}