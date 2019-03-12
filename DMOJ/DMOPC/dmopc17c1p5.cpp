#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> arr;
vector<int, pair<int, int>> queries;


int main() {

    scanf("%d%d", &N, &Q);
    for (int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }

    for (int i=0; i<Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        queries.push_back(i, make_pair(a, b));
    }

    sort(queries.begin(), queries.end());

    return 0;
}