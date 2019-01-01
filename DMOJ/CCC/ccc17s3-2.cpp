#include<bits/stdc++.h>

using namespace std;

int wood[2001];
int res[4002];

int main() {

    memset(wood, 0, sizeof wood);
    memset(res, 0, sizeof res);

    int N, l;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &l);
        wood[l]++;
    }

    for (int i=1; i<=2000; i++) {
        for (int j=i; j<=2000; j++) {
            if (i == j) {
                if (wood[i]) {
                    res[i + j] += wood[i] / 2;
                }
            } else {
                if (wood[i] && wood[j]) {
                    res[i + j] += min(wood[i], wood[j]);
                }
            }
        }
    }

    int curMaxHeight=0;
    int curMaxLength = INT_MIN;
    for (int i=4002; i>0; i--) {
        if (res[i] > curMaxLength) {
            curMaxLength = res[i];
            curMaxHeight=1;
        } else if (res[i] == curMaxLength) {
            curMaxHeight++;
        }
    }

    printf("%d %d\n", curMaxLength, curMaxHeight);
    return 0;
}