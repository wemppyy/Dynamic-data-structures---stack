#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkBrackets(string str) {
	stack <char> s;
	int i = 0;

	while (i < str.length()) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (s.empty()) {
				cout << "Error: Closing bracket without opening bracket" << endl;
				return;
			}
			char c = s.top();
			s.pop();
			if (str[i] == ')' && c != '(') {
				cout << "Error: Closing bracket without opening bracket" << endl;
				return;
			}
			if (str[i] == ']' && c != '[') {
				cout << "Error: Closing bracket without opening bracket" << endl;
				return;
			}
			if (str[i] == '}' && c != '{') {
				cout << "Error: Closing bracket without opening bracket" << endl;
				return;
			}
		}
		i++;
	}
	if (!s.empty()) {
		cout << "Error: Opening bracket without closing bracket" << endl;
	}
	else {
		cout << "Brackets are correct" << endl;
	}
}

int main() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	checkBrackets(str);
	return 0;
}
