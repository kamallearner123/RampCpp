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
    ListNode* swapPairs(ListNode* head) {
        ListNode *a1, *a2, *prev = nullptr;
        if (head==nullptr || head->next==nullptr) {
            return head;
        } else {
            a1 = head;
            a2 = a1->next;
        }

        while(true) {
            a1->next = a2->next;
            a2->next = a1;
            if (prev==NULL){
                prev = a1;
                head = a2;
            } else {
                prev = a1;
            }
            a1 = a1->next;
            if (a1!=nullptr) {
                a2 = a1->next;
            } else {
                break;
            }
            if (a2!=nullptr) {
                prev->next = a2;
            } else {
                break;
            }
        }    

        while (head!=nullptr){
            cout << head->val << endl;
            head = head->next;
        }    
        return head;
    }

};

int main() {
    ListNode *l4 = new ListNode{4};
    ListNode *l3 = new ListNode{3,l4};
    ListNode *l2 = new ListNode{2,l3};
    ListNode *l1 = new ListNode{1,l2};
    Solution s;
    s.swapPairs(l1);
    return 1;
}