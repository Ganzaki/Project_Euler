/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler23      *
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
ll a[1000100];

ll sFactors(ll n) 
{
	ll p = 1;
	ll j=1;
	if(n%2==0)
	{
		j = 1;
		while (n%2 == 0) 
		{ 
			n = n/2;
			j++;
		}
	}
	p*=((pow(2,j)-1)/1);
	for (ll i = 3; i <= sqrt(n); i = i+2) 
	{ 
		
		if(n%i==0)
		{
			j = 1;
			while (n%i == 0) 
			{
				n = n/i;
				j++;
			}
			p*=((pow(i,j)-1)/(i-1));
		}
		
	}
	if(n>2)
		p*=(1+n);
	return p; 
} 


void Set()
{
	a[0] = 1;
	int n = 600000;

	FOR(i,1,n)
	{
		a[i] = sFactors(i) - i;
	}
	
}


void solve()
{
	ll n;
	cin>>n;
	if(n>28123)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		ll k=1;
		if(n%2==0)
		{
			if(a[n/2]>(n/2))
			{
				cout<<"YES"<<endl;
				k=0;

			}	
		}
		if(k)
		{
			ll j = 0;
			FOR1(i,2,n)
			{
				if(a[i]>i && a[n-i]>(n-i))
				{
					j = 1;
					break;
				}
			}
			if(j)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
}

int main()
{
	desperate_optimization(10);
	Set();
	//cout<<sFactors(220)<<" "<<a[220]<<endl;
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}