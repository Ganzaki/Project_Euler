/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler12      *
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

ll divisor[2000];

ll nFactors(ll n) 
{
	ll p = 1;
	ll j=0;
	if(n%2==0)
	{
		j = 0;
		while (n%2 == 0) 
		{ 
			j++;
			n = n/2;
		}
		p = p*(j+1);
	}
	for (ll i = 3; i <= sqrt(n); i = i+2) 
	{ 
		if(n%i==0)
		{
			j = 0;
			while (n%i == 0) 
			{
				j++; 
				n = n/i; 
			}
			p = p*(j+1);
		}
	}
	if(n>2)
		p*=2;
	return p; 
} 
void Set()
{
	ll i = 2;
	ll factor = 1;ll j;
	ll temp = 1;
	while(j<1e+9)
	{
		j = i*(i+1)/2;
		factor = nFactors(j);
		if(!divisor[factor] && factor>temp)
		{
			divisor[factor] = j;
			temp = factor;
		}
		i++;
	}
}


void solve()
{
	ll n;
	cin>>n;
	n++;
	ll j = 0;
	while(!j)
	{
		j = divisor[n];
		n++;
	}
	cout<<j<<endl;
}


int main()
{
	desperate_optimization(10);
	FILL(divisor,0);
	//cout<<"lol lll "<<nFactors(28)<<endl;
	int t;
	Set();
	/*cout<<"[";
	FOR1(i,0,2000)
	{
		cout<<divisor[i]<<",";
	}
	cout<<"]";*/
	cin>>t;
	while(t--)
		solve();
	return 0;
}