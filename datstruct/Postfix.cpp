#include<bits/stdc++.h>
using namespace std;

string operatorList = "+-*/^";

int power(int x, int y) {
	int ans = 1;
	while (y--) ans *= x;
	return ans;
}

bool isOperator(char op) {
	for (auto c: operatorList) {
		if (c == op) return true;
	}
	return false;
}

int calculate(int x, int y, char op) {
	if (op == '+') return x + y;
	if (op == '-') return y - x;
	if (op == '*') return x * y;
	if (op == '/') return y / x;
	if (op == '^') return power(y, x);
	return -1;
}

int priority(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	return -1;
}

string toPostFix(string S) {
	string ans = "";
	stack<char> st;
	for (auto c: S) {
		if (c == '(') st.push(c);
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (isOperator(c)) {
			while (!st.empty() && priority(c) <= priority(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}
		else {
			ans += c;
		}
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	return ans;
}

int evaluatePostFix(string S) {
	stack<int> st;
	for (auto c: S) {
		if (isOperator(c)) {
			int top1 = st.top(); st.pop();
			int top2 = st.top(); st.pop();
			st.push(calculate(top1, top2, c));
		}
		else {
			st.push(c - '0');
		}
	}
	return st.top();
}

int main() {
	string S;
	cin >> S;
	cout << toPostFix(S) << endl;
	cout << evaluatePostFix(toPostFix(S)) << endl;
	return 0;
}
