// TO BE COMPLETED:
//		postfix()

// SOLUTION: InfixToPost.h
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

// labels designating the parentheses characters
const char lParen = '(';
const char rParen = ')';

class InfixToPostfix
{
public:
	// default constructor. infix expression is NULL string
	InfixToPostfix();

	// initialize the infix expression
	InfixToPostfix(const string& infixExp);

	// change the infix expression
	void setInfixExp(const string& infixExp);

	// return a string that contains the equivalent postfix expression.
	//   The function throws ExpressionError if an error occurs during conversion
	string postfix();

private:
	// the infix expression to convert
	string infixExpression;

	// built to contain the postfix equivalent of infixExpression
	string postfixExpression;

	// stack of expressionSymbol objects
	myStack<ExpressionSymbol> operatorStack;

	// The expressionSymbol object op holds the current symbol.
	//   Pop the stack and output as long as the symbol
	//   on the top of the stack has a precedence >= that of
	//   the current operator
	void outputHigherOrEqual(const ExpressionSymbol& op);

	// is ch one of '+','-','*','/', '^'
	bool isOperator(char ch) const;
};

// Determine which operators need to be popped from stack
//	before adding the new operator, "op"
//  Determines whether operator left on the stack should be output before
//  pushing operator right on the stack
void InfixToPostfix::outputHigherOrEqual(const ExpressionSymbol& op) {
	ExpressionSymbol op2;

	while (!operatorStack.isEmpty() && (op2 = operatorStack.top()) >= op) {
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool InfixToPostfix::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

InfixToPostfix::InfixToPostfix() {}

InfixToPostfix::InfixToPostfix(const string& infixExp) : infixExpression{ infixExp } {}

void InfixToPostfix::setInfixExp(const string& infixExp) {
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string InfixToPostfix::postfix() {
						/**** TO BE COMPLETED *****/
	/* allocate a local variable ExpressionSymbol op
		allocate a local variable ch

		for (int i = 0; i < infixExpression.length(); i++ {   e.g. 1 + 2 / 3 ^ 6 * 7
			ch = infixExpression[i]; // assign ch the ith character in the string

			ch is a digit ...
			add it to postfix
			add a space to postfix

			ch is an operator or lparen(opening)
			op = ExpressionSymbol(ch) // create an expression symbol and store in op
			test if things have to come off stackand be added to postfix -- outputHigherOrEqual
			push op on the stack

			ch is a) rparen(closing)
			op = ExpressionSymbol(ch) // create an expression symbol and store in op
			get up to the left paren off the stack -- hopefully finding a lparen   -- outputHigherOrEqual
			if the stack is empty
				throw ExpressionError("infixtopostfix missing "(")
			else
					operatorStack.pop() .... throw away the left paren
					ch is not whitespace
					throw ExpressionError("InfixToPostfix: Invalid input");

		} // end for

	************Now have to clean up // finish what might be left on the stack **************

		finish reading topand popping pop the remain operators off the stack
		if op popped is a(
			you are missing a rparen and should throw an exeption
			otherwise
			add the operator to the postfix


			return postfixEexpression; // this gets returned to main. */

	ExpressionSymbol op;
	char ch;

	for (int i = 0; i < infixExpression.length(); i++) {
		ch = infixExpression[i];

		if (isdigit(ch)) {
			postfixExpression.push_back(ch);
			postfixExpression + " ";
		}
		else if (isOperator(ch)) {
			op = ExpressionSymbol(ch);
			outputHigherOrEqual(ch);
		}
		else if (ch == ')') {
			op = ExpressionSymbol(ch);

			outputHigherOrEqual(ch);

			if (operatorStack.isEmpty() == true) {
				throw ExpressionError("infixtopostfix missing (");
			}
			else {
				operatorStack.pop();
				throw ExpressionError("InfixToPostfix: Invalid input");
			}

		}

		if (op)

	}
} //end postfix()
#endif	// INFIX_TO_POSTFIX

