#include <bits/stdc++.h>

using namespace std;

int ul[1000001];

int main() {

    int K;
    scanf("%d", &K);

    memset(ul, 0, sizeof ul);

    while (K--) {
        int x;
        scanf("%d", &x);
        ul[x]++;
    }

    for (int i=1; i<1000001; i++) {
        ul[i] += ul[i-1];
    }

    int N;
    cin >> N;
    while (N--) {
        int x;
        scanf("%d", &x);
        x -= ul[x];
        printf("%d\n", x);
    }

    return 0;
}