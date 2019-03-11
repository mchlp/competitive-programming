#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int N, X, Q;
vector<pair<int, int>> countries;
int dis[1000001];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        countries.push_back(make_pair(x, y));
    }

    scanf("%d", &X);
    X--;

    memset(dis, INF, sizeof dis);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, X));
    dis[X] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (cur.first <= dis[cur.second]) {
            for (int i = 0; i < N; i++) {
                if (i != cur.first) {
                    int nextDis = cur.first + pow(countries[cur.second].first - countries[i].first, 2) +
                                  pow(countries[cur.second].second - countries[i].second, 2);
                    if (nextDis < dis[i]) {
                        dis[i] = nextDis;
                        pq.push(make_pair(nextDis, i));
                    }
                }
            }
        }
    }

    sort(dis, dis + 1000001);
    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        int x;
        scanf("%d", &x);
        if (x < dis[1]) {
            printf("1\n");
            continue;
        }
        int top = N;
        int bottom = 0;
        int middle;
        while (top - bottom > 1) {
            middle = (top + bottom)/2;
            if (dis[middle] > x) {
                top = middle;
            } else if (dis[middle] < x) {
                bottom = middle;
            } else {
                break;
            }
        }
        printf("%d\n", middle+1);
    }
}