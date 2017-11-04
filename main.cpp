#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};



/*
 Example:
 Input values: 5, 3, 8, 6, 1, 2, 4
 Result
 5
 3 8
 1 4 6
 2
*/
void addNode(int data, TreeNode *&currPtr)
{
 if(!currPtr) {
     currPtr = new TreeNode;
     currPtr->value = data;
     currPtr->right = currPtr->left = nullptr;
 }
 else if(data <= currPtr->value) {
     addNode(data, currPtr->left);
 }
 else {
     addNode(data, currPtr->right);
 }
}

void print(TreeNode* Tree)
{
    if(Tree) {
        cout << Tree->value << " ";
        print(Tree->left);
        print(Tree->right);
    }
}
void deleatingTree(TreeNode *&Head){
    if(Head){
        deleatingTree(Head->left);
        deleatingTree(Head->right);
        delete Head;
    }
}

int main(int argc, char** argv)
{
    cout << "Yaroslav Opanasenko, +380635317095, super_opanas@ukr.net\n\n";
    cout << "Input set of integer values: ";
    string line;
    getline(cin, line);
    cout << line << "\n";
    TreeNode *Head = nullptr;
    for (int i = 0; i < line[i]; ++i) {
        cout << line[i] << " ";
        //if(isdigit(line[i])) {
            //addNode(line[i], Head);
        //}
    }
    cout << "\nYour binary Tree:\n";
    print(Head);
    deleatingTree(Head);
    return 0;
}
