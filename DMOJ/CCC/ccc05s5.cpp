#include <bits/stdc++.h>

using namespace std;

int t;
set<int> scores;

int main() {

    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int x;
        scanf("%d", &x);
        scores.insert(x);
    }
    return 0;
}