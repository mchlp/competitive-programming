#include <bits/stdc++.h>

using namespace std;

char graph[101][502];

int main() {

    for (int _ = 0; _ < 10; _++) {
        int L, W;
        scanf("%d%d ", &L, &W);
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%c ", &graph[i][j]);
            }
        }

        int oddPos = W / 2;
        int evenPos = oddPos;
        int nextLane = L-1;
        int stayCount = 0;
        int dayCount = 0;
        bool possible = true;

        while (nextLane >= 0) {
            int nextLanePos = nextLane % 2 == 0 ? oddPos : evenPos;
            int curLanePos = nextLane-1 % 2 == 0 ? oddPos : evenPos;
            if (graph[nextLane][nextLanePos] == '-') {
                nextLane--;
                stayCount = 0;
            } else {
                stayCount++;
            }
            if (nextLane > 0) {
                if (graph[nextLane-1][curLanePos] != '-') {
                    printf("Not Possible\n");
                    possible = false;
                    break;
                }
            }
            if (stayCount > W) {
                printf("Not Possible\n");
                possible = false;
                break;
            }
            dayCount++;
            evenPos++;
            if (evenPos == W) {
                evenPos = 0;
            }
            oddPos--;
            if (oddPos < 0) {
                oddPos = W - 1;
            }
        }
        if (possible) {
            printf("%d\n", dayCount);
        }
    }

    return 0;
}