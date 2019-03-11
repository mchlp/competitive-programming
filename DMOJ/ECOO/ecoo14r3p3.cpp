#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[1001][1001];
int dis[1001][1001];
int directions[4][2] = {{-1, 0},
                        {1,  0},
                        {0,  1},
                        {0,  -1}};

int main() {

    for (int _ = 0; _ < 10; _++) {
        int H, V;
        scanf("%d%d", &H, &V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < H; j++) {
                graph[i][j].clear();
                dis[i][j] = -1;
            }
        }
        int sh, sv, fh, fv;
        scanf("%d%d", &sh, &sv);
        scanf("%d%d", &fh, &fv);

        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int th, tv, uh, uv;
            scanf("%d%d%d%d", &th, &tv, &uh, &uv);
            graph[tv][th].push_back(make_pair(uv, uh));
            graph[uv][uh].push_back(make_pair(tv, th));
        }

        deque<pair<int, int>> deque;
        deque.push_back(make_pair(sv, sh));

        while (!deque.empty()) {
            pair<int, int> cur = deque.front();
            deque.pop_front();
            if (cur.first == fv && cur.second == fh) {
                printf("%d\n", dis[cur.first][cur.second] + 1);
                break;
            } else {
                for (int i = 0; i < 4; i++) {
                    int newV = cur.first + directions[i][0];
                    int newH = cur.second + directions[i][1];
                    if (dis[newV][newH] == -1) {
                        deque.push_back(make_pair(newV, newH));
                        dis[newV][newH] = dis[cur.first][cur.second] + 1;
                    }
                }
                if (graph[cur.first][cur.second].size() > 0) {
                    for (int i = 0; i < graph[cur.first][cur.second].size(); i++) {
                        if (dis[graph[cur.first][cur.second][i].first][graph[cur.first][cur.second][i].second] == -1) {
                            deque.push_front(make_pair(graph[cur.first][cur.second][i].first,
                                                       graph[cur.first][cur.second][i].second));
                            dis[graph[cur.first][cur.second][i].first][graph[cur.first][cur.second][i].second] = dis[cur.first][cur.second];
                        }
                    }
                }
            }
        }
    }
    return 0;
}