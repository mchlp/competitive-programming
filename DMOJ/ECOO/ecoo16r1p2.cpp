#include <bits/stdc++.h>

using namespace std;

#define MAXT 1000002

int main() {
    int _ = 10;
    while (_--) {
        int N;
        scanf("%d", &N);
        set<int> checked;
        bool s1[MAXT];
        bool s2[MAXT];
        bool s3[MAXT];
        memset(s1, false, sizeof s1);
        memset(s2, false, sizeof s2);
        memset(s3, false, sizeof s3);
        for (int i = 0; i < N; i++) {
            int num;
            scanf("%d", &num);
            s1[num] = true;
        }

        for (int i = 0; i < MAXT; i++) {
            if (s1[i]) {
                int b = i;
                for (int j = 0; j < MAXT; j++) {
                    if (s1[j]) {
                        if (b * j <= MAXT) {
                            s2[b * j] = true;
                        }

                        if (b + j <= MAXT) {
                            s2[b + j] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < MAXT; i++) {
            if (s2[i] && !s1[i]) {
                int b = i;
                for (int j = 0; j < MAXT; j++) {
                    if (s1[j]) {
                        if (b * j <= MAXT) {
                            s3[b * j] = true;
                        }

                        if (b + j <= MAXT) {
                            s3[b + j] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            int tar;
            scanf("%d", &tar);
            printf("%c", s3[tar] ? 'T' : 'F');
        }
        printf("\n");
    }
}