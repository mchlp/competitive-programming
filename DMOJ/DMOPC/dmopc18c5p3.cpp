#include <bits/stdc++.h>

using namespace std;

long long N, M;
long long arr[200001];

int main() {
    scanf("%lld%lld", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    long long len = 0;
    long long back = 0;
    long long runningSum = 0;
    long long maxLen = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] < M) {
            runningSum += arr[i];
            len++;
        } else {
            back = i+1;
            len = 0;
        }

        while (runningSum >= M) {
            runningSum -= arr[back];
            back++;
            len--;
        }

        if (len > maxLen) {
            maxLen = len;
        }
    }

    printf("%lld\n", maxLen);
}