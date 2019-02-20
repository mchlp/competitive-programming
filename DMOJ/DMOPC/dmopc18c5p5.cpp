#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001

int N;
vector<pair<int, int>> people;
int hatValues[MAXN];
bool switchPeople[MAXN];
int minUnhap;

void check() {
    for (int i = 0; i < people.size(); i++) {
        hatValues[i] = people[i].first;
    }
    for (int i = 0; i < people.size() -1; i++) {
        if (switchPeople[i]) {
            int second = hatValues[i + 1];
            hatValues[i + 1] = hatValues[i];
            hatValues[i] = second;
        }
    }
    int unhapSum = 0;
    for (int i = 0; i < people.size(); i++) {
        unhapSum += abs(hatValues[i] - people[i].second);
    }

    if (unhapSum < minUnhap) {
        minUnhap = unhapSum;
    }
}

void recurCheck(int per) {
    if (per == N - 1) {
        switchPeople[per] = true;
        check();
        switchPeople[per] = false;
        check();
    } else {
        switchPeople[per] = true;
        recurCheck(per + 1);
        switchPeople[per] = false;
        recurCheck(per + 1);
    }

}


int main() {
    minUnhap = INT_MAX;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        people.push_back(make_pair(v, w));
    }

    recurCheck(0);

    printf("%d\n", minUnhap);
}