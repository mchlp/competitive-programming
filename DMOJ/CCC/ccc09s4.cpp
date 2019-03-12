#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int N, T, K, D;
vector<pair<int, int>> graph[5001];
int cost[5001];
int dis[5001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {

    scanf("%d", &N);
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    memset(cost, -1, sizeof cost);
    memset(dis, INF, sizeof dis);

    scanf("%d", &K);

    for (int i=0; i<K; i++) {
        int s, p;
        scanf("%d%d", &s, &p);
        cost[s] = p;
    }

    scanf("%d", &D);

    pq.push(make_pair(0, D));
    dis[D] = 0;
    int minCost = cost[D] == -1 ? INT_MAX : cost[D];

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for (int i=0; i<graph[cur.second].size(); i++) {
            int newDis = cur.first + graph[cur.second][i].second;
            if (newDis < dis[graph[cur.second][i].first]) {
                dis[graph[cur.second][i].first] = newDis;
                pq.push(make_pair(newDis, graph[cur.second][i].first));
            }
            if (cost[graph[cur.second][i].first] != -1) {
                if (newDis + cost[graph[cur.second][i].first] < minCost) {
                    minCost = newDis + cost[graph[cur.second][i].first];
                }
            }
        }
    }

    printf("%d\n", minCost);

    return 0;
}