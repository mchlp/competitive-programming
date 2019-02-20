#include <bits/stdc++.h>

using namespace std;

long double r1, r2, g1, g2, b1, b2;

int main() {
    char type[10];
    scanf("%s\n", &type[0]);
    scanf("%Lf%Lf%Lf", &r1, &g1, &b1);
    scanf("%Lf%Lf%Lf", &r2, &g2, &b2);
    if (strcmp(type, "Multiply") == 0) {
        printf("%Lf %Lf %Lf\n", r1*r2, g1*g2, b1*b2);
    } else if (strcmp(type, "Screen") == 0) {
        printf("%Lf %Lf %Lf\n", 1-((1-r1)*(1-r2)), 1-((1-g1)*(1-g2)), 1-((1-b1)*(1-b2)));
    } else {
        long double rf, gf, bf;
        if (r1 < 0.5) {
            rf = 2*(r1)*(r2);
        } else {
            rf = 1-(2*(1-r1)*(1-r2));
        }
        if (g1 < 0.5) {
            gf = 2*(g1)*(g2);
        } else {
            gf = 1-(2*(1-g1)*(1-g2));
        }
        if (b1 < 0.5) {
            bf = 2*(b1)*(b2);
        } else {
            bf = 1-(2*(1-b1)*(1-b2));
        }
        printf("%Lf %Lf %Lf\n", rf, gf, bf);
    }

}