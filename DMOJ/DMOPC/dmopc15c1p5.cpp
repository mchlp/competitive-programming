#include <bits/stdc++.h>

using namespace std;

int prefix[251][251];
int W, H, N;

int main() {

    scanf("%d%d%d", &W, &H, &N);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            scanf("%d", &a);
            if (i == 0 && j == 0) {
                prefix[i][j] = a;
            } else if (i == 0) {
                prefix[i][j] = prefix[i][j - 1] + a;
            } else if (j == 0) {
                prefix[i][j] = prefix[i - 1][j] + a;
            } else {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a;
            }
        }
    }


    int maxDiem;
    if (H > W) {
        maxDiem = W;
    } else {
        maxDiem = H;
    }

    int maxTotal = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 1; k<=maxDiem; k++) {
                int startX = j;
                int startY = i;
                int endX;
                int endY;

                if (H > W) {
                    endX = min(j + k - 1, W - 1);
                    endY = min(i + (N/k) - 1, H - 1);
                } else {
                    endX = min(j + (N/k) - 1, W - 1);
                    endY = min(i + k - 1, H - 1);
                }

                int curTotal = prefix[endY][endX];
                if (startX > 0 && startY > 0) {
                    curTotal -= prefix[startY - 1][endX];
                    curTotal -= prefix[endY][startX - 1];
                    curTotal += prefix[startY - 1][startX - 1];
                } else if (startX > 0) {
                    curTotal -= prefix[endY][startX - 1];
                } else if (startY > 0) {
                    curTotal -= prefix[startY - 1][endX];
                }
                maxTotal = max(maxTotal, curTotal);
            }
        }
    }
    printf("%d\n", maxTotal);
    return 0;
}