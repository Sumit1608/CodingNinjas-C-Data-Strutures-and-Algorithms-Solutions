#include<iostream>
using namespace std;
#include <string>

class TrieNode{
	public:
		char data;
		TrieNode **children;
		bool isTerminal;
		
		TrieNode(char data){
			this->data = data;
			children = new TrieNode*[26];
			for(int i=0; i<26; i++){
				children[i] = NULL;
			}
			isTerminal = false;
		}
};

class Trie {
	TrieNode *root;
	
	public:
		
		Trie(){
			root = new TrieNode('\0');
		}
		
		void insertWord(TrieNode* root, string word){
			//Base Case
			if(word.size() == 0){
				root -> isTerminal = true;
				return;
			}
			
			//Small calculation
			int index = word[0] - 'a';
			TrieNode *child;
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			
			//Recursice call
			insertWord(child, word.substr(1));
		}
		
		//For User
		void insertWord(string word){
			insertWord(root, word);
		}
		
		
		bool search(TrieNode* root, string word){
			//Base Case
			if(word.size() == 0){
				return root->isTerminal;
			}
			
			//Small calculation & Recursive call
			int index = word[0] - 'a';
			if(root->children[index] == NULL){
				return false;
			}
			else{
				return search(root->children[index], word.substr(1));
			}
		}
		
		//For User
		bool search(string word){
			return search(root, word);
		}
		/*Or
		bool search(string word) {
        	return searchhelp(root,word);
    	}
    	bool searchhelp(TrieNode *root,string word){
    	    if(word.size()==0){
	            return root->isTerminal;
    	    }
        	int index=word[0]-'a';
        	TrieNode*child;
        	if(root->children[index]!=NULL){
        	    child=root->children[index];
        	}
        	else{
        	    return false;
        	}
        	return searchhelp(child,word.substr(1));
    	}*/
    	
    	void removeWord(TrieNode *root, string word) {
			// Base case
			if(word.size() == 0) {
				root -> isTerminal = false;
				return;
			}

			// Small calculation
			TrieNode *child;
			int index =  word[0] - 'a';
			if(root -> children[index] != NULL) {
				child = root -> children[index];
			}
			else {
				// Word not found
				return;
			}

			removeWord(child, word.substr(1));

			// Remove child Node if it is useless
			if(child -> isTerminal == false) {
				for(int i = 0; i < 26; i++) {
					if(child -> children[i] != NULL) {
						return;
					}
				}
				delete child;
				root -> children[index] = NULL;
			}
		}

		void removeWord(string word) {
			removeWord(root, word);
		}
};


int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("and") << endl;

	t.removeWord("and");
	cout << t.search("and") << endl;
}

