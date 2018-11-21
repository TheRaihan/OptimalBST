//  c(i,j) = min {c(i,k-1)+c(k,j+w(i,j)}
#include<bits/stdc++.h>
#define inf             1/0.0
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define MOD             100000007
using namespace std;

int dp[100][100],n;
pair<int,int>x[10];

void func()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%5d ",dp[i][j]);
        cout << endl;
    }
}

int cost(int i,int j,int k)
{
    int w=0;
    for(int c=i+1;c<=j;c++)
        w+=x[c].S;

    return dp[i][k-1]+dp[k][j]+w;
}

int main()
{
    fin;
    int cost1,p,i,j;
    cin >> n;
    for(int i = 1 ;i<=n;i++)
    {
        cin >> x[i].F >> x[i].S ;
//        dp[i-1][i] = x[i].S;
    }

    for(int p=1; p<=n ; p++)
    {
        j=p,i=0,cost1=50000;
        while((j-i)==p)
        {
            if(j > n) break;

            cost1=50000;

            for(int k=1;k<=j;k++)
                    if(k>i) cost1= min(cost(i,j,k),cost1);

            dp[i][j] = cost1;
            i++,j++;
        }
    }

//    func();
    cout << dp[0][n];

    return 0;
}
