#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include<vector>
vector<int> makearr(BinaryTreeNode<int> *root){
	queue<BinaryTreeNode<int> *> q;
	q.push(root);
	vector<int> arr;
	while(!q.empty()){
		BinaryTreeNode<int> *front=q.front();
		//cout<<front->data<<endl;
		arr.push_back(front->data);
		q.pop();
		if(front->right!=NULL){
			q.push(front->right);
		}
		if(front->left!=NULL){
			q.push(front->left);
		}
	}
	return arr;
}
void pairSum(BinaryTreeNode<int> *root, int sum,BinaryTreeNode<int> *res=NULL) {
    if(root==NULL){
		return ;
	}
	vector<int> arr=makearr(root);
    //sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
	return;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}