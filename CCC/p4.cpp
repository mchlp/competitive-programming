#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> places;
vector<pair<int, int>> max1;
vector<pair<int, int>> max2;

int main() {

    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        places.push_back(make_pair(x, i));
    }

    for (int j=0; j<N-K; j++) {
        max1.push_back(places[j]);
    }
    for (int j=N-K; j<N; j++) {
        max2.push_back(places[j]);
    }

    sort(max1.begin(), max1.end());
    sort(max2.begin(), max2.end());

    int maxSum = max1.empty() ? max2.back().first: max1.back().first + max2.back().first;

    if (!max1.empty() && !max2.empty()) {
        for (int j = 0; j < max2.size(); j++) {
            if (max2[j].first > max1.back().first) {
                if (max2[j].second <= K) {
                    max1.push_back(max2[j]);
                    max2.erase(max2.begin() + j);
                    sort(max1.begin(), max1.end());
                    if (max1.back().first + max2[j].first > maxSum) {
                        maxSum = max1.back().first + max2[j].first;
                    }
                }
            }
        }
    }

    /*
    if (!max1.empty() && !max2.empty()) {
        while (!max2.empty() && max2.back().first > max1.back().first) {
            if (max2.back().second <= K) {
                max1.push_back(max2.back());
                max2.pop_back();
                sort(max1.begin(), max1.end());
                if (max1.back().first + max2.back().first > maxSum) {
                    maxSum = max1.back().first + max2.back().first;
                }
            } else {
                pair<int, int> lastTop = max2.back();
                max2.pop_back();
                bool found = false;
                while (max2.back().first == lastTop.first && max2.back().second != lastTop.second) {
                    if (max2.back().second <= K) {
                        max1.push_back(max2.back());
                        max2.pop_back();
                        max2.push_back(lastTop);
                        sort(max1.begin(), max1.end());
                        sort(max2.begin(), max2.end());

                        if (max1.back().first + max2.back().first > maxSum) {
                            maxSum = max1.back().first + max2.back().first;
                        }
                        found = true;
                    }
                }
                if (!found) {
                    max2.push_back(lastTop);
                    sort(max1.begin(), max1.end());
                    sort(max2.begin(), max2.end());
                    break;
                }
            }
        }
    }*/

    sort(max1.begin(), max1.end());
    sort(max2.begin(), max2.end());
    if (max1.empty()) {
        printf("%d\n", max2.back().first);
    } else if (max2.empty()) {
        printf("%d\n", max1.back().first);
    } else {
        printf("%d\n", maxSum);
    }
    /*
    sort(places.begin(), places.end());

    int max1 = 0;
    int max2 = 0;
    for (int i=0; i<places.size(); i++) {
        if (places[i] > max1 && places[i].second >= N-K) {
            max1 = places[i].first;
        } else if (places[i] > max2) {
            max2 = places[i].first;
            break;
        }
    }

    printf("%d\n", max1+max2);
*/
    return 0;
}