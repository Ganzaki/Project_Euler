/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler15      *
*                                   *
* * * * * * * * * * * * * * * * * * *
*/
#include <bits/stdc++.h>


#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define FOR1(i,j,k) for(ll i=j;i<=k;i++)
#define FOR2(i,j,k) for(ll i=j;i>=k;i--)
#define FILL(a,i) memset(a,i,sizeof(a))
#define dbg(...) do{\
	fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_do(__VA_ARGS__);\
}while(0)


using namespace std;


typedef long long ll;
typedef unsigned long ul;
typedef std::string str;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef std::vector<str> vs;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<char> vc;
typedef map<int,int> mii;
typedef map<string,int> msi;

void desperate_optimization(int precision){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(precision);
}


ll MAX = 1e+9 + 7;
ll a[510][510];


void Set()
{
	FOR(i,0,501)
	{
		a[i][0] = 1;
	}
	FOR(i,0,501)
	{
		a[0][i] = 1;
	}
	FOR(i,1,501)
	{
		FOR(j,1,501)
		{
			a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MAX;
			//a[i][j] = (a[i - 1][j] + a[i][j - 1]);
		}        
	}
}


void solve()
{
	ll n;
	ll m;
	cin>>n;
	cin>>m;
	cout << a[n][m] << endl;
}



int main()
{
	desperate_optimization(10);
	FILL(a,0);
	int t;
	Set();
	cin>>t;
	while(t--)
		solve();
	return 0;
}