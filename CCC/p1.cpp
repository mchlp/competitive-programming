#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    scanf("%d", &N);
    int ways = 0;
    for (int i=0; i<=N/2; i++) {
        if (N - i <= 5) {
            ways++;
        }
    }
    printf("%d\n", ways);
    return 0;
}