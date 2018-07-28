#include <bits/stdc++.h>

using namespace std;

#define MAXN 20000
#define MAXR 1002

int rooms[MAXR][2];
int dp[MAXR][MAXN];

int main() {

    int N, E;

    scanf("%d %d", &N, &E);

    for (int i=0; i<N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        rooms[i+1][1] = a;
        rooms[i+2][0] = b;
    }

    for (int i=0; i<MAXN; i++) {
        dp[0][i] = i;
    }


    for (int i=1; i<MAXR; i++) {
        for (int j = E; j >= 0; j--) {
            if (j >= rooms[i][1] + rooms[i+1][0]) {
                dp[i][j] = dp[i-1][j];
            } else if (rooms[i+1][0] <= j && j < rooms[i][1] + rooms[i+1][0]) {
                dp[i][j] = dp[i-1][j-rooms[i+1][0]] + rooms[i+1][0];
            } else if (j < rooms[i+1][0]) {
                int closed = 0;
                for (int k=0; k<rooms[i][1]; k++) {
                    if (dp[i-1][k] > closed) {
                        closed = dp[i-1][k];
                    }
                }
                int open = dp[i-1][rooms[i][1]];
                dp[i][j] = max(closed, open);
            }
        }
    }

    int m = 0;
    for (int i=0; i<MAXN; i++) {
        m = max(dp[N][i], m);
    }

    printf("%d\n", m);

    /* dp[i room][j people in room] = max # of friends from room 1 to room i
     * j <= 20 000 or else you can travel anywhere
     * dp[1][j] = j
     * j < e
     * cases:
     * j >= ai + bi (all j people can go to the left)
     * bi <= j <= ai (only j-bi people can go to the left)
     * j < bi (no one can move)
     *
     * dp[cur][j] = dp[pre][j] (j >= ai + bi)
     * dp[cur][j] = dp[pre][j-bi]+bi (bi <= j < ai + bi)
     * dp[cur][j] = CLOSED: max(dp[pre][0], dp[pre][1]...dp[pre][ai-1] (pre < ai && j < bi)
     *              OPEN: dp[pre][ai+j]
     *              max(CLOSED, OPEN)
     */

    return 0;
}