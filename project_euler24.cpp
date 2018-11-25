/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler24      *
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



ll factorial(ll n)
{
	ll fact = 1;
	while(n>0)
	{
		fact = fact * (n--);
	}
	return fact;
}


void solve()
{
	str a("mlkjihgfedcba");
	ll len = 13;
	ll n;

	cin>>n;
	n--;
	//cout<<"n = "<<n<<" len = "<<len<<endl;
	str b;
	ll i = 1;
	ll temp = 0;
	while(n)
	{
		for(i = 1; i <=len; i++)
		{
			temp = (len-i)*factorial(len-1);
			//cout<<"temp = "<<temp<<endl;
			if(temp<=n)
			{
				//cout<<"lol"<<endl;
				b.push_back(a[i-1]);
				a.erase (std::remove(a.begin(), a.end(), a[i-1]), a.end());
				len--;
				n = n - temp;
				//cout<<b<<endl;
				break;
			}
		}
	}
	if(len)
	{
		for(i = 1; i<=len; i++)
			b.push_back(a[len-i]);
	}

	cout<<b<<endl;
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