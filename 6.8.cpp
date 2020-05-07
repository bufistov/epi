#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_set(vector<int> &set, const int &x) {
    if (set[x] != x) 
        set[x] = find_set(set, set[x]);
    return set[x];
}

void union_set(vector<int> &set, int x, int y) {
    int x_root=find_set(set, x);
    int y_root = find_set(set, y);
    set[min(x_root, y_root)] = max(x_root, y_root);
}

vector<int> offline_minimum(const vector<int> &A, const vector<int> &E) {
    vector<int> R(A.size() + 1, E.size());
    int pre = 0;
    for (int i = 0; i < E.size(); ++i) {
        for (int j = pre; j < E[i]; ++j) {
            R[A[j]] = i;
        }
        pre = E[i];
    }
    vector<int> ret(E.size(), -1);
    vector<int> set(E.size() + 1, 0);
    for (int i = 1; i < set.size(); ++i) {
        set[i] = i;
    }
    for (int i = 0; i < A.size(); ++i) {
        if (find_set(set, R[i]) != E.size() && ret[find_set(set, R[i])] == -1) {
            ret[set[R[i]]] = i;
            union_set(set, set[R[i]], set[R[i]] + 1);
        }
    }
    return ret;
}

int main() {
    vector<int> A = {5,4,6,1,7,3,2};
    vector<int> E = {3,5,5, 7};
    vector<int> res = offline_minimum(A, E);
    for (auto x: res) {
        cout << x << ' ';
    }
    cout << endl;
}