#include<bits/stdc++.h>

using namespace std;

vector<int> data[701];

int main() {
    int N = 10;
    while (N--) {
        for (int i=0; i<701; i++) {
            data[i].clear();
        }
        int roads;
        scanf("%d", &roads);
        int low = INT_MAX;
        for (int i=0; i<roads; i++) {
            int id;
            int rounds;
            scanf("%d %d", &id, &rounds);
            for (int j=0; j<rounds; j++) {
                int c;
                scanf(" %d", &c);
                data[id].push_back(c);
                if (c < low) {
                    low = c;
                }
            }
            scanf("\n");
        }
        vector<int> t;
        for (int i=0; i<701; i++) {
            for (int j=0; j<data[i].size(); j++) {
                if (data[i][j] == low) {
                    t.push_back(i);
                    break;
                }
            }
        }

        printf("%d {", low);
        sort(t.begin(), t.end());
        printf("%d", t[0]);
        for (int i=1; i<t.size(); i++) {
            printf(",%d", t[i]);
        }
        printf("}\n");
    }
    return 0;
}