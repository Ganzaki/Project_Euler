/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler19      *
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

ll ZellerC(ll q, ll m, ll y) 
{ 
	if (m == 1) 
	{ 
		m = 13; 
		y--; 
	} 
	if (m == 2) 
	{ 
		m = 14; 
		y--; 
	}  
	ll k = y % 100; 
	ll j = y / 100; 
	ll h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j; 
	h = h % 7; 
	return h;
}


void solve()
{
	ll d1;ll d2;ll m1;ll m2;ll y1;ll y2;ll sunday = 0;
	cin>>y1;cin>>m1;cin>>d1;
	cin>>y2;cin>>m2;cin>>d2;
	if (y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2<d1))
	{
		std::swap(y1, y2);
		std::swap(m1, m2);
		std::swap(d1, d2);
	}
	if(d1>1)
	{
		m1++;
		if(m1>12)
		{
			m1-=12;
			y1++;
		}
	}
	while(y1+2800<y2)
	{
		y1+=2800;
		sunday+=4816;
	}
	while (m1<m2 || y1<y2)
	{
		//cout<<(m1<m2)<<(y1<y2)<<(m1<m2 || y1<y2)<<" "<<m1<<" "<<y1<<" "<<y2<<" "<<m2<<endl;
		if(ZellerC(1,m1,y1)==1)
			sunday++;
		m1++;
		if(m1>12)
		{
			m1-=12;
			y1++;
		}
	}
	if(ZellerC(1,m1,y1)==1)
			sunday++;
	cout<<sunday<<endl;
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