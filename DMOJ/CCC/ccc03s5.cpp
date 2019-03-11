#include <bits/stdc++.h>

#define MAXDIS 100005

using namespace std;

int c, r, d;
vector<pair<int, int>> graph[10001];
int dis[10001];

int main() {

    scanf("%d%d%d", &c, &r, &d);

    for (int i=0; i<r; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);

        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(100000, 1));
    for (int i=0; i<10001; i++) {
        dis[i] = MAXDIS;
    }

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (cur.second == 1 || dis[cur.second] == MAXDIS || dis[cur.second] < cur.first) {
            dis[cur.second] = cur.first;
            for (int i=0; i<graph[cur.second].size(); i++) {
                if (graph[cur.second][i].first != 1) {
                    if (dis[graph[cur.second][i].first] == MAXDIS || dis[graph[cur.second][i].first] < min(cur.first, graph[cur.second][i].second)) {
                        pq.push(make_pair(min(cur.first, graph[cur.second][i].second), graph[cur.second][i].first));
                    }
                }
            }
        }
    }

    int minWeight = INT_MAX;
    for (int i=0; i<d; i++) {
        int x;
        scanf("%d", &x);
        if (dis[x] < minWeight) {
            minWeight = dis[x];
        }
    }
    printf("%d\n", minWeight);


    return 0;
}