#include <iostream>
#include <bitset>
#include <string>
#include <cassert>
typedef long long ll_t;

ll_t nearest(ll_t x) {
    if (x & 1) {
        int mask = (x ^ (x + 1)) >> 2;
        return (x + 1) | mask;
    } else {
        int mask = (x ^ (x - 1)) >> 2;
        return (x - 1) & ~mask;
    }
}
using namespace std;

int main() {
    for (int i = 1; i <= 256; ++i) {
        bitset<32> bits(i);
        cout << bits.to_string() << endl;
        string istr = bitset<32>(i).to_string();
        int next = nearest(i);
        bitset<32> nextBits = bitset<32>(next);
        cout << nextBits.to_string() << endl;
        assert(nextBits.count() == bits.count());
        cout << "Difference: " << next - i << endl;
    }
}