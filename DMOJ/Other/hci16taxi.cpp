#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100001];
long long dis[100001];

long long bfs(int start, int end) {
    memset(dis, -1, sizeof dis);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push(make_pair(0, start));
    dis[start] = 0;

    while (!queue.empty()) {
        pair<int, int>cur = queue.top();
        queue.pop();

        if (cur.second == end) {
            return dis[cur.second];
        } else {
            for (int i=0; i<graph[cur.second].size(); i++) {
                pair<int, int> next = graph[cur.second][i];
                if (dis[next.first] == -1 || dis[next.first] > dis[cur.second] + next.second) {
                    queue.push(make_pair(dis[cur.second] + next.second, next.first));
                    dis[next.first] = dis[cur.second] + next.second;
                }
            }
        }
    }
    return -1;
}

int main() {

    int V, E, P, D, R;
    scanf("%d%d%d%d%d", &V, &E, &P, &D, &R);

    for (int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    long long tof = bfs(P, D);
    long long toh = bfs(D, R);

    long long fcost = tof > 0 ? 3 : 0;
    if (tof <= 10) {
        fcost += 2*tof;
    } else {
        fcost += (2*10) + (tof-10);
    }

    if (toh > 0) {
        long long leftover = 10 - tof < 0 ? 0 : 10 - tof;

        if (leftover == 10) {
            fcost += 3;
        }

        if (toh <= leftover) {
            fcost += 2 * toh;
        } else {
            fcost += 2 * leftover + (toh - leftover);
        }
    }

    if (tof == -1) {
        printf("Nooooooooo!!!\n");
    } else if (tof > 0 && toh == -1) {
        printf("%lld\nYippee!!!\n", fcost);
    } else {
        printf("%lld\n", fcost);
    }

    return 0;
}