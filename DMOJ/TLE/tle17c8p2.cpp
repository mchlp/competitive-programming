#include<bits/stdc++.h>

using namespace std;

long t[1001];
vector<pair<double, double>> s;

int main() {

    for (int i = 0; i < 1001; i++) {
        t[i] = 0;
    }

    long H;
    int D, E;
    scanf("%ld %d %d", &H, &D, &E);

    for (int i = 0; i < D; i++) {
        double A, S;
        scanf("%lf %lf", &A, &S);
        pair<double, double> pdd;
        pdd.first = A;
        pdd.second = S;
        s.push_back(pdd);
    }

    int lastTime = 0;
    for (int i = 0; i < E; i++) {
        int T, L, X;
        scanf("%d %d %d", &T, &L, &X);
        for (int j = T; j < T + L; j++) {
            t[j] += X;
        }
        lastTime = max(lastTime, T + L);
    }

    long double health = H;

    for (int i = 0; i < lastTime; i++) {
        long double newHealth = health-t[i];
        for (unsigned int j = 0; j < s.size(); j++) {
            long double testHealth = health;
            if (t[i] - s[j].second > 0) {
                testHealth -= (t[i] - s[j].second) * (1 - (s[j].first / 100.0));
            }
            if (testHealth > newHealth) {
                newHealth = testHealth;
            }
        }
        health = newHealth;
    }

    if (health < 0) {
        printf("DO A BARREL ROLL!\n");
    } else {
        printf("%.2Lf\n", health);
    }

    return 0;
}