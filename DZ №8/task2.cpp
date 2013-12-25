#include <cstdio>
#include <string.h>
#include <iostream>


using namespace std;

const int maxn = 100;
const int INF = (int)1e9;

void qSort(int left, int right, int * inputArray, int * arrayIndex)
{
	int i = left; 
	int j = right; 
  	
	int m = inputArray[(i + j) / 2];
	int temp = 0;
	
	do
  	{
		while (inputArray[i] < m) 
		{
			i++; 
		}
        
		while (inputArray[j] > m)
		{	
			j--; 
		}
        
		if (i <= j)
		{
			temp = inputArray[i]; 
			inputArray[i] = inputArray[j]; 
			inputArray[j] = temp;
			
			temp = arrayIndex[i]; 
			arrayIndex[i] = arrayIndex[j]; 
			arrayIndex[j] = temp;
			
			i++; 
			j--;
		}
	}
	while (i <= j);    
  
  
	if (left < j) 
	{
		qSort(left, j, inputArray, arrayIndex);
	}
  	
	if (i < right)
	{
		qSort(i, right, inputArray, arrayIndex); 
	}
}

void rec(int l, int r, int ** p)
{
	if(p[l][r] == -1)
		cout << l + 1 << ":" << r + 1 << " ";
	else
	{
		rec(l, p[l][r], p);
		rec(p[l][r], r, p);
	}
}

int main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int** g = new int*[n];
	int** p = new int*[n];
	
	bool* used = new bool[n];
	int* inputArray = new int[n];
	int* arrayIndex = new int[n];
	
	for (int i = 0; i < n; i++) 
	{
		g[i] = new int[n];
		for (int j = 0; j < n; j++) 
		{
			g[i][j] = 0;
		}
		
		p[i] = new int[n];
		for (int j = 0; j < n; j++) 
		{
			p[i][j] = 0;
		}
		used[i] = false;
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
		{
			g[k][i] = INF;
			p[k][i] = -1;
		}
		
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		
		g[a][b] = c;
		g[b][a] = c;
	}
	
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][k] < INF && g[k][j] < INF)
					if(g[i][j] > g[i][k] + g[k][j])
					{
						g[i][j] = g[i][k] + g[k][j];
						p[i][j] = k;
					}
					
	for(int i = 1; i < n; i++)
	{
		arrayIndex[i - 1] = i;
		inputArray[i - 1] = g[0][i];
	}

	qSort(0, n - 1, inputArray, arrayIndex);
	for(int i = 0; i < n - 1; i++)
	{
		cout << "Vertex number : " << arrayIndex[i] + 1 << ") Distance is : " << inputArray[i] << " -  The path is ";
		rec(0, arrayIndex[i], p);
		cout << endl;
	}
	
	for(int i = 0; i < n; i++) 
		delete[] g[i];
	delete[] g;
	
	for(int i = 0; i < n; i++) 
		delete[] p[i];
	delete[] p;
	
	delete[] used;
	delete[] arrayIndex;
	delete[] inputArray;
	
	return 0;
}