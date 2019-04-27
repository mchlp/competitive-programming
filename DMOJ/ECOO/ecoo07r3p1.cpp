#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000001

bool primes[MAXN];

int main() {

    memset(primes, true, sizeof primes);
    primes[2] = false;
    for (int i=2; i<sqrt(MAXN) + 1; i++) {
        int n = i*2;
        while (n < MAXN) {
            primes[n] = false;
            n += i;
        }
    }

    int _=5;
    while (_--) {
        int N;
        scanf("%d", &N);
        bool found = false;

        if (primes[N]) {
            printf("%d = %d\n", N, N);
            found = true;
        }

        for (int i=(N/2)+1; i>0; i--) {
            if (primes[i] && primes[N-i]) {
                found = true;
                printf("%d = %d + %d\n", N, i, N-i);
                break;
            }
        }

        if (!found) {
            for (int i=(N/3)+1; i>0; i--) {
                for (int j=(N/3)+1; j>0; j--) {
                    if (primes[i] && primes[j] && primes[N-i-j]) {
                        printf("%d = %d + %d + %d\n", N, j, i, N-i-j);
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }
    }

    return 0;
}