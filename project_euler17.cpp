/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler17      *
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


ll nDigits(ll n)
{
	ll t =0;
	while(n)
	{
		t++;
		n/=10;
	}
	return t;
}


void place(ll n)
{
	switch(n)
	{
		case 13:cout<<"Trillion ";
			break;
		case 12:
		case 11:
		case 10: cout<<"Billion ";
			break;
		case 9:
		case 8:
		case 7: cout<<"Million ";
			break;
		case 6:
		case 5:
		case 4:cout<<"Thousand ";
			break;
		default:cout<<"";
	}
}

void number(ll n, ll l)
{
	if(l==1)
	{
		switch(n)
		{
			case 10:
				cout<<"Ten ";
				break;
			case 11:
				cout<<"Eleven ";
				break;
			case 12:
				cout<<"Twelve ";
				break;
			case 13:
				cout<<"Thirteen ";
				break;
			case 14:
				cout<<"Fourteen ";
				break;
			case 15:
				cout<<"Fifteen ";
				break;
			case 16:
				cout<<"Sixteen ";
				break;
			case 17:
				cout<<"Seventeen ";
				break;
			case 18:
				cout<<"Eighteen ";
				break;
			case 19:
				cout<<"Nineteen ";
				break;
			default:
				cout<<"";
				break;
		}	
	}
	else
	{
		switch(n)
		{
			case 1:
				cout<<"One ";
				break;
			case 2:
				cout<<"Two ";
				break;
			case 3:
				cout<<"Three ";
				break;
			case 4:
				cout<<"Four ";
				break;
			case 5:
				cout<<"Five ";
				break;
			case 6:
				cout<<"Six ";
				break;
			case 7:
				cout<<"Seven ";
				break;
			case 8:
				cout<<"Eight ";
				break;
			case 9:
				cout<<"Nine ";
				break;
			default:
				cout<<"";
				break;
		}
	}
}
void tenth(ll n)
{
	switch(n)
	{
		case 1:
			cout<<"Ten ";
			break;
		case 2:
			cout<<"Twenty ";
			break;
		case 3:
			cout<<"Thirty ";
			break;
		case 4:
			cout<<"Forty ";
			break;
		case 5:
			cout<<"Fifty ";
			break;
		case 6:
			cout<<"Sixty ";
			break;
		case 7:
			cout<<"Seventy ";
			break;
		case 8:
			cout<<"Eighty ";
			break;
		case 9:
			cout<<"Ninety ";
			break;
		default:
			cout<<"";
			break;
	}
}



void hundreth(ll n)
{
	//cout<<n<<endl;
	number((n - n%100)/100, 0);
	if(n - n%100)
		cout<<"Hundred ";
	ll l = (n%100 - n%10)/10;
	if(l==1)
	{
		number(n%100,l);
	}
	else
	{
		tenth(((n - n%10)/10)%10);
		number(n%10,l);
	}
}



void solve()
{
	ll n;
	cin>>n;
	if(n==0)
	{
		cout<<"Zero ";
	}
	else
	{
		ll v = n / 1000000000000;
		n = n % 1000000000000;
		if(v)
		{
			hundreth(v);
			place(13);
		}
		v = n / 1000000000;
		n = n%1000000000;
		if(v)
		{
			hundreth(v);
			place(10);
		}
		v = n / 1000000;
		n = n%1000000;
		if(v)
		{
			hundreth(v);
			place(7);
		}
		v = n / 1000;
		n = n%1000;
		if(v)
		{
			hundreth(v);
			place(4);
		}
		v = n;
		if(v)
		{
			hundreth(v);
		}
	}
	cout<<endl;
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