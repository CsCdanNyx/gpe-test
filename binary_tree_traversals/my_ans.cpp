#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



typedef struct node{
    char val;
    node *left;
    node *right;
    node(char x) :
        val(x), left(nullptr), right(nullptr) {}
}node;


vector<char> preorder(26, 0);
vector<char> inorder(26, 0);
int pre_index = 0;

node* construct_tree(int begin_index, int end_index) {
    
    if (begin_index > end_index)
        return nullptr;


    node *root = new node(preorder[pre_index]);

    auto itr = find(inorder.begin(), inorder.end(), preorder[pre_index]);
    int root_index = distance(inorder.begin(), itr);
    pre_index++;

    root->left = construct_tree(begin_index, root_index - 1);
    root->right = construct_tree(root_index + 1, end_index);

    return root;
}

void print_postorder(node *root) {
    if (root == nullptr)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
    return;
}

int main() {

    int cases, node_cnt;
    cin >> cases;
    while (cases--) {

        fill(preorder.begin(), preorder.end(), 0);
        fill(inorder.begin(), inorder.end(), 0);

        cin >> node_cnt;
    

        // cout << "preorder: ";
        for (int i = 0; i < node_cnt; i++) {
            cin >> preorder[i];
            // cout << preorder[i] << " ";
        }
        // cout << endl;

        // cout << "inorder: ";
        for (int i = 0; i < node_cnt; i++) {
            cin >> inorder[i];
            // cout << inorder[i] << " ";
        }
        // cout << endl;

        pre_index = 0;
        node *aRoot = construct_tree(0, node_cnt - 1);

        // cout << "postorder: ";
        print_postorder(aRoot);
        cout << endl;

    }


    return 0;
}