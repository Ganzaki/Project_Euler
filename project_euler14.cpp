/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler14      *
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

ll a[5000100];
ll b[5000100];

void Set(){
	FOR1(i,1,5000002){
		ll num = i;
		ll counter = 1;
		while(num!=1LL){
			if(num<5000010 && b[num]){
				counter+= b[num]-1;
				break;				
			}
			if(num&1) num = 3*num +1;
			else      num>>=1;
			counter++;
		}
		b[i]=counter;
		if(b[a[i-1]]>counter)
        	{
            		a[i] = a[i-1];
        	}
        	else
        	{
            		a[i] = i;
        	}
	}	
}
void solve()
{
	ll n;
	cin>>n;
	ll t = a[n];
	cout<<t<<endl;
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