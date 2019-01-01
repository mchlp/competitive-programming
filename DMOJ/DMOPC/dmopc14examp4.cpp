#include <bits/stdc++.h>

using namespace std;

double graph[1001][1001];
double red[1001][1001];
pair<double, int> dist[1001];
double redSpeed[1001];
int V, E;


int main() {

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            graph[i][j] = -1;
        }
    }

    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int m, n, d, s;
        scanf("%d %d %d %d", &m, &n, &d, &s);
        if (graph[m][n] == -1 || graph[m][n] > (double) d / s) {
            graph[m][n] = (double) d / s;
            graph[n][m] = (double) d / s;
            red[m][n] = (double) d / (s * 0.75);
            red[n][m] = (double) d / (s * 0.75);
        }
    }

    for (int i = 0; i <= V; i++) {
        dist[i] = {DBL_MAX, INT_MAX};
    }

    deque<int> queue;
    queue.push_back(1);
    dist[1] = {0.0, 0};

    while (!queue.empty()) {
        int curNode = queue.front();
        queue.pop_front();
        for (int i = 0; i <= V; i++) {
            if (graph[curNode][i] >= 0) {
                if (dist[i].first > dist[curNode].first + graph[curNode][i] ||
                    (dist[i].first == dist[curNode].first + graph[curNode][i] &&
                     dist[i].second > dist[curNode].second + 1)) {
                    dist[i] = {dist[curNode].first + graph[curNode][i], dist[curNode].second + 1};
                    redSpeed[i] = redSpeed[curNode] + red[curNode][i];
                    queue.push_back(i);
                }
            }
        }
    }

    printf("%d\n%d", dist[V].second, (int) round((redSpeed[V] - dist[V].first) * 60));

    return 0;
}