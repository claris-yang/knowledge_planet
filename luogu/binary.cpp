
#include <iostream>
#include <sstream>

using namespace std;

int binaryToTen(string str) {
        int seed = 1;
        int result = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if ('1' == str[i]) {
                result = result + seed ;
            } 
            seed *= 2;
        }
        return result;
}


string itos( int i ) {
	stringstream stream;
	stream << i;
	return stream.str();
}

string reserve( string &str) {
	int s = str.length();
	for ( int i = 0 ; i < str.length() / 2; i++) {
		char t = str[i];
		str[i] = str[s -i - 1];
		str[s - i -1] = t;
	}	
	return str;
}

string TenToBinary(int a) {
        string str = "";
        
        while( 0 != a) {
            str = str + itos(a & 0x01);
            a = a >> 1;
        }
        
        return reserve(str);
}


int main() {
	std::cout << binaryToTen("1") << std::endl;
	std::cout << binaryToTen("10") << std::endl;
	std::cout << binaryToTen("11") << std::endl;

	std::cout << TenToBinary(3) << std::endl;
	std::cout << TenToBinary(2) << std::endl;
	std::cout << TenToBinary(1) << std::endl;
}
