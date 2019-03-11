#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000005

int N;
int pos[MAXN];
int total;


int main() {

    memset(pos, -1, sizeof pos);
    scanf("%d", &N);
    pos[0] = 0;
    total = 0;
    for (int i=1; i<=N; i++) {
        int k, c;
        scanf("%d%d", &k, &c);
        total += k*c;
        for (int j=0; j<MAXN; j++) {
            if (pos[j] != -1 && pos[j] < i) {
                for (int m = 1; m <= k; m++) {
                    if (j + m * c < MAXN && pos[j + m * c] == -1) {
                        pos[j + m * c] = i;
                    }
                }
            }
        }
    }

    for (int i=total/2; i>=0; i--) {
        if (pos[i] != -1) {
            printf("%d\n", (total-i) - i);
            break;
        }
    }

    return 0;
}