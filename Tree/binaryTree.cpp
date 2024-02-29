#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildFromLevelOrder(Node* root){
	queue<Node*>q;
	int data;
	cout<<"enter the data: ";
	cout<<endl;
	cin>>data;
	root = new Node(data);
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cout<<"Enter data for left of: "<<temp->data;
		cout<<endl;
		int leftData;
		cin>>leftData;
		if(leftData!=-1){
			temp->left = new Node(leftData);
			q.push(temp->left);
		}
		cout<<"Enter data for right of: "<<temp->data;
		cout<<endl;
		int rightData;
		cin>>rightData;
		if(rightData!=-1){
			temp->right = new Node(rightData);
			q.push(temp->right);
		}		
	}
	return root;
}
Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
// void levelOrderTraversal(Node* root){
// 	queue<Node*> q;
// 	q.push(root);
// 	q.push(NULL);
// 	while(!q.empty()){
// 		Node* temp = q.front();
// 		q.pop();
// 		if(temp==NULL){
// 			cout<<endl;
// 			if(!q.empty()){
// 				q.push(NULL);
// 			}
// 		}
// 		else{
// 			cout<<temp->data<<" ";
// 		if(temp->left){
// 			q.push(temp->left);
// 		}
// 		if(temp->right){
// 			q.push(temp->right);
// 		}
// 		}
// 	}
// }
void levelOrderTraversal(Node* root) {
	queue<Node *> q;
	q.push(root);

	while(!q.empty()) {
		int N = q.size();

		while(N--) {
			Node *temp = q.front();
			q.pop();
			cout << temp->data << " ";

			if(temp->left) {
				q.push(temp->left);
			}

			if(temp->right) {
				q.push(temp->right);
			}
		}

		cout << endl;
	}
}
void inOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	// left traversal
	inOrderTraversal(root->left);
    //Node printing
	cout<<root->data<<" ";
	//right order traversal
	inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
    //Node printing
	cout<<root->data<<" "; 
	// left traversal
	preOrderTraversal(root->left);
	//right order traversal
	preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	// left traversal
	postOrderTraversal(root->left);
	//right order traversal
	postOrderTraversal(root->right);
    //Node printing
	cout<<root->data<<" "; 
}
void morrisTraversal(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred = pred->right;
            }
            if(pred->right==NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main(){
    Node* root = NULL; 
    root = buildTree(root);
    cout<<"level order traversal is: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"in order traversal is: "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"pre order traversal is: "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"post order traversal is: "<<endl;
    postOrderTraversal(root);
    cout<<endl;
	cout<<"morris traversal is: "<<endl;
	morrisTraversal(root);
    return 0;
}