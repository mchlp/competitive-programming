#include <bits/stdc++.h>

using namespace std;

int N, M;
char names[21][21];
int votes[10001];
queue<int> allVotes[10001];
vector<int> removed;
int voteCount[21];

int main() {
    memset(votes, -1, sizeof votes);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", &names[i][0]);
    }

    for (int i = 0; i < M; i++) {
        int X;
        scanf("%d", &X);
        for (int k = 0; k < X; k++) {
            char name[21];
            scanf("%s", &name[0]);
            for (int j = 0; j < N; j++) {
                if (strcmp(name, names[j]) == 0) {
                    if (k == 0) {
                        votes[i] = j;
                    } else {
                        allVotes[i].push(j);
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        memset(voteCount, 0, sizeof voteCount);
        for (int j = 0; j < M; j++) {
            if (votes[j] != -1) {
                voteCount[votes[j]]++;
            }
        }

        int minVote = INT_MAX;
        int minVoteIndex = 0;
        int goodVoteCount = 0;
        for (int j = 0; j < N; j++) {
            if (voteCount[j] != 0) {
                goodVoteCount++;
                if (voteCount[j] < minVote) {
                    minVoteIndex = j;
                    minVote = voteCount[j];
                }
            }
        }

        if (goodVoteCount == 1) {
            break;
        }

        removed.push_back(minVoteIndex);

        for (int j = 0; j < M; j++) {
            while (find(removed.begin(), removed.end(), votes[j]) != removed.end()) {
                if (allVotes[j].empty()) {
                    votes[j] = -1;
                } else {
                    votes[j] = allVotes[j].front();
                    allVotes[j].pop();
                }
            }
        }

        if (removed.size() == N-1) {
            break;
        }
    }
    memset(voteCount, 0, sizeof voteCount);
    for (int j = 0; j < M; j++) {
        if (votes[j] != -1) {
            voteCount[votes[j]]++;
        }
    }

    int maxVote = 0;
    int maxVoteIndex = 0;
    for (int j = 0; j < N; j++) {
        if (voteCount[j] > maxVote) {
            maxVoteIndex = j;
            maxVote = voteCount[j];
        }
    }
    printf("%s\n", names[maxVoteIndex]);
    return 0;
}