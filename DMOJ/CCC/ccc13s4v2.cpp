#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001

int N, M;
vector<int> graph[MAXN];
bool visited[MAXN];

bool bfs(int start, int end) {
    memset(visited, false, sizeof visited);
    queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        for (int child : graph[cur]) {
            if (child == end) {
                return true;
            }
            if (!visited[child]) {
                queue.push(child);
                visited[child] = true;
            }
        }
    }
    return false;
}

int main() {

    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[b].push_back(a);
    }

    int p, q;
    scanf("%d%d", &p, &q);
    if (bfs(p, q)) {
        printf("no");
    } else if (bfs(q, p)) {
        printf("yes");
    } else {
        printf("unknown");
    }

    return 0;
}