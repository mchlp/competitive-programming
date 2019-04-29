#include <bits/stdc++.h>

using namespace std;

int main() {
    int _ = 10;
    while (_--) {
        int wt, wa, wp, wq, N;
        int ti, ai, pi, qi;
        int count = 0;
        cin >> wt >> wa >> wp >> wq;
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> ti >> ai >> pi >> qi;
            if ((ti * wt + ai * wa + pi * wp + qi * wq) >= 5000) {
                count++;
            }
        }
        printf("%d\n", count);

    }
}