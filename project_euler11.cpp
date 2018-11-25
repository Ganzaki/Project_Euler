/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler11      *
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
ll MAX = 1e+9 + 7;

void desperate_optimization(int precision){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(precision);
}

ll a[30][30];

void solve()
{
	ll maxp = 0;
	ll i;ll j;
	FOR(i,4,24){
		FOR(j,4,24){
			cin>>a[i][j];
		}
	}
	FOR(i,3,26){
		FOR(j,3,26){
			maxp = max(maxp, a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
			maxp = max(maxp, a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
			maxp = max(maxp, a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
			maxp = max(maxp, a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3]);
		}
	}
	cout<<maxp<<endl;
}


int main()
{
	desperate_optimization(10);
	solve();
	return 0;
}