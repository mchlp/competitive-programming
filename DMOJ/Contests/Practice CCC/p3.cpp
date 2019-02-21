#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> readings;
vector<int> first;
vector<int> second;

int main() {
    scanf("%d", &N);
    for (int i=0; i<1001; i++) {
        readings.push_back(make_pair(0, i));
    }
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        readings[x].first++;
    }

    sort(readings.begin(), readings.end());
    reverse(readings.begin(), readings.end());

    int max1 = readings[0].first;
    first.push_back(readings[0].second);
    int max2 = -1;
    for (int i=1; i<1001; i++) {
        if (readings[i].first == max1) {
            first.push_back(readings[i].second);
        } else if (max2 == -1){
            max2 = readings[i].first;
            second.push_back(readings[i].second);
        } else if (max2 == readings[i].first) {
            second.push_back(readings[i].second);
        } else {
            break;
        }
    }

    if (first.size() > 1) {
        sort(first.begin(), first.end());
        printf("%d\n", abs(first[0] - first[first.size()-1]));
    } else {
        int maxDis = 0;
        for (int i=0; i<second.size(); i++) {
            if (abs(second[i] - first[0]) > maxDis) {
                maxDis = abs(second[i] - first[0]);
            }
        }
        printf("%d\n", maxDis);
    }

    return 0;
}