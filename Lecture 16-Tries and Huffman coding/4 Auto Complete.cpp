#include <iostream>
#include <string>
using namespace std;
#include <vector>


class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
  
    //Finding address of last letter of word
	TrieNode* addressLast(TrieNode* root, string word){
		if(word.size() == 0){
			return root;
		}
		int index = word[0] -'a';
		if(root->children[index] != NULL){
			return addressLast(root->children[index], word.substr(1));
		}
		else{
			return NULL;
		}
	}
	
	void autoComplete(TrieNode* root, string word){
		if(word.size()==0){
			return;
		}
		
		TrieNode *lastAdd = addressLast(root, word);
		if(lastAdd != NULL){
			if(lastAdd -> isTerminal == true){
				cout<<word<<endl;
				lastAdd -> isTerminal = false;
			}
			for(int i=0; i<26; i++){
				if(lastAdd->children[i] != NULL){
					string temp = word;
					temp += lastAdd->children[i]->data;
					autoComplete(root, temp);
				}
			}
		}
	}
	
	void autoComplete(vector<string> input, string pattern) {
        for(int i=0; i<input.size(); i++){
			insertWord(input[i]);
		}
		autoComplete(root, pattern);
    }
};



int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}

