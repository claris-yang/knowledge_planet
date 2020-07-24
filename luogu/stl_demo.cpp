//
// Created by yangtao on 19-6-27.
//
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;
int main() {
	
	int ia[6] = {27, 210, 12, 47, 109, 83};
	vector<int, allocator<int>> vi(ia, ia+6);
	cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));

	vector<int>::iterator it  = vi.begin();
	for(; it != vi.end(); it++) {
		cout << *it << endl;
	}

	for (int i : {1,2,3,4,5,6,7,8,10} ) {
		cout << i << endl;
	}

	for( auto elem : vi) {
		cout << elem << endl;
	}

	for( auto &elem : vi) {
		cout << elem  << endl;
	}

	list<string> c;
	list<string>::iterator it ;

	return 0;

}
