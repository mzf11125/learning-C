#include<bits/stdc++.h>
using namespace std;

bool balanced(string S) {
	stack<char> st;
	for (auto c: S) {
		if (c == '(' || c == '[') st.push(c);
		else {
			if (st.empty()) return false;
			if (c == ']' && st.top() == '(') return false;
			if (c == ')' && st.top() == '[') return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	string S;
	cin >> S;
	if (balanced(S)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
