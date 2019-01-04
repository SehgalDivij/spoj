#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

using namespace std;

void show_expr(string expression){
	string op, spaces;
	int cur_op, max_len = 0;
	if (expression.find('+') != string::npos){
		op = "\\+";
	}
	else{
		if (expression.find('-') != string::npos){
			op = "\\-";
		}
		else{
			op = "\\*";
		}
	}
	std::regex regex(op);
	std::vector<std::string> ops(
		std::sregex_token_iterator(expression.begin(), expression.end(), regex, -1),
		std::sregex_token_iterator()
	);
	if(!op.compare("\\*")){
		int final_prod = 0;
		if (ops.at(1).length() > 1){
			ops.push_back(string(max(ops.at(0).length(), ops.at(1).length() + 1), '-'));
			for (int i=ops.at(1).length() - 1; i>=0; i--){
				cur_op = stoi(ops.at(0)) * (ops.at(1).at(i) - '0');
				spaces = "";
				for (int j=0;j<ops.at(1).length() - i - 1;j++){
					spaces += " ";
				}
				final_prod += (cur_op * pow(10,spaces.length()));
				if (max_len < (to_string(cur_op) + spaces).length())
					max_len = (to_string(cur_op) + spaces).length();
				ops.push_back(to_string(cur_op) + spaces);
			}
			ops.push_back(string(max_len, '-'));
			ops.push_back(to_string(final_prod));
		}
		else{
			final_prod = stoi(ops.at(0)) * stoi(ops.at(1));
			max_len = to_string(final_prod).length();
			ops.push_back(string(max_len, '-'));
			ops.push_back(to_string(final_prod));
		}
		ops[1] = "*" + ops[1];
	}
	if (!op.compare("\\+")){
		max_len = max(ops.at(0).length(), ops.at(1).length() + 1);
		ops.push_back(string(max_len, '-'));
		ops.push_back(to_string(stoi(ops.at(0)) + stoi(ops.at(1))));
		ops[1] = "+" + ops[1];
	}
	if (!op.compare("\\-")){
		max_len = max(ops.at(0).length(), ops.at(1).length() + 1);
		ops.push_back(string(max_len, '-'));
		ops.push_back(to_string(stoi(ops.at(0)) - stoi(ops.at(1))));
		ops[1] = "-" + ops[1];
	}
	for(int i=0; i<ops.size(); i++){
		cout << string(max_len - ops.at(i).length(), ' ') + ops[i] << endl;
	}
	cout << endl;
}


int main(){
	int test_cases;
	string expression;
	cin >> test_cases;
	for (int i=0; i< test_cases; i++){
		cin >> expression;
		show_expr(expression);
	}
	return 0;
}