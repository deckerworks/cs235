#include "ExpressionManager.h"

using namespace std;

bool ExpressionManager::validate_in(string expression_import)
{
	bool valid = true;
	stringstream str(expression_import);
	string val;

	while (!str.eof() && valid) {

		str >> val;
		bool valid_char = true;

		for (int i = 0; i < val.length() && valid_char == true; i++) {
			string sub = val.substr(i, 1);
			valid_char = false;
				for (int j = 0; j < 21 && valid_char == false; j++) {
					if (sub == VALID_IN[j]) {
						valid_char = true;
					}
				}
			}

		valid = valid_char;
	}

	return valid;
}

string ExpressionManager::char_type(string expression_import)
{
	string type = "";

	for (int j = 0; j < expression_import.length() && type != "invalid"; j++) {
		for (int i = 0; i < 3 && type == ""; i++) {
			if (expression_import.substr(j, 1) == OPEN_P[i]) {
				type = "open_paren";
			}
			else if (expression_import.substr(j, 1) == CLOSE_P[i]) {
				type = "close_paren";
			}
		}

		for (int i = 0; i < 5 && type == ""; i++) {
			if (expression_import.substr(j, 1) == OP[i]) {
				type = "operator";
			}
		}

		for (int i = 0; i < 10 && type == ""; i++) {
			if (expression_import.substr(j, 1) == VALID_OPAND[i]) {
				type = "operand";
			}
		}

		if (type == "") {
			type = "invalid";
		}
	}

	return type;
}

int ExpressionManager::getPrecedence(string _char)
{
	int precedence = 1;

	for (int i = 0; i < 3; i++) {
		if (_char == OPEN_P[i]) precedence = 0;
	}

	if (_char == "/" || _char == "*" || _char == "%") precedence = 2;

	return precedence;
}

bool ExpressionManager::isBalanced(string expression)
{
	string result = "";
	if (!validate_in(expression))
		result = "invalid";

	bool balanced = true;
	stack<string> stack;
	stringstream exp(expression);

	string item; // Will hold each item as it is pulled out of the string
	while (!exp.eof() && balanced == true && result != "invalid") {
		exp >> item;
		for (int i = 0; i < 3; i++) {
			if (item == OPEN_P[i]) {
				stack.push(item);
			}
			else if (item == CLOSE_P[i]) {
				string match;
				if (stack.size() > 0) {
					string match = stack.top();
					if (match != OPEN_P[i]) {
						balanced = false;
					}
					stack.pop();
				}
				else
					balanced = false;
			}
		}
	}
	if (result == "invalid")
		balanced = false;
	else if (stack.size() > 0) 
		balanced = false;

	return balanced;
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	stringstream str(postfixExpression);
	stack<string> operands;
	string result = "";

	if (!validate_in(postfixExpression)) result = "invalid";

	string token;
	while (!str.eof() && result != "invalid") {
		str >> token;

		string type = this->char_type(token);
		if (type == "open_paren" || type == "close_paren") {
			result = "invalid";
		}
		else if (type == "operand") {
			operands.push(token);
		}
		else if (type == "operator") {
			if (operands.size() < 2) {
				result = "invalid";
			}
			else {
				string right_operand = operands.top();
				operands.pop();
				string left_operand = operands.top();
				operands.pop();

				result = "( " + left_operand + " " + token + " " + right_operand + " )";

				operands.push(result);
			}
		}
		else {
			result = "invalid";
		}
	}

	if (operands.size() != 1) {
		result = "invalid";
	}

	return result;
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	stringstream str(infixExpression);
	stack<string> operators;
	stack<string> operands;
	string result = "";
	string token;

	if (!isBalanced(infixExpression)) 
		result = "invalid";
	if (!validate_in(infixExpression)) 
		result = "invalid";

	bool first = true;
	while (str >> token && result != "invalid") {

		string type = this->char_type(token);
		if (first) {
			if (type != "open_paren" && type != "operand")
				result = "invalid";
			first = false;
		}

		if (result == "invalid") {}
		else if (type == "operand") {
			operands.push(token);
		}
		else if (type == "open_paren") {
			operators.push(token);
		}
		else if (type == "close_paren") {
			while (operators.size() > 0 && operators.top() != "(") {
				string right_operand = operands.top();
				operands.pop();
				string left_operand = operands.top();
				operands.pop();
				string op = operators.top();
				operators.pop();

				string eval = left_operand + " " + right_operand + " " + op;
				operands.push(eval);
			}
			operators.pop(); // pop off the open paren
		}
		else if (type == "operator") {
			if (operators.size() == 0) {
				operators.push(token);
			}
			else {
				if (getPrecedence(token) > getPrecedence(operators.top())) {
					operators.push(token);
				}
				else {
					while (operators.size() > 0
						&& (getPrecedence(token) <= getPrecedence(operators.top()))
						&& operators.top() != "("
						&& result != "invalid") {
						if (operands.size() >= 2) {
							string right_operand = operands.top();
							operands.pop();
							string left_operand = operands.top();
							operands.pop();
							string op = operators.top();
							operators.pop();

							result = left_operand + " " + right_operand + " " + op;
							operands.push(result);
						}
						else {
							result = "invalid";
						}
					}
					operators.push(token);
				}
			}
		}
		else {
			result = "invalid";
		}
	}
	if (result != "invalid") {
		while (operands.size() >= 2) {
			string right_operand = operands.top();
			operands.pop();
			string left_operand = operands.top();
			operands.pop();
			string op = operators.top();
			operators.pop();

			string eval = left_operand + " " + right_operand + " " + op;
			operands.push(eval);
		}
		result = operands.top();
		while (operators.size() > 0) {
			string op = operators.top();
			operators.pop();
			result += " ";
			result += op;
		}
	}
	return result;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	stringstream str(postfixExpression);
	stack<int> operands;
	string result = "";

	if (!validate_in(postfixExpression)) result = "invalid";

	string _char;
	while (!str.eof() && result != "invalid") {
		str >> _char;

		string type = this->char_type(_char);
		if (type == "open_paren" || type == "close_paren") {
			result = "invalid";
		}
		else if (type == "operand") {
			//int op = toNum(_char);
			operands.push(toNum(_char));
		}
		else if (type == "operator") {
			if (operands.size() < 2) {
				result = "invalid";
			}
			else {
				int right_operand = operands.top();
				operands.pop();
				int left_operand = operands.top();
				operands.pop();

				int op_result; // the result of the operation
				if (_char == "+") 
					op_result = left_operand + right_operand;
				else if (_char == "-") 
					op_result = left_operand - right_operand;
				else if (_char == "*") 
					op_result = left_operand * right_operand;
				else if (right_operand == 0) {
					op_result = 0;
					result = "invalid";
				}
				else if (_char == "/") 
					op_result = left_operand / right_operand;
				else if (_char == "%") 
					op_result = left_operand % right_operand;
				operands.push(op_result);
			}
		}
		else {
			result = "invalid";
		}
	}

	if (operands.size() != 1) {
		result = "invalid";
	}

	if (result != "invalid")
		result = toString(operands.top());

	return result;
}

string ExpressionManager::toString(int data)
{
	stringstream in;
	in << data;
	string result;
	in >> result;
	return result;
}

int ExpressionManager::toNum(string data)
{
	stringstream in(data);
	int result;
	in >> result;
	return result;
}