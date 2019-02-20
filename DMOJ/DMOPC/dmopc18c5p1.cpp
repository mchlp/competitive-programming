#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool nbin[35];
bool mbin[35];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    memset(nbin, false, sizeof nbin);
    memset(mbin, false, sizeof mbin);
    for (int i=0; i<35; i++) {
        if (N % 2 == 1) {
            nbin[i] = true;
        }
        N /= 2;
        if (N == 0) {
            break;
        }
    }

    for (int i=0; i<35; i++) {
        if (M % 2 == 1) {
            mbin[i] = true;
        }
        M /= 2;
        if (M == 0) {
            break;
        }
    }

    int blue = 0;
    int purple = 0;
    for (int i=0; i<K; i++) {
        if ((mbin[i] || nbin[i]) && !(mbin[i] && nbin[i])) {
            blue++;
        } else {
            purple++;
        }
    }

    printf("%d %d\n", blue, purple);

}