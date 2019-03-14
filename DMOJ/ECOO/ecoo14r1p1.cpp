#include <bits/stdc++.h>

using namespace std;

int main() {

    int _ = 10;
    while (_--) {
        int ed, eh, em;
        scanf("%d%d%d", &ed, &eh, &em);
        ed--;
        long long es = ed * 24 * 3600 + eh * 3600 + em * 60;
        double ms = es * ((24*3600) / (24*3600+37*60+22.663));
        int md = ms / (24*3600);
        int mh = (ms - (md * 24 * 3600)) / 3600;
        int mm = (ms - (md * 24 * 3600) - (mh * 3600)) / 60;
        printf("Day %d, %02d:%02d\n", md+1, mh, mm);
    }

    return 0;
}