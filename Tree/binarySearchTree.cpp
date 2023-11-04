#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    if(val<root->data){
        //left call
        root->left = insertToBST(root->left, val);
    }
    else{
        root->right = insertToBST(root->right, val);
    }
    return root;

}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){
        insertToBST(root, d);
        cin>>d;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
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
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root, int val){
    // assuming that val is definitely present in one of the node data of BST
    if(root==NULL)
    return root;
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int maxi = maxVal(root->left)->data;
            root->data = maxi;
            root->left = deleteFromBST(root->left, maxi);
            return root;
            // or
            // int mini = minVal(root->right)->data;
            // root->data = mini;
            // root->right = deleteFromBST(root->right, mini);
            // return root;
        }
   

    }
    else if(root->data > val){
        //left
        root->left = deleteFromBST(root->left, val);
    }
    else{
        //right
        root->right =  deleteFromBST(root->right, val);
    }
    return root;
}
Node* inOrderPred(Node* root){
    if(root==NULL || root->left==NULL){
        return NULL;
    }
    Node* pred = maxVal(root->left);
    return pred;
}
Node* inOrdersucc(Node* root){
    if(root==NULL || root->right==NULL){
        return NULL;
    }
    Node* succ = minVal(root->right);
    return succ;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data: "<<endl;
    takeInput(root);
    // levelOrderTraversal(root);
    // inOrderTraversal(root);
    // cout<<endl;
    // preOrderTraversal(root);
    // cout<<endl;
    // postOrderTraversal(root);
    // cout<<endl;
    // morrisTraversal(root);
    // cout<<endl;
    // cout<<minVal(root)->data<<endl;
    // cout<<maxVal(root)->data<<endl;
    // cout<<endl;
    // cout<<inOrderPred(root)->data<<endl;
    // cout<<inOrdersucc(root)->data<<endl;
    return 0;
}