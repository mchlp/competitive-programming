#include <bits/stdc++.h>

using namespace std;

int B, Q;
pair<int, pair<int, int>> lights[501];
bool visited[501];

bool bfs(int start, int end) {
    memset(visited, false, sizeof visited);
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        int x = lights[cur].second.first;
        int y = lights[cur].second.second;
        int r = lights[cur].first;
        for (int i=1; i<=B; i++) {
            if (i != cur) {
                int lightX = lights[i].second.first;
                int lightY = lights[i].second.second;
                if (sqrt(pow(lightX - x, 2) + pow(lightY - y, 2)) <= r) {
                    if (i == end) {
                        return true;
                    } else if (!visited[i]) {
                        queue.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &B, &Q);

    for (int i = 1; i <= B; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        lights[i] = make_pair(r, make_pair(x, y));
    }

    for (int i=0; i<Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf(bfs(a, b) ? "YES\n" : "NO\n");
    }

    return 0;
}