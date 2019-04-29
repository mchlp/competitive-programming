#include <bits/stdc++.h>

using namespace std;

int events[1001];

int main() {
    int _ = 10;
    while (_--) {
        memset(events, 0, sizeof events);
        int N, M, D;
        scanf("%d%d%d", &N, &M, &D);
        int clean = N;
        int total = N;
        for (int i = 0; i < M; i++) {
            int x;
            scanf("%d", &x);
            events[x-1]++;
        }

        int laun = 0;
        for (int i=0; i<D; i++) {
            if (clean == 0) {
                clean = total;
                laun++;
            }
            clean--;
            clean += events[i];
            total += events[i];
        }
        printf("%d\n", laun);
    }
}