#include<bits/stdc++.h>
#define nl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll long long int
#define loop(a,b)           for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);

using namespace std;
void FAST_IO();
bool leap(int leap);
int main()
{
    //_time_
   //FAST_IO();
    string month1,month2;
    ll date1,year1,date2,year2;
    int i=1;
    sv()
    {
        char c;
        cin>>month1>>date1>>c>>year1;
        cin>>month2>>date2>>c>>year2;
        //cout<<month1<<" "<<date1<< " "<<year1<<endl;
        int four1=year1/4;
        int four2=year2/4;
        int hundred1=year1/100;
        int hundred2=year2/100;
        int fourhundred1=year1/400;
        int fourhundred2=year2/400;
        int total=(four2-four1)-((hundred2-hundred1)-(fourhundred2-fourhundred1));
        //cout<<total<<endl;

        if(leap(year1))
        {
            if(month1=="January" || month1=="February")
                total++;
        }
        //cout<<total<<endl;
        if(leap(year2))
        {
            if(month2=="January")
                total--;
            else if(month2=="February" && date2<29)
                total--;
        }
        cout<<"Case "<<i<<": "<<total<<endl;
        i++;
    }


   // show
    return 0;
}
bool leap(int leap)
{
    if(leap%4==0)
    {
        if(leap%400==0)
            return true;
        else if(leap%100==0)
            return false;
        return true;
    }
    return false;
}
void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
#ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
