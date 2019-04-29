#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000002

long long rib[MAXN];

int main(){

    freopen("DATA31.txt", "r", stdin);

    int _=10;
    while (_--) {
        int N, M;
        memset(rib, 0, sizeof rib);
        scanf("%d%d\n", &N, &M);

        for (int i=MAXN/2; i<MAXN/2+N; i++) {
            rib[i] = 1;
        }

        for (int i=0; i<M; i++) {
            char c;
            int p;
            cin >> p >> c;
            p += (MAXN/2);
            p--;
            if (c == 'L') {
                int k=1;
                while (rib[p-k] > 0) {
                    rib[p+k-1] += rib[p-k];
                    rib[p-k] = 0;
                    k++;
                }
            } else {
                int k=1;
                while (rib[p+k] > 0) {
                    rib[p-k+1] += rib[p+k];
                    rib[p+k] = 0;
                    k++;
                }
            }
        }

        int len = 0;
        long long maxT = 0;
        for (int i=0; i<MAXN; i++) {
            if (rib[i] > 0) {
                len++;
                if (rib[i] > maxT) {
                    maxT = rib[i];
                }
            }
        }

        printf("%d %lld\n", len, maxT);
    }

    return 0;
}