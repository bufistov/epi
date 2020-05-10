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
    bool isPalindrome(ListNode* head) {
        ListNode* middle = head, *fast = head;
        int len = 0;
        while (fast != 0) {
            ++len;
            fast = fast->next;
            if (fast == 0) {
                break;
            }
            ++len;
            fast = fast->next;
            middle = middle->next;
        }
        if (len % 2 && middle != 0) {
            middle = middle->next;
        }
        ListNode* secondHalf = reverse(middle);
        ListNode *firstHalf = head;
        bool result = true;
        ListNode* oldSecondHalf = secondHalf;
        for (int i = 0; i < len / 2; ++i) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        reverse(oldSecondHalf);
        return result;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* result = 0, *resultTail = 0;
        while (head) {
            ListNode* headNext = head->next;
            if (result == 0) {
                result = resultTail = head;
                resultTail->next = 0;
            } else {
                head->next = result;
                result = head;
            }
            head = headNext;
        }
        return result;
    }
};

int main() {
    ListNode n3(1);
    ListNode n2(2, &n3);
    ListNode n1(2, &n2);
    ListNode n0(1, &n1);

    assert(Solution().isPalindrome(&n0));
    cout << n0.toString() << endl;
    assert(n0.toString() == "1 2 2 1 ");
    return 0;
}