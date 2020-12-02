#include <iostream>
using namespace std;

int editDistance(string s, string t) {
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}


	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	}
	else {
		// Insert
		int x = editDistance(s.substr(1), t) + 1;
		// Delete
		int y = editDistance(s, t.substr(1)) + 1;
		// Replace
		int z = editDistance(s.substr(1), t.substr(1)) + 1;

		return min(x, min(y, z));
	}
}

int main() {
	string s,t;
	cin>>s>>t;
	
	cout << editDistance(s, t) << endl;
}

