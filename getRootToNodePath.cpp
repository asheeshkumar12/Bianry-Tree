#include<iostream>
#include "binaryTreeNodeClass.cpp"
using namespace std;
#include<queue>
// take input level wise
BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}
// end input level wise

vector<int>* getRootToPath(BinaryTreeNode<int>* root,int k)
{

    if(root==NULL)
        return NULL;
    if(root->data==k)
    {
     vector<int>* output=new vector<int>();
     output->push_back(root->data);
     return output;
    }
    vector<int>* leftOutput=getRootToPath(root->left,k);
    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput=getRootToPath(root->right,k);
    if(rightOutput!=nullptr)
    {

        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}
int main()
{

    BinaryTreeNode<int>* root=takeInputLevelWise();
    vector<int>* output=getRootToPath(root,8);
    for(int i=0;i<output->size();i++)
    {
        cout<<output->at(i)<<" ";
    }
    delete output;
    delete root;

}
