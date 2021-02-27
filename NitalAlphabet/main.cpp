#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, char> make_graph(string file) 
{
	map<char, char> res;

	string prev;
	string next;

	ifstream f("input.txt");
	getline(f, next);

	getline(f, prev);
	while (f >> next)
	{
		//cout << temp << endl;
		//cout << input << endl;
		for (size_t i = 0; i < min({ prev[i], next[i] }); i++)
		{
			if (prev[i] != next[i])
				res.insert(make_pair(prev[i], next[i]));
		}

		prev = next;
	}

	return res;
}

void dfs() {}

int main() 
{
	/*string input;
	ifstream file("ex.txt");
	while (file >> input) 
	{
		cout << input << endl;
	}*/

	/*
	string temp;
	string input;

	ifstream f("input.txt");
	getline(f, input);

	getline(f, temp);
	while (f >> input)
	{
		cout << temp << endl;
		cout << input << endl;
		temp = input;
	}*/

	/*
	map<char, char> res;

	string prev;
	string next;

	ifstream f("input.txt");
	getline(f, next);

	getline(f, prev);
	while (f >> next)
	{
		//cout << temp << endl;
		//cout << input << endl;
		for (size_t i = 0; i < min({ prev[i], next[i] }); i++)
		{
			if (prev[i] != next[i])
				res.emplace(prev[i], next[i]);
		}
		prev = next;
	}*/

	for (pair<char, char> x : make_graph("input.txt"))
	{
		cout << x.first << x.second << endl;
	}

	return 0;
}