#include <bits/stdc++.h>

using namespace std;

bool house[402][402];
bool demo[402][402];
vector<pair<int, int>> houses;

int main() {
    memset(house, false, sizeof house);
    memset(demo, false, sizeof demo);
    houses.clear();
    freopen("DATA41.txt", "r", stdin);
    int _ = 10;
    while (_--) {
        int cx, cy;
        scanf("%d%d", &cx, &cy);
        cx += 200;
        cy += 200;

        for (int i = 0; i < 100; i++) {
            int x, y;
            char c;
            scanf("%d%d %c", &x, &y, &c);
            x += 200;
            y += 200;
            demo[x][y] = c == 'D';
            house[x][y] = true;
            houses.push_back(make_pair(x, y));
        }

        int demc = 0;
        int totc = 0;

        for (int i = cx - 52; i <= cx + 52; i++) {
            for (int j = cy - 52; j <= cy + 52; j++) {
                if (!house[i][j]) {
                    if ((i - cx) * (i - cx) + (j - cy) * (j - cy) <= 2500) {
                        vector<pair<int, pair<int, int>>> disVec;
                        for (int k = 0; k < houses.size(); k++) {
                            int dis = (i - houses[k].first) * (i - houses[k].first) + (j - houses[k].second) * (j - houses[k].second);
                            disVec.push_back(make_pair(dis, houses[k]));
                        }
                        sort(disVec.begin(), disVec.end());
                        int dc = 0;
                        int rc = 0;
                        if (demo[disVec[0].second.first][disVec[0].second.second]) {
                            dc++;
                        } else {
                            rc++;
                        }
                        if (demo[disVec[1].second.first][disVec[1].second.second]) {
                            dc++;
                        } else {
                            rc++;
                        }
                        if (demo[disVec[2].second.first][disVec[2].second.second]) {
                            dc++;
                        } else {
                            rc++;
                        }
                        for (int k = 3; k < disVec.size(); k++) {
                            if (disVec[k].first != disVec[k-1].first) {
                                break;
                            }
                            if (demo[disVec[k].second.first][disVec[k].second.second]) {
                                dc++;
                            } else {
                                rc++;
                            }
                        }
                        if (dc >= rc) {
                            demc++;
                        }
                        totc++;
                    }
                }
            }
        }

        printf("%.1lf\n", ((double) 100 * demc / totc));
    }
}