#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

class cmp {
public:
    bool operator()(pair<pair<int, int>, pair<int, int>> A, pair<pair<int, int>, pair<int, int>> B) {
        if (A.first.first == B.first.first) {
            return A.first.second > B.first.second;
        }
        return A.first.first > B.first.first;
    }
};

int R, C;
int graph[11][11];
int dis[11][11];
pair<int, int> start;
int dirs[4][2] = {{1,  0},
                  {-1, 0},
                  {0,  1},
                  {0,  -1}};
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, cmp> pq;

int main() {
    int tall = 0;
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'X') {
                start.first = i;
                start.second = j;
                graph[i][j] = 0;
            } else if (c == '.') {
                graph[i][j] = 0;
            } else {
                if (c - '0' > tall) {
                    tall = c - '0';
                }
                graph[i][j] = c - '0';
            }
        }
    }

    pq.push(make_pair(make_pair(0, 0), start));

    int minDis = INF;
    int minCut = INF;
    int minTrees = INF;
    memset(dis, INF, sizeof dis);

    dis[start.first][start.second] = 0;

    while (!pq.empty()) {
        pair<pair<int, int>, pair<int, int>> cur = pq.top();
        pq.pop();

        int newWeight = cur.first.first + graph[cur.second.first][cur.second.second];
        int newTrees = cur.first.second + (graph[cur.second.first][cur.second.second] == 0 ? 0 : 1);
        for (int i = 0; i < 4; i++) {
            int newY = cur.second.first + dirs[i][0];
            int newX = cur.second.second + dirs[i][1];

            if (newX >= 0 && newX < C && newY >= 0 && newY < R) {
                if (graph[newY][newX] == tall) {
                    if (pow(newY - start.first, 2) + pow(newX - start.second, 2) < minDis) {
                        minDis = pow(newY - start.first, 2) + pow(newX - start.second, 2);
                        minCut = newWeight;
                        minTrees = newTrees;
                    } else if (pow(newY - start.first, 2) + pow(newX - start.second, 2) == minDis) {
                        if (newWeight < minCut) {
                            minCut = newWeight;
                            minTrees = newTrees;
                        } else if (minCut == newWeight) {
                            if (newTrees < minTrees) {
                                minTrees = newTrees;
                            }
                        }
                    }
                }
                if (newWeight < dis[newY][newX]) {
                    dis[newY][newX] = newWeight;
                    pq.push(make_pair(make_pair(newWeight, newTrees), make_pair(newY, newX)));
                }
            }
        }
    }

    printf("%d\n", minTrees);
    return 0;
}