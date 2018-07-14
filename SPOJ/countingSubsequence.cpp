#include<bits/stdc++.h>

using namespace std;

unordered_map<int, long> checked;

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        checked.clear();

        checked[0] = 1;

        int count = 0;
        int s = 0;
        for (int i = 0; i < N; i++) {
            int c;
            scanf("%d", &c);
            s += c;
            count += checked[s - 47];
            checked[s]++;
        }

        printf("%d\n", count);
    }

    return 0;
}