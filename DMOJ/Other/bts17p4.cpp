#include<bits/stdc++.h>

using namespace std;

#define MAXN 100001

int mud[MAXN];
int N, M, J;

bool check(int time) {
    int curJump = J;
    for (int i=1; i<=N; i++) {
        if (mud[i] != -1 && mud[i] <= time) {
            curJump = J;
        } else {
            curJump--;
            if (curJump <= 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    for (int i=0; i<MAXN; i++) {
        mud[i] = -1;
    }

    scanf("%d %d %d", &N, &M, &J);

    while (M--) {
        int p, t;
        scanf("%d %d", &p, &t);
        mud[p] = t;
    }

    int top = 1000000;
    int bottom = 0;
    int mid = 1;
    int oldMid = -1;

    while (oldMid != mid) {
        oldMid = mid;
        mid = (top+bottom)/2;
        if (check(mid)) {
            top = mid;
        } else {
            bottom = mid+1;
        }
    }

    if (mid == 1000000) {
        printf("-1\n");
    } else {
        printf("%d\n", mid);
    }

    return 0;
}