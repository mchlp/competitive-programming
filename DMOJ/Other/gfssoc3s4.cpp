#include <bits/stdc++.h>

using namespace std;

int R, C;

vector<unsigned int> masks;
unsigned int dp[101][4194305];

bool check(unsigned int mask1, unsigned int mask2) {
    unsigned int newMask = mask1 | mask2;
    return (newMask & (newMask >> 1u) & (newMask >> 2u) == 0) != 0;
}

int main() {

    scanf("%d %d", &R, &C);

    // check if valid: mask & (mask >> 1) & (mask << 1)

    for (int i=1; i<R-1; i++) {
        for (unsigned int mask : masks) {
            for (unsigned int checkMask : masks) {
                if (mask != checkMask) {
                    if (check(mask, checkMask)) {
                        dp[i][mask] += dp[i-1][checkMask];
                    }
                }
            }
        }
    }

    return 0;
}
