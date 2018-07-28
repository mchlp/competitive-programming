#include<bits/stdc++.h>

using namespace std;

#define MAXN 21

int N, M, K;
int costs[MAXN][MAXN];

int main() {

    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            costs[i][j] = -1;
        }
    }

    scanf("%d %d %d", &N, &M, &K);

    for (int i=0; i<M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        costs[a][b] = c;
        costs[b][a] = c;
    }


    return 0;
}