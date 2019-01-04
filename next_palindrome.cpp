/*
 * Solution to the problem at: https://www.spoj.com/problems/PALIN/
 */
 
#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
 
string get_next_palindrome(string n){
	int i, j, n_length = n.size(), centre = n_length/2;
	bool is_palindrome;
	// check if it is already a palindrome
	if (!(n_length%2)){
		// even
		i = centre - 1;
		j = centre;
	}
	if (n_length%2){
		// odd
		i = centre - 1;
		j = centre + 1;
	}
	// cout << "length is: " << n_length << endl;
	// cout << "i: " << i << " j: " << j <<endl;
	while (i >= 0 && j < n_length ){
		// cout << "comparing: " << s.at(i) << " and " << s.at(j) << endl;
		if (n.at(i) == n.at(j)){
			i--;
			j++;
		}
		else
			break;
	}
	// cout << "After finishing, i: " << i << " j: " << j <<endl;
	if (i < 0 && j == n_length)
		is_palindrome = true;
	else
		is_palindrome = false;
 
	// number is even
	if (!(n_length % 2)){
		// number is even
		if (is_palindrome){
			// number is already a palindrome. less work to be done
			// cout << n << " is already an even-length palindrome " << endl;
			int leftside = stoi(n.substr(0, centre));
			leftside++;
			string left_side = to_string(leftside);
			int right_side = stoi(n.substr(centre, centre));
			n.replace(0, centre, left_side);
			reverse(left_side.begin(), left_side.end());
			n.replace(centre, centre, left_side);
			// cout << "After changing: " << n << endl;
		}
		else{
			// number of digits is even but number is not already a palindrome
			// cout << n << " is even-length but not already a palindrome" << endl;
			// cout << char(stoi(to_string(n.at(i)))) << endl;
			int leftside = stoi(n.substr(0, i+1));
			string cent;
			cent = n.at(centre-1);
			int centre_char = stoi(cent);
			// cout << i << endl << j << endl;
			if (n.at(i) < n.at(j)){
				int centre_str = stoi(cent);
				int leftside = stoi(n.substr(0, centre-1));
				if (centre_str == 9){
					cent = "0";
					leftside++;
				}
				else{
					centre_char++;
					// left_side = 
					cent = to_string(centre_char);
				}
				// make the replacements in original string.
				string left_side = to_string(leftside);
				n.replace(0, centre-1, left_side);
				reverse(left_side.begin(), left_side.end());
				n.replace(centre + 1, centre, left_side);
				cent += cent;
				// cout << "Before replacing center: " << n << endl;
				n.replace(centre-1, 2, cent);
				// cout << "After changing: " << n << endl;
			}
			else{
				// take the diff side from start and replace with the number increased by 1
				int leftside = stoi(n.substr(0, centre));
				string left_side = n.substr(0, centre);
				n.replace(0, centre, left_side);
				reverse(left_side.begin(), left_side.end());
				n.replace(centre, centre, left_side);
			}
		}
	}
	// number is odd
	else{
		// number is odd
		// odd: increment the central digit by 1
		if(is_palindrome){
			string cent;
			cent = n.at(centre);
			int leftside = stoi(n.substr(0, centre));
			int centre_char = stoi(cent);
			if (centre_char == 9){
				cent = "0";
				leftside++;
			}
			else{
				centre_char++;
				cent = to_string(centre_char);
			}
			string left_side = to_string(leftside);
			n.replace(0, centre, left_side);
			reverse(left_side.begin(), left_side.end());
			n.replace(centre + 1, n_length - centre, left_side);
			n.replace(centre, 1, cent);
		}
		else{
			string cent;
			cent = n.at(centre);
			int leftside = stoi(n.substr(0, centre));
			if (n.at(i) < n.at(j)){
				// cout << "i is less than j" << endl;
				int centre_char = stoi(cent);
				if (centre_char == 9){
					cent = "0";
					leftside++;
				}
				else{
					centre_char++;
					cent = to_string(centre_char);
				}
				string left_side = to_string(leftside);
				n.replace(0, centre, left_side);
				reverse(left_side.begin(), left_side.end());
				n.replace(centre + 1, n_length - centre, left_side);
				n.replace(centre, 1, cent);
			}
			else{
				string left_side = to_string(leftside);
				n.replace(0, centre, left_side);
				reverse(left_side.begin(), left_side.end());
				n.replace(centre + 1, n_length - centre, left_side);
			}
			// cout << "After changing: " << n << endl;	
		}
	}
	// cout << "Next Palindrome: " << n << endl;
	return n;
}
 
int main(){
	int test_cases;
	string number;
	cin >> test_cases;
	for (int i=0; i< test_cases; i++){
		cin >> number;
		cout << get_next_palindrome(number) << endl;
	}
	return 0;
}