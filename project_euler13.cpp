/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler13      *
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

ll a[1000001];
ll lena = 0;
void sumn(str b)
{
	ll carry = 0;
	ll j = 1;
	for(ll i= 0; i<50; i++)
	{
		j = i+1;
		a[i] = a[i]+b[49-i]-'0';
		carry = (a[i] - a[i]%10)/10;
		a[i] = a[i]%10;
		while(carry)
		{
			a[j]+=carry;
			carry = (a[j] - a[j]%10)/10;
			a[j] = a[j]%10;
			j++;
			lena = j+1;
			
		}
	}
}

void solve()
{
	FILL(a,0);
	ll n;
	cin>>n;
	lena = 50;
	str b;
	while(n--)
	{
		cin>>b;
		sumn(b);
	}
	lena = lena+500;
	while(!a[lena-1])
	{
		lena--;
	}
	FOR2(i, lena-1, lena-10)
	{
		cout<<a[i];
	}
	cout<<endl;
}


int main()
{
	desperate_optimization(10);
	solve();
}

