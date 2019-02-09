#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K);
    long long buy = (N/(K+1))*K + N%(K+1);
    printf("%lld\n", buy);
    return 0;
}