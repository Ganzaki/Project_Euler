/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler10      *
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
bool prime[1000001]; 
ll sump[1000001];

void setPrime()
{
	for (register ll p = 2; p * p <= 1000001; p++) { 
		if (prime[p] == true) {  
			for (ll i = p * 2; i <= 1000001; i += p) 
				prime[i] = false; 
		}
	}
	sump[0]=sump[1]=1;sump[2]=2;
	for (ll i = 3; i < 1000001; i++) 
		if (prime[i]) 
			sump[i] = sump[i-1]+i;
		else
			sump[i] = sump[i-1];
}

void solve()
{
	ll n;
	cin>>n;
	ll sum = sump[n];
	cout<<sum<<endl;
}


int main()
{
	desperate_optimization(10);
	int t;
	memset(prime, true, sizeof(prime)); 
	setPrime();
	cin>>t;
	while(t--)
		solve();
	return 0;
}