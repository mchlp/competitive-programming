#include <bits/stdc++.h>

using namespace std;

int N, P;
vector<pair<int, int>> planets;

int main() {
    scanf("%d%d", &N, &P);

    long long fuel = 0;
    int pcount = 1;

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (i + 1 == P) {
            fuel = a;
        } else {
            if (a - b >= 0) {
                planets.push_back(make_pair(a - b, b));
            }
        }
    }

    sort(planets.begin(), planets.end());

    queue<pair<int, int>> qPlanets;
    for (int i = 0; i < planets.size(); i++) {
        qPlanets.push(planets[i]);
    }

    int vCount = 0;

    while (!qPlanets.empty()) {
        pair<int, int> cur = qPlanets.front();
        qPlanets.pop();
        if (cur.second <= fuel) {
            fuel += cur.first;
            pcount++;
        } else {
            if (vCount < N-1) {
                qPlanets.push(cur);
            } else {
                break;
            }
        }
        vCount++;
    }

    printf("%lld\n%d\n", fuel, pcount);

    return 0;
}