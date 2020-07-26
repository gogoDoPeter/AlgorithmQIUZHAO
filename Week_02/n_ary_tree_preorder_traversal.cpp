/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // vector<int> res;
    vector<int> preorder(Node* root) {
        // if(!root) return res;
        // res.push_back(root->val);
        // for(auto i : root->children){
        //     preorder(i);
        // }
        // return res;

        //迭代法
        vector<int> res;
        if(!root) return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp_node = stk.top();
            stk.pop();
            res.push_back(tmp_node->val);
            for(int i = tmp_node->children.size() - 1; i >= 0; --i)
                stk.push(tmp_node->children[i]);
            
        }
        return res;
    }
};