#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];
bool start[10001];


int main() {

    memset(start, true, sizeof start);

    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        start[b] = false;
    }

    memset(visited, false, sizeof visited);
    queue<int> queue;
    for (int i = 1; i <= N; i++) {
        if (start[i]) {
            queue.push(i);
            visited[i] = true;
        }
        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            for (int &j : graph[cur]) {
                if (!visited[j]) {
                    visited[i] = true;
                    queue.push(j);
                }
            }
        }
    }
    printf("Y\n");
    return 0;
}