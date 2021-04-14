#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


/*

struct vertex 
{
	char symbol;
	int color; // 0 = белый, 1 = серый, 2 = чёрный
	int in;
	int out; //отметки времени входа и выхода при обходе в глубину
	//vertex p; //родитель
	vector<vertex> adj; //вершины, в которые существуют дуги из данной

	vertex(char s) :symbol(s)
	{
		this->color = 0;
		this->in = -1;
		this->out = -1;
		vector<vertex> ad;
		this->adj = ad;
	}

	vertex(char s, char a): symbol(s)
	{
		this->color = 0;
		this->in = -1;
		this->out = -1;
		vector<vertex> ad;
		ad.push_back(vertex(a));
		this->adj = ad;
	}

	/*
	int getColor() 
	{
		return this->color;
	}

	void setColor(int c) 
	{
		this->color = c;
	}
	*/

/*
	void print()
	{
		cout << "символ в данной вершине: " << this->symbol << endl;
		cout << "цвет вершины: " << this->color << endl;
		cout << "время входа в вершину: " << this->in << endl;
		cout << "время выхода из вершины: " << this->out << endl;
		cout << "вершины-потомки: " << endl;
		for (vertex v : adj) 
		{
			cout << "	" << v.symbol << endl;
		}
		cout << endl;
	}
};


struct graph 
{
	vector<vertex> vertices;

	

	graph() 
	{
		vector<vertex> v;
		this->vertices = v;
	}

	void add_vertex(vertex u) 
	{
		for (vertex v : this->vertices) 
		{
			if (v.symbol == u.symbol)
				return;
		}
		this->vertices.push_back(u);
	}

	/*
	void update_vertex(vertex u) 
	{
		for (vertex v : this->vertices)
		{
			if (v.symbol == u.symbol)
				v = u;
		}
	}
	*/

/*
	void print() 
	{
		for (vertex v : this->vertices) 
		{
			v.print();
		}
	}
};

graph make_graph(string file)
{
	graph res;

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
			{
				res.add_vertex(vertex(prev[i], next[i]));
				res.add_vertex(vertex(next[i]));
				break;
			}
		}

		prev = next;
	}

	return res;
}

void dfs_visit(vertex & u, int & time, vector<vertex> & toUpdate)
{
	u.color = 1;
	time = time + 1;
	u.in = time;
	for (vertex v : u.adj) 
		{
		if (v.color == 0)
			//pi?
			dfs_visit(v, time, toUpdate);
		}
	u.color = 2;
	time = time + 1;
	u.out = time;
	toUpdate.push_back(u);
}

void dfs(graph & g)
{
	for (vertex & u : g.vertices)
	{
		u.color = 0;
		//pi?
	}
	int time = 0;
	vector<vertex> toUpdate;
	for (vertex & u : g.vertices)
	{
		if (u.color == 0)
			dfs_visit(u, time, toUpdate);
	}
	/*for (vertex & u : toUpdate) 
	{
		g.update_vertex(u);
	}*/
		//string
map<char,string> make_graph() {
	map<char, string> graph;
	string prev;
	string next;
	ifstream f("input.txt");
	getline(f, prev);

	/*
	getline(f, prev);
	for (char c : prev) 
	{
		vertices.insert(c);
	}*/
	//while (f >> next)

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

	/*
	for (pair<char, string> x : graph)
	{
		cout << x.first << ": " << x.second << endl;
	}
	*/

	string result;

	dfs(graph, result);

	/*
	for (pair<char, string> x : graph)
	{
		cout << x.first << ": " << x.second << endl;
	}
	*/

	cout << result;

	return 0;
 }