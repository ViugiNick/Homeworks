#include <cstdio>
#include <string.h>
#include <iostream>


using namespace std;

const int maxn = 100;

char dfs(int x, bool* & used, int **g, int n, char c)
{
	cerr << x << " " << c << endl;
	used[x] = true;
	for(int i = 0; i < n; i++)
	{
		if(g[x][i] != 0 && !used[i])
			c = dfs(i, used, g, n, c + 1);
	}
	return c;
}

int main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int** g = new int*[n];
	bool* used = new bool[n];
	
	for(int i = 0; i < n; i++) 
	{
		g[i] = new int[n];
		for(int j = 0; j < n; j++) 
		{
			g[i][j] = 0;
		}
		used[i] = false;
	}	
	
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		
		g[a][b] = 1;
		g[b][a] = 1;
	}
	
	dfs(1, used, g, n, 'a');

	for(int i = 0; i < n; i++) 
		delete[] g[i];
	delete[] g;
	delete[] used;
	
	return 0;
}