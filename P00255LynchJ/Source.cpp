// Jeremy Lynch, CS255, P00, Program takes input of two complex numbers and applies math operations to them.

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct ComplexNumber {
	double rNum;
	double iNum;
};

ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.rNum = num1.rNum + num2.rNum;
	result.iNum = num1.iNum + num2.iNum;

	return result;
}

ComplexNumber subtractComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.rNum = num1.rNum - num2.rNum;
	result.iNum = num1.iNum - num2.iNum;

	return result;
}

ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.rNum = (num1.rNum * num2.rNum) - (num1.iNum * num2.iNum);
	result.iNum = (num1.rNum * num2.iNum) + (num1.iNum * num2.rNum);

	return result;
}

ComplexNumber divideComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.rNum = ((num1.rNum * num2.rNum) + (num1.iNum * num2.iNum)) / (pow(num2.rNum, 2) + pow(num2.iNum, 2));
	result.iNum = ((num1.iNum * num2.rNum) - (num1.rNum * num2.iNum)) / (pow(num2.rNum, 2) + pow(num2.iNum, 2));

	return result;
}

ostream operator<<(ostream os, const ComplexNumber num)
{
	return os << num.rNum << " " << num.iNum << "i";
}

int main() {
	ComplexNumber num1;
	ComplexNumber num2;
	double rNum;
	double iNum;
	string leave = "y";

	do {
		cout << "Enter 1st complex number real and imaginary parts separated by space: ";
		cin >> rNum;
		cin >> iNum;
		num1.rNum = rNum;
		num1.iNum = iNum;

		cout << "\n";
		while (true) {
			cout << "Enter 2nd complex number real and imaginary parts (non-zero) separated by space: ";
			cin >> rNum;
			cin >> iNum;

			if (rNum != 0 && iNum != 0) {
				num2.rNum = rNum;
				num2.iNum = iNum;
				cout << "\n";
				break;
			}
			else {
				cout << ">>> ERROR: Both numbers must be non-zero -- try again! <<< \n\n";
			}
		}
		
		cout << "Results: ";
		cout << "\n    Addition Results: "        << addComplexNumbers(num1, num2);
		cout << "\n    Subtraction Results: "    << subtractComplexNumbers(num1, num2);
		cout << "\n    Multiplication Results: " << multiplyComplexNumbers(num1, num2);
		cout << "\n    Division Results: "       << divideComplexNumbers(num1, num2);

		cout << "\n\n\n";
		cout << "Run again (y or Y) or any other character to end? ";
		cin >> leave;
		cout << "\n";

	} while (leave == "y" || leave == "Y");

	return 0;
}