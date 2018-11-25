/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler3       *
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


ll maxPrimeFactors(ll n) 
{ 
	ll maxn = 0;
	if(n%2==0)
	{
        maxn = 2;
		while (n%2 == 0) 
		{ 
			n = n/2; 
		}   
	}
	for (int i = 3; i <= sqrt(n); i = i+2) 
	{
        if(n%i==0)
        {
            maxn = i;
    		while (n%i == 0) 
    		{ 
    			n = n/i; 
    		}
        } 
	} 
	if (n > 2) 
		maxn = n;
    return maxn;
}



void solve()
{
    ll n;
    cin>>n;
    ll maxn = maxPrimeFactors(n);
    cout<<maxn<<endl;
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