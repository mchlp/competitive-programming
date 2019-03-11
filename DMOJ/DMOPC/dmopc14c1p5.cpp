#include <bits/stdc++.h>

using namespace std;

int R, C, T, sx, sy, ox, oy;
bool tele[1001][1001];
bool graph[1001][1001];
int dis[1001][1001];
int directions[4][2] = {{1,  0},
                        {-1, 0},
                        {0,  -1},
                        {0,  1}};

int main() {

    scanf("%d%d", &R, &C);
    scanf("%d%d", &sy, &sx);
    scanf("%d%d ", &oy, &ox);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            scanf("%c ", &c);
            if (c == 'X') {
                graph[i][j] = false;
            } else {
                graph[i][j] = true;
            }
            tele[i][j] = false;
            dis[i][j] = -1;
        }
    }

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        tele[b][a] = true;
    }

    int disToOffice = INT_MAX;
    int disToTele = INT_MAX;

    queue<pair<int, int>> queue;
    queue.push(make_pair(sx, sy));
    dis[sy][sx] = 0;

    while (!queue.empty()) {
        pair<int, int> cur = queue.front();
        queue.pop();

        if (cur.first == ox && cur.second == oy) {
            if (disToOffice > dis[cur.second][cur.first]) {
                disToOffice = dis[cur.second][cur.first];
            }
        }

        if (tele[cur.first][cur.second]) {
            if (disToTele > dis[cur.second][cur.first]) {
                disToTele = dis[cur.second][cur.first];
            }
        }

        for (int i = 0; i < 4; i++) {
            int newX = cur.first + directions[i][0];
            int newY = cur.second + directions[i][1];

            if (newX >= 0 && newX < C && newY >= 0 && newY < R) {
                if (graph[newY][newX] && dis[newY][newX] == -1) {
                    dis[newY][newX] = dis[cur.second][cur.first] + 1;
                    queue.push(make_pair(newX, newY));
                }
            }
        }
    }

    printf("%d\n", (disToOffice - disToTele) > 0 ? (disToOffice - disToTele) : 0);

    return 0;
}