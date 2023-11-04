#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        //Assuming words are of small alphabets
        int index = word[0] - 'a';
        TrieNode* child;
        // char present
        if(root->children[index] != NULL){
            // simply agge bdhjao
            child = root->children[index];
        }
        // char absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
        if(searchWord(word)){
            int idx = word[0]-'a';
            TrieNode* temp = root->children[idx];
            TrieNode* child = root;
            while(temp->isTerminal != true){
                word = word.substr(1);
                idx = word[0]-'a';
                child = temp;
                temp = temp->children[idx];
            }
            child->isTerminal = true;
            delete temp;
            cout<<"word removed"<<endl;
            //  OR
            // while(word.length() != 1){
            //     word = word.substr(1);
            //     idx = word[0]-'a';
            //     child = child->children[idx];
            // }
            // child->isTerminal = false;
            // cout<<"word removed"<<endl;
            return;
        }
        else{
            cout<<"Word doesn't exist"<<endl;
            return;
        }
    }

    void removeWord(string word){
        removeUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        //Assuming all words are of small alphabets
        int idx = word[0] - 'a';
        TrieNode* child;
        // char present
        if(root->children[idx] != NULL){
            //simply agge bdhjao
            child = root->children[idx];
        }
        else{
            // char not present, i.e word not present, return false
            return false;
        }
        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }
};
int main(){
    Trie *t = new Trie();
    t->insertWord("arm");
    t->insertWord("do");
    t->insertWord("time");
    if(t->searchWord("do")){
        cout<<"word present"<<endl;
    }
    else{
        cout<<"word not present"<<endl;
    }
    t->removeWord("do");
    if(t->searchWord("do")){
        cout<<"word present"<<endl;
    }
    else{
        cout<<"word not present"<<endl;
    }
    return 0;
}