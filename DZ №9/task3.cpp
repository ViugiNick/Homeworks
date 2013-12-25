#include <cstdio>
#include <string.h>
#include <iostream>


using namespace std;

const int maxn = 100;
const int INF = (int)1e9;

/*
	-1 отсутствие ребра
*/

int main()
{
	freopen("text.in", "r", stdin);
	
	bool used[maxn];
	int g[maxn][maxn];
	int minnEdge[maxn];
	int minnVertex[maxn];
	
	for(int i = 0; i < maxn; i++)
		minnEdge[i] = INF;
	for(int i = 0; i < maxn; i++)
		minnVertex[i] = -1;	
	minnEdge[0] = 0;

	int n = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			
			if(tmp == -1)
			{
				g[i][j] = INF;
			}
			else
			{
				g[i][j] = tmp;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) 
	{
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || minnEdge[j] < minnEdge[v]))
				v = j;
		
		used[v] = true;
		if (minnVertex[v] != -1)
			cout << v << " " << minnVertex[v] << endl;
 
		for (int to=0; to<n; ++to)
			if (g[v][to] < minnEdge[to]) 
			{
				minnEdge[to] = g[v][to];
				minnVertex[to] = v;
			}
	}
	
	return 0;
}