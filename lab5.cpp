#include "Header.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;
enum constants {
	add, get, del
};

using namespace std;
int main()
{
	const map<string, constants> comands = { { "add", constants::add },{ "get", constants::get },{ "del", constants::del } };
	int n;
	cin >> n;
	string line, word;
	PriorQueue<int> que;
	cin.get();
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		istringstream ss(line);
		ss >> word;
		try {
			switch (comands.at(word)) {
			case constants::add:
				int value;
				ss >> value;
				que.push(value);
				break;
			case constants::get:
				try {
					cout << que.top() << endl;
				}
				catch (...) {
					cout << "Stack is empty" << endl;
				}
				break;
			case constants::del:
				que.pop();
				break;
			}
		}
		catch (...) {
			cout << "Unknown command" << endl;
		}
	}

	return 0;
}
