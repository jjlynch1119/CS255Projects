

/*
string InfixToPostfix::postfix() {

	allocate a local variable ExpressionSymbol op
	allocate a local variable ch

	for (int i =0; i < infixExpression.length(); i++ {   e.g. 1+2/3^6*7
		ch = infixExpression[i]; // assign ch the ith character in the string

		ch is a digit ...
			add it to postfix
			add a space to postfix

		ch is an operator or lparen (opening)
			op = ExpressionSymbol(ch) // create an expression symbol and store in op
			test if things have to come off stack and be added to postfix -- outputHigherOrEqual
			push op on the stack

		ch is a ) rparen (closing)
			op = ExpressionSymbol(ch) // create an expression symbol and store in op
			get up to the left paren off the stack -- hopefully finding a lparen   -- outputHigherOrEqual
			if the stack is empty
				throw ExpressionError("infixtopostfix missing "(")
			else
				operatorStack.pop() .... throw away the left paren
		ch is not whitespace
			throw ExpressionError("InfixToPostfix: Invalid input");

	} // end for

	************ Now have to clean up // finish what might be left on the stack **************

	finish reading top and popping pop the remain operators off the stack
		if op popped is a (
			you are missing a rparen and should throw an exeption
		otherwise
			add the operator to the postfix


	return postfixEexpression; // this gets returned to main.

} // end postfix()
