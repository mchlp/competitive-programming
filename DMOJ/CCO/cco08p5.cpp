// TODO: WIP

#include<bits/stdc++.h>

using namespace std;

#define MAXN 101

int candy[201];

int dp[]

int main() {

    memset(candy, 0, sizeof candy);

    int N;
    int tCal = 0;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int K, C;
        scanf("%d %d", &K, &C);
        candy[c] += K;
        tCal += C * K;
    }

    int target = tCal/2;

    return 0;
}