/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : ProjectEuler27       *
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


bool isPrime(ll n)
{
	if(n<=1)
		return false;
	if(n==2 || n==3)
		return true;
	for(ll i = 2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}



void solve()
{
	ll n;
	cin>>n;
	ll a;ll b;
	ll count = 0;ll temp=0;
	FOR1(i, -n, n)
	{
		FOR1(j, -n, n)
		{
			count = 0;
			while(isPrime(count*count+count*i+j))
				count++;

			if(count>temp)
			{
				a = i;
				b = j;
				temp = count;
			}
		}
	}
	cout<<a<<" "<<b<<endl;
}



int main()
{
	desperate_optimization(10);
	//cout<<isPrime(2)<<" "<<isPrime(4)<<" "<<isPrime(3)<<" "<<isPrime(155)<<" "<<isPrime(97)<<" "<<endl;
	solve();

	return 0;
}
