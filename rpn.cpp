/*
 * Solution to the problem at: https://www.spoj.com/problems/ONP
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>

using namespace std;

int LEFT = 0, RIGHT = 1;

struct info {
	int pre, ass;
};

map<char, info> operators {
	{'+', {0, LEFT}},
	{'-', {0, LEFT}},
	{'*', {5, LEFT}},
	{'/', {5, LEFT}},
	{'^', {10, RIGHT}}
};

string get_rpn(string ip_exp){
	int expr_size = ip_exp.size();
	stack<char> op_stack;
	string rpn_exp = "";
	for(int i=0; i<expr_size;i++){
		char cur_char = ip_exp.at(i);
		bool is_true = operators.find(cur_char) != operators.end();
		switch(cur_char){
			case '(':
				op_stack.push(cur_char);
				break;
			case ')':
				while(op_stack.top() != '('){
					rpn_exp.append(1, op_stack.top());
					op_stack.pop();
				}
				if(op_stack.top() == '(')
					op_stack.pop();
				break;
			default:
				if (operators.find(cur_char) != operators.end()){
					// check if top of stack is 
					// cout << cur_char << endl;
					// cout << operators.find(cur_char) -> first << endl;
					// cout << operators.find(cur_char) -> first << " ::::: " << operators.find(cur_char) -> second.pre << " ::::: " << operators.find(cur_char) -> second.ass << endl;
					while(operators.find(op_stack.top()) != operators.end() && (
					  	  (operators.find(cur_char) -> second.ass == LEFT && operators.find(cur_char) -> second.pre <= operators.find(op_stack.top())-> second.pre) || 
						  (operators.find(cur_char) -> second.ass == RIGHT && operators.find(cur_char) -> second.pre < operators.find(op_stack.top()) -> second.pre)
						  )
						){
						rpn_exp.append(1, op_stack.top());
						op_stack.pop();
					}
					op_stack.push(cur_char);
				}
				else
					rpn_exp.append(1, cur_char);
				break;
		}
	}
	return rpn_exp;
}


int main(){
	int test_cases;
	string expression;
	cin >> test_cases;
	for (int i=0; i< test_cases; i++){
		cin >> expression;
		cout << get_rpn(expression) << endl;
	}
	return 0;
}