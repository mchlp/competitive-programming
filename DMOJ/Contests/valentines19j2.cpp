#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int pcount = 0;
    while (N--) {
        int r, g, b;
        scanf("%d%d%d", &r, &g, &b);
        if (r >= 240 && r <= 255 && g >=0 && g<= 200 && b >= 95 && b <=220) {
            pcount++;
        }
    }
    printf("%d\n", pcount);
}