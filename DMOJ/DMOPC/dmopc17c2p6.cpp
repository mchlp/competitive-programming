#include <bits/stdc++.h>

using namespace std;

int N, A[200001], B[200001], chans[200001];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i=0; i<N; i++) {
        scanf("%d", &B[i]);
    }

    for (int i=0; i<N; i++) {
        chans[i] = 1;
    }

    int k=0;
    int newMin = INT_MAX;
    for (int i=0; i<N; i++) {
        newMin = min(newMin, chans[i] == 1 ? A[i] : B[i]);
    }
    printf("%d\n", newMin);
    while (k<N) {
        int minNum = INT_MAX;
        int minChan = 0;
        int minTime = 0;
        int curChan = 1;
        for (int i=0; i<N; i++) {
            curChan = chans[i];
            int curVal = curChan == 1 ? A[i] : B[i];
            if (curVal < minNum) {
                minChan = curChan;
                minTime = i;
                minNum = curVal;
            }
        }

        if (minNum >= (minChan == 1 ? B[minTime] : A[minTime])) {
            while (k<N) {
                printf("%d\n", minNum);
                k++;
            }
            return 0;
        }

        if (chans[minTime] == minChan) {
            for (int i=minTime; i<N; i++) {
                chans[i] = chans[i] == 1 ? 2 : 1;
            }
            k++;
            int newMin = INT_MAX;
            for (int i=0; i<N; i++) {
                newMin = min(newMin, chans[i] == 1 ? A[i] : B[i]);
            }
            printf("%d\n", newMin);
        }
    }

    return 0;
}