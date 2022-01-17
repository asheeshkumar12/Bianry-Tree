#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}



// functio call to contruct a binary tree given in and pre order traversal

#include<bits/stdc++.h>
 BinaryTreeNode<int>* bT(int *in,int *pre,int inS,int inE,int preS,int preE)
 {
    if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rIdx = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rIdx = i;
			break;
		}
	}

	int lInS = inS; 
	int lInE = rIdx - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rIdx + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = bT(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = bT(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}
// BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength)
    {
        return bT(inorder,preorder,0,inLength-1,0,preLength-1);
    }
    
   