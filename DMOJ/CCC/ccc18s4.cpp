#include <bits/stdc++.h>

using namespace std;

unordered_map<int, long long> memo;

long long recur(int weight) {
    if (memo.count(weight) == 0) {
        if (weight == 1) {
            memo[weight] = 1;
        } else {
            long long total = 0;
            for (int i=2; i<=weight; i++) {
                int cweight = weight / i;
                total += recur(cweight);
            }
            memo[weight] = total;
        }
    }
    return memo[weight];
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%lld\n", recur(N));

    return 0;
}