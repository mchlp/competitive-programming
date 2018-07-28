#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[10001];
bool vis[10001];
long long paths = 0;

int main() {
    scanf("%d %d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }

    deque<int> dq;
    dq.push_front(1);
    int dest = 2;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == dest) {
            paths++;
        } else {
            if (vis[cur]) {
                printf("inf\n");
                return 0;
            }
            vis[cur] = true;
            for (int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur][i];
                if (!vis[next]) {
                    dq.push_front(next);
                }
            }
        }

    }

    printf("%lld\n", paths);

    return 0;
}