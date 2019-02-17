#include <bits/stdc++.h>

using namespace std;

int N, Q;
int flippedX[100001];
int flippedY[100001];
vector<int> squares[100001];

int main() {

    scanf("%d%d", &N, &Q);
    N++;
    memset(flippedX, 0, sizeof flippedX);
    memset(flippedY, 0, sizeof flippedY);

    for (int _ = 0; _ < Q; _++) {
        int a, i, j;
        scanf("%d%d%d", &a, &i, &j);
        if (a == 1) {
            flippedX[i]++;
            flippedY[j]++;
            squares[i].push_back(j);

        } else {
            printf("%d\n", (flippedX[i] + flippedY[j] - count(squares[i].begin(), squares[i].end(), j)) % 2);
        }

    }

    return 0;
}