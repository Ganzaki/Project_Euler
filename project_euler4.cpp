/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler4       *
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


bool isPalindrome(ll n)
{
	ll s = 0;
	ll t = n;
	while(t)
	{
		s = s*10 + t%10;
		t=t/10;
	}
	//cout<<"in"<<s<<endl;
	return s==n;
}

void solve()
{
	ll n;
	cin>>n;
	ll t = 0;
	for(ll j=100; j<=999; j++)
	{
			for(ll i=100; i<=999 && i<((n%j)?n/j:n/j+1); i++)
			{
				if(isPalindrome(i*j))
				{
					t = max(t,i*j);
				}
			}
	}
	cout<<t<<endl;
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