#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int N;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int mid = ceil(N/2.0) - 1;

    for (int i=0; i<mid; i++) {
        printf("%d %d ", arr[mid-i], arr[mid+i+1]);
    }

    if (N % 2 == 0) {
        printf("%d %d ", arr[0], arr[N-1]);
    } else {
        printf("%d", arr[0]);
    }
}