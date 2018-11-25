/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler16      *
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


ll a[11100];
ll b[11100];

void Set()
{
	a[0] = 1;
	b[0] = 1;
	ll carry = 0;
	ll j = 1;
	ll len = 1;
	for(ll i= 1; i<=10001; i++)
	{
		for(int k = 0; k<j; k++)
		{
			a[k] = a[k]*2;
			a[k]+=carry;
			carry = (a[k] - a[k]%10)/10;
			a[k] = a[k]%10;
		}
		while(carry)
		{
			a[j]=carry%10;
			carry= carry/10;
			j++;
			len = max(len,j);
		}
		for(ll k = len+50; k>=0; k--)
		{
			b[i]+=a[k];
		}
	}
}



void solve()
{
	ll n;
	cin>>n;
	cout << b[n] << endl;
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