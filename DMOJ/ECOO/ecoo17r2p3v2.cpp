#include <bits/stdc++.h>

using namespace std;

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int N, M, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> ratings;

int main() {
    for (int _ = 0; _ < 10; _++) {
        ratings = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 0; i < N; i++) {
            int n;
            scanf("%d", &n);
            ratings.push(make_pair(n, i));
        }
        for (int i = 0; i < K - 1; i++) {
            pair<int, int> top = ratings.top();
            ratings.pop();
            ratings.push(make_pair(top.first - M, top.second));
        }
        printf("%d\n", ratings.top().second + 1);
    }
    return 0;
}