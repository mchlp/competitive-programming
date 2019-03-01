#include <bits/stdc++.h>

using namespace std;

int grid[3][3];
int trygrid[3][3];
bool trygood[3][3];
bool good[3][3];

bool check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!trygood[i][j]) {
                return false;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (trygrid[i][1] - trygrid[i][0] != trygrid[i][2] - trygrid[i][1]) {
            return false;
        }
        if (trygrid[1][i] - trygrid[0][i] != trygrid[2][i] - trygrid[1][i]) {
            return false;
        }
    }
    return true;
}

void reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trygood[i][j] = good[i][j];
            trygrid[i][j] = grid[i][j];
        }
    }
}

void solve() {
    for (int _ = 0; _ < 20; _++) {
        for (int i = 0; i < 3; i++) {
            if (!trygood[i][0] && trygood[i][1] && trygood[i][2]) {
                trygrid[i][0] = trygrid[i][1] - (trygrid[i][2] - trygrid[i][1]);
                trygood[i][0] = true;
            } else if (!trygood[i][1] && trygood[i][0] && trygood[i][2]) {
                trygrid[i][1] = (trygrid[i][2] - trygrid[i][0]) / 2 + trygrid[i][0];
                trygood[i][1] = true;
            } else if (!trygood[i][2] && trygood[i][0] && trygood[i][1]) {
                trygrid[i][2] = (trygrid[i][1] - trygrid[i][0]) + trygrid[i][1];
                trygood[i][2] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (!trygood[0][i] && trygood[1][i] && trygood[2][i]) {
                trygrid[0][i] = trygrid[1][i] - (trygrid[2][i] - trygrid[1][i]);
                trygood[0][i] = true;
            } else if (!trygood[1][i] && trygood[2][i] && trygood[0][i]) {
                trygrid[1][i] = (trygrid[2][i] - trygrid[0][i]) / 2 + trygrid[0][i];
                trygood[1][i] = true;
            } else if (!trygood[2][i] && trygood[1][i] && trygood[0][i]) {
                trygrid[2][i] = (trygrid[1][i] - trygrid[0][i]) + trygrid[1][i];
                trygood[2][i] = true;
            }
        }
    }

    for (int _ = 0; _ < 20; _++) {
        for (int i = 0; i < 3; i++) {
            int rfillcount = 0;
            for (int j = 0; j < 3; j++) {
                if (trygood[i][j]) {
                    rfillcount++;
                }
            }
            if (rfillcount == 1) {
                bool foundvdiff = false;
                int vdiff = 0;
                for (int j = 0; j < 3; j++) {
                    if (i == 0 || i == 1) {
                        if (trygood[i + 1][j] && trygood[i][j]) {
                            foundvdiff = true;
                            vdiff = trygrid[i + 1][j] - trygrid[i][j];
                            break;
                        }
                    }
                    if (i == 1 || i == 2) {
                        if (trygood[i - 1][j] && trygood[i][j]) {
                            foundvdiff = true;
                            vdiff = trygrid[i][j] - trygrid[i - 1][j];
                            break;
                        }
                    }
                }
                if (foundvdiff) {
                    for (int j = 0; j < 3; j++) {
                        if (i == 0 || i == 1) {
                            if (trygood[i + 1][j]) {
                                trygrid[i][j] = trygrid[i + 1][j] - vdiff;
                                trygood[i][j] = true;
                                continue;
                            }
                        }
                        if (i == 1 || i == 2) {
                            if (trygood[i - 1][j]) {
                                trygrid[i][j] = trygrid[i - 1][j] + vdiff;
                                trygood[i][j] = true;
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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

    reset();
    solve();

    int gcount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (trygood[i][j]) {
                gcount++;
            }
        }
    }

    if (gcount == 1) {
        if (trygood[1][0]) {
            trygrid[0][0] = trygrid[1][0];
            trygrid[0][0] = true;
            trygrid[1][1] = trygrid[1][0];
            trygood[1][1] = true;
            trygrid[1][2] = trygrid[1][0];
            trygood[1][2] = true;
        } else if (trygood[1][1]) {
            trygrid[0][1] = trygrid[1][1];
            trygrid[0][1] = true;
            trygrid[1][0] = trygrid[1][1];
            trygood[1][0] = true;
            trygrid[1][2] = trygrid[1][1];
            trygood[1][2] = true;
        } else if (trygood[1][2]) {
            trygrid[0][2] = trygrid[1][2];
            trygrid[0][2] = true;
            trygrid[1][0] = trygrid[1][2];
            trygood[1][0] = true;
            trygrid[1][1] = trygrid[1][2];
            trygood[1][1] = true;
        } else {
            trygrid[1][0] = 0;
            trygood[1][0] = true;
            trygrid[1][1] = 0;
            trygood[1][1] = true;
            trygrid[1][2] = 0;
            trygood[1][2] = true;
        }
    }

    gcount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (trygood[i][j]) {
                gcount++;
            }
        }
    }

    if (gcount == 3 && trygood[1][0] && trygood[1][1] && trygood[1][2]) {
        trygrid[0][0] = trygrid[1][0];
        trygood[0][0] = true;
    }

    if (gcount < 3) {
        good[1][1] = true;
        grid[1][1] = 0;
    }

    if (gcount == 0) {
        printf("0 0 0\n0 0 0\n0 0 0");
        return 0;
    }

    if (!check()) {
        if (!trygood[1][0]) {
            for (int i = -10000000; i < 10000000; i++) {
                reset();
                trygrid[1][0] = i;
                trygood[1][0] = true;
                solve();
                if (check()) {
                    break;
                };
            }
        }
        else if (!trygood[1][1]) {
            for (int i = -10000000; i < 10000000; i++) {
                reset();
                trygrid[1][1] = i;
                trygood[1][1] = true;
                solve();
                if (check()) {
                    break;
                };
            }
        }
        else if (!trygood[1][2]) {
            for (int i = -10000000; i < 10000000; i++) {
                reset();
                trygrid[1][2] = i;
                trygood[1][2] = true;
                solve();
                if (check()) {
                    break;
                };
            }
        } else {
            solve();
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (trygood[i][j]) {
                printf(" %d", trygrid[i][j]);
            } else {
                printf(" -1");
            }
        }
        printf("\n");
    }

    return 0;
}