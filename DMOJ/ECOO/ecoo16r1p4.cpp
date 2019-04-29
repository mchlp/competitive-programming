#include <bits/stdc++.h>

using namespace std;

int cx, cy;
vector<pair<int, int>> houses;
bool demo[402][402];
bool house[402][402];
int numTotal;
int numDemo;

void check(int x, int y) {
    vector<pair<int, bool>> dis;
    for (pair<int, int> h : houses) {
        int d = (h.first-x)*(h.first-x) + (h.second-y)*(h.second-y);
        dis.push_back(make_pair(d, demo[h.first][h.second]));
    }

    sort(dis.begin(), dis.end());

    int voteDemo = 0;
    int voteRep = 0;

    for (int i=0; i<3; i++) {
        if (dis[i].second) {
            voteDemo++;
        } else {
            voteRep++;
        }
    }

    for (int i=3; i<dis.size(); i++) {
        if (dis[i].first != dis[2].first) {
            break;
        } else {
            if (dis[i].second) {
                voteDemo++;
            } else {
                voteRep++;
            }
        }
    }

    if (voteDemo >= voteRep) {
        numDemo++;
    }

    numTotal++;
}

int main() {

    int _ = 10;
    while (_--) {
        scanf("%d%d", &cx, &cy);
        cx += 200;
        cy += 200;

        numTotal = 0;
        numDemo = 0;

        int nh = 100;
        memset(demo, false, sizeof demo);
        memset(house, false, sizeof demo);
        houses.clear();

        for (int i = 0; i < nh; i++) {
            int hx, hy;
            char c;
            scanf("%d%d %c", &hx, &hy, &c);
            hx += 200;
            hy += 200;
            demo[hx][hy] = c == 'D';
            house[hx][hy] = true;
            houses.push_back(make_pair(hx, hy));
        }

        for (int i = cx - 52; i <= cx + 52; i++) {
            for (int j = cy - 52; j <= cy + 52; j++) {
                if ((i - cx) * (i - cx) + (j - cy) * (j - cy) <= 2500) {
                    if (!house[i][j]) {
                        check(i, j);
                    }
                }
            }
        }

        printf("%.1f\n", (double) numDemo * 100 / numTotal);
    }

    return 0;
}