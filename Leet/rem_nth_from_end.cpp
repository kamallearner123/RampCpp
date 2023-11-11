#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *prev, *ptr = head;


        while(ptr != nullptr) {
            len++;
            ptr = ptr->next;
        }
        if (len<n) {
            return head;
        }
        ptr = head;
        prev = nullptr;
        while(len-n>0) {
            len--;
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev == nullptr) {
            // Going to delete head;
            head = ptr->next;
        }
        else { 
            prev->next = ptr->next;
        }
        delete ptr;
        return head;
    }
};

int main() {
    ListNode *l3 = new ListNode{4};
    ListNode *l2 = new ListNode{3,l3};
    ListNode *l1 = new ListNode{2,l2};
    ListNode *l0 = new ListNode{1,l1};

    Solution s;
    s.removeNthFromEnd(l0, 4);
    return 0;
 }
