#include <bits/stdc++.h>

using namespace std;

int N;
int sum1, sum2, k;
int run1[100001];
int run2[100001];

int main() {

    scanf("%d", &N);
    sum1 = 0;
    sum2 = 0;
    k = 0;

    for (int i=0; i<N; i++) {
        scanf("%d", &run1[i]);
    }


    for (int i=0; i<N; i++) {
        scanf("%d", &run2[i]);
    }

    for (int i=0; i<N; i++) {
        sum1 += run1[i];
        sum2 += run2[i];
        if (sum1 == sum2) {
            k = i+1;
        }
    }
    printf("%d\n", k);
    return 0;
}