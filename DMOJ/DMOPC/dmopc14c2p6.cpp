#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> trees[20001];
long long bit[100001];
long long res[100000];
int memoSum[100001];
vector<tuple<int, int, int, int>> queries;

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    return get<0>(a)> get<0>(b);
}

void update(int x, int val) {
    for (; x <= N; x += x & -x) {
        bit[x] += val;
    }
}

int sumBit(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x) {
        sum += bit[x];
    }
    return sum;
}

int main() {
    memset(bit, 0, sizeof bit);
    memset(memoSum, 0, sizeof memoSum);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int m;
        scanf("%d", &m);
        trees[m].push_back(i);
    }
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int a, b, q;
        scanf("%d %d %d", &a, &b, &q);
        tuple<int, int, int, int> query = {q, i, a, b};
        queries.push_back(query);
    }
    sort(queries.begin(), queries.end(), cmp);
    int curLevel = 20001;
    for (int i = 0; i < Q; i++) {
        tuple<int, int, int, int> query = queries[i];
        int queryLevel = get<0>(query);
        if (queryLevel < curLevel) {
            for (int j = curLevel - 1; j >= queryLevel; j--) {
                for (int k = 0; k < trees[j].size(); k++) {
                    update(trees[j][k] + 1, j);
                }
            }
            curLevel = queryLevel;
        }

        int a = get<2>(query);
        int b = get<3>(query);

        long long mass = sumBit(b + 1) - (a == 0 ? 0 : sumBit(a));

        res[get<1>(query)] = mass;
    }

    for (int i = 0; i < Q; i++) {
        printf("%lld\n", res[i]);
    }

}