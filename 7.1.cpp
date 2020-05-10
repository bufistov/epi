#include <cassert>
#include <iostream>
#include <string>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

     string toString() {
         ListNode *ptr = this;
         string result;
         while (ptr) {
             result += to_string(ptr->val);
             result += ' ';
             ptr = ptr->next;
         }
         return result;
     }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = 0;
        ListNode* resultLast = 0;
        while (l1 != 0 && l2 != 0) {
            ListNode* add = l1;
            if (l1->val > l2->val) {
                add = l2;
                l2 = l2->next;
            } else {
                l1 = l1->next;
            }
            if (result == 0) {
                result = add;
                resultLast = add;
            } else {
                resultLast->next = add;
                resultLast = add;
            }
        }
        ListNode* tail = l1 != 0 ? l1 : l2;
        while (tail) {
            if (result == 0) {
                result = tail;
                resultLast = tail;
            } else {
                resultLast->next = tail;
                resultLast = tail;
            }
            tail = tail->next;
        }
        return result;
    }
};

int main() {
    ListNode n2(3);
    ListNode n1(2, &n2);
    ListNode n0(1, &n1);

    ListNode n4(5);
    ListNode n5(4, &n4);

    ListNode* merged = Solution().mergeTwoLists(&n0, &n5);
    assert(merged->toString() == "1 2 3 4 5 ");
    return 0;
}