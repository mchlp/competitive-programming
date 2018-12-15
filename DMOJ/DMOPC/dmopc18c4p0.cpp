#include<bits/stdc++.h>

using namespace std;

int main() {

    int R, X, Y;
    int ax, ay, am, bx, by, bm, cx, cy, cm;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &R, &X, &Y, &ax, &ay, &am, &bx, &by, &bm, &cx, &cy, &cm);

    bool see = false;
    int minStar = min(cm, min(am, bm));

    if (minStar == am && sqrt(pow(abs(ax - X), 2) + pow(abs(ay - Y), 2)) < R) {
        see = true;
    } else if (minStar == bm && sqrt(pow(abs(bx - X), 2) + pow(abs(by - Y), 2)) < R) {
        see = true;
    } else if (minStar == cm && sqrt(pow(abs(cx - X), 2) + pow(abs(cy - Y), 2)) < R) {
        see = true;
    }

    if (see) {
        printf("What a beauty!\n");
    } else {
        printf("Time to move my telescope!");
    }

    return 0;
}