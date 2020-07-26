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
    vector<int> res;
    vector<int> postorder(Node* root) {
        //迭代法
        // vector<int> res;
        // if(!root) return res;
        // stack<Node*> stk;
        // stk.push(root);
        // while(!stk.empty()){
        //     Node* tmp_node = stk.top();
        //     stk.pop();
        //     res.push_back(tmp_node->val);
        //     for(auto node:tmp_node->children){
        //         stk.push(node);
        //     }
        // }
        // reverse(res.begin(),res.end());
        // return res;

        //递归实现
        if(!root) return res;
        for(auto i : root->children )
            postorder(i);
        res.push_back(root->val);
        return res;
    }
};