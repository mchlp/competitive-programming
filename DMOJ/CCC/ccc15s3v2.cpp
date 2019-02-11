#include <bits/stdc++.h>

using namespace std;

int G, P;
set<int> gates;


int main() {
    scanf("%d%d", &G, &P);
    int count = 0;
    for (int i=1; i<=G; i++) {
        gates.insert(-i);
    }
    while (P--) {
        int p;
        scanf("%d", &p);
        if (gates.lower_bound(-p) == gates.end()) {
            printf("%d\n", count);
            return 0;
        } else {
            gates.erase(gates.lower_bound(-p));
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}