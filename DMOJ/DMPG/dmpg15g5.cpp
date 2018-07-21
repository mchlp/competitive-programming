// TODO: WIP

#include <bits/stdc++.h>

using namespace std;
long long dp[2002];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> pq;
vector<pair<long long, long long>> pairs;

int main() {

    memset(dp, 0, sizeof dp);

    long long zeroCount = 0;

    long long N, R;
    scanf("%lld %lld", &N, &R);

    while (N--) {
        long long E, C, V, CA, CB, CM, VA, VB, VM;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &E, &C, &V, &CA, &CB, &CM, &VA, &VB, &VM);

        while (E--) {

            if (C <= R && V > 0) {
                pair<long long, long long> pair;
                pair.first = C;
                pair.second = V;
                pq.push(pair);

                C = ((C * CA) + CB) % CM;
                V = ((V * VA) + VB) % VM;
            }
        }

        while (!pq.empty()) {
            if (pq.top().first != 0) {
                pairs.push_back(pq.top());
            } else {
                zeroCount += pq.top().second;
            }
            pq.pop();
        }

        while (!pairs.empty()) {
            for (int j=R; j >= pairs.back().first; j--) {
                dp[j] = max(dp[j], dp[j-pairs.back().first] + pairs.back().second);
            }
            pairs.pop_back();
        }
    }

    printf("%lld\n", dp[R] + zeroCount);

    return 0;
}