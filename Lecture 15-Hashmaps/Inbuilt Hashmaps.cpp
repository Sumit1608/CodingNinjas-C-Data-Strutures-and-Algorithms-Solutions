#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//DevC++ doesnt have files for unordered maps
//

int main() {
	unordered_map<string , int> ourmap;
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;
	
	//cout << ourmap.at("ghi") << endl;   //at fxn is not used 
	cout << "size : " << ourmap.size() << endl;
	cout << ourmap["ghi"] << endl;  // here, it adds ghi to ourmap as it is not there before and assign it the value 0
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}
}
