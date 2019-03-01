#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005

int N, M, D;
bool edge[MAXN][MAXN];
double graph[MAXN][MAXN];
double dis[MAXN];

int main() {
    for (int _ = 0; _ < 10; _++) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                graph[i][j] = -1;
                edge[i][j] = false;
            }
            dis[i] = -INFINITY;
        }
        scanf("%d%d%d", &N, &M, &D);
        for (int i = 0; i < M; i++) {
            int a, b;
            double n;
            scanf("%d%d%lf", &a, &b, &n);
            if (graph[a][b] < log10(n)) {
                graph[a][b] = log10(n);
                edge[a][b] = true;
            }
        }
        stack<pair<int, double>> stack;
        stack.push(make_pair(1, log10(D)));
        dis[1] = log10(D);

        bool rich = false;

        while (!stack.empty()) {
            pair<int, double> cur = stack.top();
            stack.pop();
            if (rich) {
                break;
            }
            for (int i = 1; i <= N; i++) {
                if (edge[cur.first][i]) {
                    double newMoney = cur.second - graph[cur.first][i];
                    if (dis[i] <= newMoney) {
                        stack.push(make_pair(i, newMoney));
                        dis[i] = newMoney;
                    }
                    if (i == N && newMoney >= 9) {
                        rich = true;
                        break;
                    }
                }
            }
        }
        if (dis[N] >= 9) {
            printf("Billionaire!\n");
        } else {
            printf("%.2lf\n", pow(10, dis[N]));
        }
    }
    return 0;
}