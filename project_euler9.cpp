/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler9       *
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
	ll maxp = -1;
	ll k = 0;
	ll i;
	FOR1(i,1,n/3)
	{
		ll t1 = n*n - 2*n*i;
		ll t2 = 2 * (n-i);
		if(t1%t2!=0)
			continue;
		ll j = t1/t2;
		ll k = n - i - j;
		if((i*i+j*j==k*k)&&(i<j&&j<k))
			maxp=max(maxp,i*j*k);
	}
	cout<<maxp<<endl;
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