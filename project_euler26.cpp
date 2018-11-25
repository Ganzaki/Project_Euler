/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler26      *
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



ll a[11000];

void Set()
{
	a[0]=a[1]=a[2]=1;
	ll n = 10100;
	ll j = 1;
	ll b[11][11000];
	ll r = 0;
	ll k = 0;
	ll temp = 0;
	FOR(i,3,n)
	{
		j = 1;
		FILL(b,0);
		r = 0;
		k = 1;
		while(1)
		{
			while(j/i==0)
			{
				j*=10;
				r++;
			}
			if(j%i==0)
			{
				k = 0;
				break;

			}
			else
			{
				if(!b[j/i][j%i])
				{
					b[j/i][j%i] = r;
				}
				else
				{
					r = r - b[j/i][j%i];
					break;
				}
			}
			j = j%i;
		}
		if(k)
		{

			if(temp<r)
			{
				a[i] = i;
				temp = r;
			}
			else
			{
				a[i] = a[i-1];
			}
			
		}
		else
		{
			a[i] = a[i-1];
		}
	}
}


void solve()
{
	ll n;
	cin>>n;
	cout<<a[n-1]<<endl;
}

int main()
{
	desperate_optimization(10);
	Set();
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}