#include <iostream>
#include <cmath>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr = new ListNode;
        ListNode *head = ptr;
        ListNode *prev;
        int num=0, carry=0;

        while(l1!=nullptr && l2!=nullptr)
        {
            num = carry+l1->val+l2->val;
            ptr->val = num%10;
            if (num>9)
                carry = 1;
            else 
                carry = 0;
            l1 = l1->next;
            l2 = l2->next;
            ptr->next = new ListNode;
            prev = ptr;
            ptr=ptr->next;
        }

        while(l1!=nullptr) {
            num = (carry+l1->val);
            ptr->val = num%10;
            if (num>9)
                carry = 1;
            else 
                carry = 0;

            l1 = l1->next;
            ptr->next = new ListNode;
            prev = ptr;
            ptr=ptr->next;
        }
        while(l2!=nullptr) {
            num = (carry+l2->val);
            ptr->val = num%10;
            if (num>9)
                carry = 1;
            else 
                carry = 0;
            l2 = l2->next;
            ptr->next = new ListNode;
            prev = ptr;
            ptr=ptr->next;
        }

        if (carry!=0) {
            ptr->val = carry;
        }else{
            delete ptr;
            prev->next = nullptr;
        }

       return head; 
    }
};

 int main() {
    ListNode *l3 = new ListNode{3};
    ListNode *l2 = new ListNode{4,l3};
    ListNode *l1 = new ListNode{2,l2};
    

    ListNode *l23 = new ListNode{4};
    ListNode *l22 = new ListNode{6,l23};
    ListNode *l21 = new ListNode{5,l22};
    
    Solution s;
    auto result = s.addTwoNumbers(l1,l21);

    while (result!=nullptr) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
 }