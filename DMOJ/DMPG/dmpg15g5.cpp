// TODO: WIP

#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;

int main() {

    // cost V-->1, V/2-->2, V/3-->3, 1-->V
    // to get top k values, use priority queue, size of PQ is K
    // 0-1 knapsack, not limited

    int N, R;
    scanf("%d %d", &N, &R);

    while (N--) {
        int E, C, V, CA, CB, CM, VA, VB, VM;
        scanf("%d %d %d %d %d %d %d %d %d", &E, &C, &V, &CA, &CB, &CM, &VA, &VB, &VM);
        while (E--) {
            // cost, value
            pair<int, int> pii;
            pii.first = C;
            pii.second = V;
            pq.push(pii);
            C = ((C*CA) + CB) % CM;
            V = ((V*VA) + VB) % VM;
        }
    }

    return 0;
}