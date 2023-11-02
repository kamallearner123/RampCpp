#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

template <typename D1>
class mymap{
    public:
    D1 first;
    D1 second;
};

class Solution {
    int num;
public:
    mymap<int> traverse(TreeNode *node) {
        mymap <int> data{0,0}, data1{0,0}, data2{0,0};

        if (node ==NULL) {
            //cout << "Reached NULL" << endl;
            data.first = 0;
            data.second = 0;
            return data;
        }

        //cout << "Node->data = " << node->val << endl;        
        if (node->left != nullptr){
            data1 = traverse(node->left);
        }
        if (node->right != nullptr) {
            data2 = traverse(node->right);
        }

        if ((data1.first+data2.first+node->val)/(data1.second+data2.second+1) == node->val) {
            //cout << "Found it at" << node->val << endl;
            num++;
        }
        //cout << "Total at "  << node->val << " is = " << total1+total2+node->val << endl;
        data.first = data1.first+data2.first+node->val;
        data.second = data1.second+data2.second+1;
        return data;
    }

    int averageOfSubtree(TreeNode* root) {
        num = 0;
        (void)traverse(root);        
        return num;
    }
};


int main() {
    Solution s;
    struct TreeNode *t = new TreeNode{4};
    struct TreeNode *t1 = new TreeNode(8);
    struct TreeNode *t2 = new TreeNode(5);
    struct TreeNode *t3 = new TreeNode(0);
    struct TreeNode *t4 = new TreeNode(1);
    struct TreeNode *t5 = new TreeNode(6);

    t->left = t1;
    t->right = t2;

    t1->left = t3;
    t1->right = t4;

    t2->right = t5;

    cout << s.averageOfSubtree(t) << endl;
}