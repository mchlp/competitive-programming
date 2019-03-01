#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005

int N, M, D;
long double graph[MAXN][MAXN];
long double dis[MAXN];

int main() {
    for (int _ = 0; _ < 10; _++) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                graph[i][j] = -1;
            }
            dis[i] = -1;
        }
        scanf("%d%d%d", &N, &M, &D);
        for (int i = 0; i < M; i++) {
            int a, b;
            long double n;
            scanf("%d%d%Lf", &a, &b, &n);
            if (graph[a][b] < n) {
                graph[a][b] = n;
            }
        }

        stack<pair<int, long double>> stack;
        stack.push(make_pair(1, D));
        dis[1] = D;

        while (!stack.empty()) {
            pair<int, long double> cur = stack.top();
            stack.pop();
            if (dis[cur.first] >= 1e9) {
                break;
            }
            for (int i = 1; i <= N; i++) {
                if (graph[cur.first][i] != -1) {
                    long double newMoney = cur.second / graph[cur.first][i];
                    if (dis[i] <= newMoney) {
                        stack.push(make_pair(i, newMoney));
                        dis[i] = newMoney;
                    }
                }
            }
        }
        if (dis[N] >= 1e9) {
            printf("Billionaire!\n");
        } else {
            printf("%.2Lf\n", dis[N] > 0 ?  dis[N] : 0);
        }
    }
    return 0;
}