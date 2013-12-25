#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

const int maxn = 100;
const int INF = (int)1e9;

int main()
{
	freopen("text.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	
	int inputArray[maxn][maxn];
	int minInArray[maxn];
	int maxInArray[maxn];
	
	for(int i = 0; i < maxn; i++)
		minInArray[i] = INF;
	for(int i = 0; i < maxn; i++)
		maxInArray[i] = -INF;
		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> inputArray[i][j];
			minInArray[i] = min(minInArray[i], inputArray[i][j]);
			maxInArray[j] = max(maxInArray[j], inputArray[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(inputArray[i][j] == minInArray[i] && inputArray[i][j] == maxInArray[j])
				cout << inputArray[i][j] << "(" << i << ", " << j << ")" << endl;
		}
	}
	
	return 0;
}