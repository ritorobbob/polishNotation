#include<iostream>
#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;

bool isOperand(char chr);
int getIP(char chr);
int getSP(char chr);

void main() {
	string infixInput = "A*(B+D)/E-F*(G+H/K)";
	stack<char> infix;
	stack<char> op;
	stack<char> prefix;
	infix.push('#');
	for (auto& item : infixInput)
		infix.push(item);
		
	char iNext;

	while (infix.top() != '#') {
		iNext = infix.top();
		if (iNext == '(') {
			while (op.top() != ')') {
				prefix.push(op.top());
				op.pop();
			}
			op.pop();
		}else if (isOperand(iNext))
			prefix.push(iNext);
		else {
			if (!op.empty() && getIP(iNext) < getSP(op.top())) {
				prefix.push(op.top());
				op.pop();
			}
			op.push(iNext);
		}
		infix.pop();
	}
	while (!op.empty()) {
		prefix.push(op.top());
		op.pop();
	}

	while (!prefix.empty()) {
		cout << prefix.top();
		prefix.pop();
	}

	cout << endl;
	system("pause");
}

bool isOperand(char chr) {
	switch (chr) {
	case '*': return 0;
	case '/': return 0;
	case '-': return 0;
	case '+': return 0;
	case ')': return 0;
	case '^': return 0;
	default: return 1;
	}
}
int getIP(char chr) {
	switch (chr) {
	case '*': return 2;
	case '/': return 2;
	case '+': return 1;
	case '-': return 1;
	case '^': return 4;
	case ')': return 4;
	default: return -1;
	}
}
int getSP(char chr) {
	switch (chr) {
	case '*': return 2;
	case '/': return 2;
	case '+': return 1;
	case '-': return 1;
	case '^': return 3;
	case ')': return 0;

	default: return -1;
	}
}