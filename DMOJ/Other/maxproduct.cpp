#include <bits/stdc++.h>

using namespace std;

long long maxProduct = LONG_LONG_MIN;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    while (N--) {
        long long product = 1;
        for (int i=0; i<K; i++) {
            int c;
            scanf("%d", &c);
            product *= c;
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    printf("%lld\n", maxProduct);
}