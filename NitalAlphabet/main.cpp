#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char,string> make_graph() {
	map<char, string> graph;
	string prev;
	string next;
	ifstream f("input.txt");
	getline(f, prev);

	int numberOfWords = stoi(prev);
	getline(f, prev);
	for (int i = 0; i < prev.size(); i++){
		if (graph.find(prev[i]) == graph.end())//проверка
			graph.emplace(prev[i], "0");
	}

	for (int i = 0; i < numberOfWords; i++)	{
		getline(f, next);
		int j = 0;
		for (; j < min({ prev[j], next[j] }); j++) {
			if (graph.find(next[j]) == graph.end())//проверка
				graph.emplace(next[j], "0");
			if (prev[j] != next[j])	{
				graph[prev[j]] += next[j];
				break;
			}
		}
		for (; j < next.size(); j++){
			if (graph.find(next[j]) == graph.end())//проверка
				graph.emplace(next[j], "0");
		}
		j = 0;

		prev = next;
	}

	return graph;
}

void dfs_visit(map<char, string> & g, char v, string & res) {
	
	g[v][0] = '1'; //1 - gray

	for (int i = 1; i < g[v].size(); i++)
	{
		if (g[g[v][i]][0] == '1') { //cycle
			res = "-";
			return;
		}

		if (g[g[v][i]][0] == '0')
			dfs_visit(g, g[v][i], res);
	}

	g[v][0] = '2'; //2 - black
	if (res != "-")
		res = v + res;
}

void dfs(map<char, string>& g, string & res) {
	for (pair<char, string> v : g)
	{
		v.second[0] = '0'; //0 - white
	};

	for (pair<char, string> v : g)
	{
		if (v.second[0] == '0')
			dfs_visit(g, v.first, res);
	};
}

int main() {
	setlocale(LC_ALL,"");

	map<char, string> graph = make_graph();

	string result;

	dfs(graph, result);

	cout << result;

	return 0;
 }