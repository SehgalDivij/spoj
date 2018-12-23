/*
 * Solution to the problem at: https://www.spoj.com/problems/TEST
 */

#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int input = 0;
	std::cin >> input;
	
	while(input != 42){
		std::cout << input << endl;
		std::cin >> input;
	}
	
	return 0;
}