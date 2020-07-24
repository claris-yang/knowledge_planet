
#include<vector>
#include<iostream>

using namespace std;
inline int max(int a, int b) {
	cout << "实例化" << endl;
	return a < b ? a : b;
}
template <typename T >
inline T const&  max(T const & a , T const & b) {
	return a < b ? a : b;
}
int main() {
	int num = 13;

	cout << ::max(10, 20) << endl;
	cout << "----------" << endl;

	std::vector<int> result ;
	std::vector<int> resp;
	
	while(num ) {
		if (num & 0x01) 
			result.push_back(1);
		else 
			result.push_back(0);
		num = num >> 1;
	}
		
	for(int i = result.size() -1 ; i >= 0 ; i--)
		resp.push_back(result[i]);

	for ( auto s: resp)

		std::cout << s << " " << std::endl;

	int res;

	double a = 1.0;

	res = a + 2;

	cout << res << endl;

	return 0;
	
}
