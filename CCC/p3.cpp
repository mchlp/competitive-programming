#include <bits/stdc++.h>

using namespace std;

int grid[3][3];
bool good[3][3];
int ogrid[3][3] = {{14, 20, 26}, {18, 18, 18}, {22, 16, 10}};

int main() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            string c;
            scanf("%s", &c[0]);
            if (c[0] == 'X') {
                grid[i][j] = -1;
                good[i][j] = false;
            } else {
                grid[i][j] = stoi(c);
                good[i][j] = true;
            }
        }
    }

    for (int _=0; _<20; _++) {
        for (int i = 0; i < 3; i++) {
            if (!good[i][0] && good[i][1] && good[i][2]) {
                grid[i][0] = grid[i][1] - (grid[i][2] - grid[i][1]);
                good[i][0] = true;
            } else if (!good[i][1] && good[i][0] && good[i][2]) {
                grid[i][1] = (grid[i][2] - grid[i][0]) / 2 + grid[i][0];
                good[i][1] = true;
            } else if (!good[i][2] && good[i][0] && good[i][1]) {
                grid[i][2] = (grid[i][1] - grid[i][0]) + grid[i][1];
                good[i][2] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (!good[0][i] && good[1][i] && good[2][i]) {
                grid[0][i] = grid[1][i] - (grid[2][i] - grid[1][i]);
                good[0][i] = true;
            } else if (!good[1][i] && good[2][i] && good[0][i]) {
                grid[1][i] = (grid[2][i] - grid[0][i]) / 2 + grid[0][i];
                good[1][i] = true;
            } else if (!good[2][i] && good[1][i] && good[0][i]) {
                grid[2][i] = (grid[1][i] - grid[0][i]) + grid[1][i];
                good[2][i] = true;
            }
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (good[i][j]) {
                printf(" %d", grid[i][j]);
            } else {
                printf(" %d", ogrid[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}