#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

#define eps 1e-9
#define inf int(2e9)
#define inflong (long long)(2e18)
#define forn(i, x, y) for (int i = (x); i <= (y); i++)
#define ford(i, y, x) for (int i = (y); i >= (x); i--)
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri 
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <LL> vl;
typedef pair<int, int> pii;

const int MaxN = int(2e5);
const LD pi = 3.1415926535897932384626433832795;

const int maxn = int(1e6 + 10);

LL a[maxn];
LL b[maxn];

LL n;

vector <LL> froma;
vector <LL> fromb; 

LL starta[maxn];
LL startb[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	
	for(LL i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for(LL i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	
	for(LL i = 0; i < n; i++)	
	{
		if(a[i] <= b[i])
		{
			froma.push_back(i);
		}
		else
			fromb.push_back(i);		
	}
	
   	LL x = -1;
   	LL y = -1;	
   
   	for(LL i = 0; i < (LL)froma.size(); i++)
   	{
   		if(froma[i] == x)
   			continue;
   			
   		if(x == -1)
   			x = froma[i];
   		else
   		{
   			if(a[froma[i]] > a[x])
   				x = froma[i];
   		}	
   	}

   	for(LL i = 0; i < (LL)fromb.size(); i++)	
   	{
   		if(fromb[i] == x)
   			continue;
   		
   		if(y == -1)
   			y = fromb[i];
   		else
   		{
   			if(b[fromb[i]] > b[y])
   				y = fromb[i];
   		}	
   	}	
   
   	LL suma = 0;
   	LL sumb = 0;
   	LL maxx = -1;
   	
   	for(LL i = 0; i < n; i++)
   	{
   		suma += a[i];
   		sumb += b[i];
   	
   		maxx = max(maxx, a[i] + b[i]);	
   	}
   	
   	LL ans = max(max(suma, sumb), maxx);
   	
   	cout << ans << endl;
   	
   	bool FLAG = false;
   	
   	if(x == -1 || (y != -1 && a[x] < b[y]))
   	{
		FLAG = true;
		
		for(LL i = 0; i < n; i++)
		{
			LL tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}

   		vector <LL> tmp = froma;
   		froma = fromb;
   		fromb = tmp;	
   	
   		LL ttmp = x;
   		x = y;
   		y = ttmp;
   	}
	
   	startb[x] = 0;
   	LL now1 = 0;
	LL now2 = b[x];
      
	for(LL i = 0; i < (LL)froma.size(); i++)
	{
		if(froma[i] == x)
   			continue;
   		
		starta[froma[i]] = now1;
		now1 += a[froma[i]];
	}
   	
	for(LL i = 0; i < (LL)froma.size(); i++)
	{
		if(froma[i] == x)
   			continue;
   		
		startb[froma[i]] = now2;
		now2 += b[froma[i]];
	}

	now1 = ans - a[x];
	starta[x] = now1;
	now2 = ans;
	
	for(LL i = 0; i < (LL)fromb.size(); i++)
	{
		if(fromb[i] == x)
   			continue;
   		
		now1 -= a[fromb[i]];
		starta[fromb[i]] = now1;
	}
	for(LL i = 0; i < (LL)fromb.size(); i++)
	{
		if(fromb[i] == x)
   			continue;
   		
		now2 -= b[fromb[i]];
		startb[fromb[i]] = now2;
	}

	for(LL i = 0; i < n; i++)
	{
		if(!FLAG)
			cout << starta[i] << " ";
		else
			cout << startb[i] << " ";
	}
	
	cout << endl;
	
	for(LL i = 0; i < n; i++)
	{
		if(FLAG)
			cout << starta[i] << " ";
		else
			cout << startb[i] << " ";
	}
	
	return 0;
}
