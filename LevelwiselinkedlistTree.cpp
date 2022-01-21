
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}

#include <queue>

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>* > f_vect;
    if(root==NULL)
        return f_vect;
    queue<BinaryTreeNode<int>*> q;
     q.push(root);
    while(q.size()!=0)
    {
          int size=q.size();
          Node<int> *head=NULL,*tail=NULL;
            for(int i=0;i<size;i++)
            {
                BinaryTreeNode<int>* f=q.front();
                q.pop();
                if(head==NULL)
                {
                            Node<int>* node=new Node<int>(f->data);
                             head=node;
                             tail=node;
                    
                }
               else if(head!=NULL)
                {
                Node<int>* newNode=new Node<int>(f->data);
                tail->next=newNode;
                tail=tail->next;
                  
                }
                if(f->left!=NULL)
                {
                    q.push(f->left);
                    
                }
                if(f->right!=NULL)

                {
                    q.push(f->right);
                }
                
            }
        f_vect.push_back(head);
    }
    return f_vect;
}
