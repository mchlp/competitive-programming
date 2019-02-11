#include <bits/stdc++.h>

using namespace std;

bool visited[7];
bool graph[7][7];
int N;
int numGraphs = 0;

void bfs(int start) {
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        for (int i = 0; i <= N; i++) {
            if (graph[cur][i]) {
                numGraphs++;
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}


int main() {

    fill(&visited[0], &visited[0] + sizeof visited, false);
    fill(&graph[0][0], &graph[0][0] + sizeof graph, false);

    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int p;
        scanf("%d", &p);
        graph[p][i] = true;
    }

    bfs(N);

    printf("%d\n", (numGraphs * (numGraphs-1))/2);

    return 0;
}