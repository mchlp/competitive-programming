#include <bits/stdc++.h>

using namespace std;

int dis[1001];
vector<int> graph[1001];
int N, M, T, Q;
vector<pair<pair<int, int>, int>> queries;
int ans[200001];

int main() {

    scanf("%d%d%d", &N, &M, &T);
    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }

    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        queries.push_back(make_pair(make_pair(a, b), i));
    }

    sort(queries.begin(), queries.end());

    int prevStart = -1;
    for (int i=0; i<Q; i++) {
        pair<pair<int, int>, int> cur = queries.back();
        queries.pop_back();

        if (prevStart != cur.first.first) {
            memset(dis, -1, sizeof dis);
            queue<int> queue;
            queue.push(cur.first.first);
            dis[cur.first.first] = 0;

            while (!queue.empty()) {
                int curNode = queue.front();
                queue.pop();

                for (int j=0; j<graph[curNode].size(); j++) {
                    if (dis[graph[curNode][j]] == -1) {
                        dis[graph[curNode][j]] = dis[curNode] + T;
                        queue.push(graph[curNode][j]);
                    }
                }
            }
        }

        ans[cur.second] = dis[cur.first.second];
    }

    for (int i=0; i<Q; i++) {
        if (ans[i] == -1) {
            printf("Not enough hallways!\n");
        } else {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}