#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>

using namespace std;

template <typename T> tuple<int, int> partition(vector<T> &A, int pivotIdx) {
    int firstEqual = 0, lastEqual = 0;
    T pivot = A[pivotIdx];
    swap(A[0], A[pivotIdx]);
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] < pivot) {
            swap(A[i], A[firstEqual]);
            ++firstEqual;
        }
        if (A[i] == pivot) {
            swap(A[i], A[lastEqual + 1]);
            ++lastEqual;
        }
    }
    return make_tuple(firstEqual, lastEqual);
}

int main() {
    vector<int> v1 = {1, 5, 2, 5, 3, 2, 1, 0};
    tuple<int, int> res = partition(v1, 2);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    assert(res == make_tuple(3 ,4));

    vector<uint8_t> testArray(512);
    for (int i = 0; i < 1000; ++i) {
        generate(testArray.begin(), testArray.end(), [](){return rand() % 256;});
        int idx = rand() % testArray.size();
        int pivotCount = count(testArray.begin(), testArray.end(), testArray[idx]);
        cout << "Pivot count: " << pivotCount << endl;
        tuple<int, int> range = partition(testArray, idx);
        assert(get<1>(range) - get<0>(range) + 1 == pivotCount);
    }
    return 0;
}