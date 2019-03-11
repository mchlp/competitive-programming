#include <bits/stdc++.h>

using namespace std;

int aw, ah, bx, by, sx, sy, tx, ty, th;

int main() {

    for (int _=0; _<10; _++) {
        scanf("%d%d%d%d%d%d", &aw, &ah, &bx, &by, &sx, &sy);

        double m, b;
        m = (double) sy / sx;
        b = by - (m * bx);

        for (int i=0; i<5; i++) {
            m = (double) sy / sx;
            b = by - (m * bx);
            scanf("%d%d%d", &th, &tx, &ty);

            if (sx == 0) {
                if (ty != by) {
                    printf("M");
                    continue;
                } else {
                    printf("H");
                }
            }

            while (true) {
                double topx = (ah - b) / m;
                double bottomx = (-b) / m;

                if (topx > tx || bottomx > tx) {
                    double yPos = (m * tx) + b;
                    if (yPos <= ty && yPos >= ty-th) {
                        printf("H");
                    } else {
                        printf("M");
                    }
                    break;
                } else {
                    m = -m;
                    if (topx > bottomx) {
                        b = ah - (m * topx);
                    } else {
                        b = -(m * bottomx);
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}