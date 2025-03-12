#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct node {

    char val;
    node *left;
    node *right;

    node(char c) :
        val(c), left(nullptr), right(nullptr) {};

}node;


vector<char> preorder(30);
vector<char> inorder(30);
int preorder_index = 0;


node *make_tree(int beg, int end) {
    if(beg > end)
        return nullptr;

    node *root = new node(preorder[preorder_index]);

    auto itr = find(inorder.begin(), inorder.end(), preorder[preorder_index]);
    int root_index = distance(inorder.begin(), itr);
    preorder_index++;

    root->left = make_tree(beg, root_index-1);
    root->right = make_tree(root_index+1, end);
    
    return root;
}

void print_postorder(node *root) {
    if (!root)
        return;
    
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases, node_cnt;
    cin >> cases;
    while (cases--) {

        fill(preorder.begin(), preorder.end(), 0);
        fill(inorder.begin(), inorder.end(), 0);

        cin >> node_cnt;

        for (int i = 0; i < node_cnt; i++)
            cin >> preorder[i];
        for (int i = 0; i < node_cnt; i++)
            cin >> inorder[i];
        
        preorder_index = 0;
        node *root = make_tree(0, node_cnt-1);
        
        print_postorder(root);
        cout << endl;

    }


    return 0;
}