#include <iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int test(char opration)
{
	if (opration == '+' || opration == '-')
		return 1;
	else
		return 2;
}
int main()
{
	string equation = "", postfix = "";
	int n = 0;
	stack<char> opration;
	cout << "please inter infix\n";
	cin >> equation;
	for (int i = 0; i < equation.length(); i++)
	{
		if (isdigit(equation[i]))
		{
			postfix += equation[i];
			cout << postfix << "\n";
		}
		else if (equation[i] == '(')
			opration.push(equation[i]);
		else if (equation[i] == ')')
		{
			while (opration.top() != '(')
			{
				postfix += opration.top();
				cout << postfix << "\n";
				opration.pop();
			}
			opration.pop();
		}
		else
		{
			while (test(equation[i]) <= test(opration.top()))
			{
				postfix += opration.top();
				cout << postfix << "\n";
				opration.pop();
			}
			opration.push(equation[i]);
		}
	}
	while (!opration.empty())
	{
		postfix += opration.top();
		cout << postfix << "\n";
		opration.pop();
	}
	return 0;
};