/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler18      *
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
ll a[20][20];

ll maxSum(ll n, ll i, ll j)
{
	ll msum = 0;
	if(i<n-1 && j>=0)
	{
		msum = a[i][j] + max(maxSum(n,i+1,j),maxSum(n,i+1,j+1));
		//cout<<"i = "<<i<<" j = "<<j<<endl;
		//cout<<"msum = "<<msum<<endl;
	}
	else if(i==n-1 && j>=0)
	{
		//cout<<"i = "<<i<<" j = "<<j<<endl;
		return a[n-1][j];
	}
	return msum;
}


void solve()
{
	ll n;
	cin>>n;
	FILL(a,0);
	FOR(i,0,n) FOR1(j,0,i) cin>>a[i][j];
	ll m = maxSum(n, 0, 0);
	cout<<m<<endl;
}


int main()
{
	desperate_optimization(10);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}