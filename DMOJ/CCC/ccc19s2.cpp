#include <bits/stdc++.h>

using namespace std;

int T, N;
unordered_set<int> primes;

bool checkPrime(int num) {
    if (primes.count(num) > 0) {
        return true;
    }

    if (num == 1) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    bool prime = true;
    for (int i=2; i<=sqrt(num)+1; i++) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }

    if (prime) {
        primes.insert(num);
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    for (int _=0; _<T; _++) {
        scanf("%d", &N);
        for (int i=1; i<=N; i++) {
            if (checkPrime(i) && checkPrime(N*2-i)) {
                printf("%d %d\n", i, N*2-i);
                break;
            }
        }
    }
    return 0;
}