/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler1       *
*                                   *
* * * * * * * * * * * * * * * * * * *
*/
#include <bits/stdc++.h>


#define FOR(j,k) for(ll i=j;i<k;i++)
#define FOR1(j,k) for(ll i=j;i<=k;i++)
#define FILL(a,i) memset(a,i,sizeof(a))
#define dbg(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)


using namespace std;


typedef long long ll;
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




void solve()
{
	ll n;
	cin>>n;
	ll sum=0;
	if(n%3==0)
	{
		sum-=n;
	}
	if(n%5==0)
	{
		sum-=n;
	}
	if(n%15==0)
	{
		sum+=n;
	}
	ll i = n/3;
	sum+=(i*(3+3*i)/2);
	i = n/5;
	sum+=(i*(5+5*i)/2);
	i = n/15;
	sum-=(i*(15+15*i)/2);
	cout<<sum<<endl;
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