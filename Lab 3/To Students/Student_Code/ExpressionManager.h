#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
class ExpressionManager : public ExpressionManagerInterface {

public:
	ExpressionManager() {}
	~ExpressionManager() {}

	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

private:

	string toString(int data);
	string char_type(string str);
	int toNum(string data);
	int getPrecedence(string _char);
	bool validate_in(string data);
	
	const string OP[5] = { "*", "/", "+", "-", "%" };
	const string OPEN_P[3] = { "[", "(", "{" };
	const string CLOSE_P[3] = { "]", ")", "}" };
	const string VALID_OPAND[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	const string VALID_IN[22] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "]", ")", "}", "[", "(", "{", "*", "/", "+", "-", "%", " " };
};