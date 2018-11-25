//  c(i,j) = min {c(i,k-1)+c(k,j+w(i,j)}
#include<bits/stdc++.h>
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define F               first
#define S               second
using namespace std;

int n;
pair<int,int>dp[50][50],x[20];
vector<int>v;
bool check[100];

void print()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%5d",dp[i][j].F);
        cout << endl;
    }
    cout << endl;
}

void makeTree()
{
    int flag1=0,flag2=0;
    v.push_back(dp[0][n].S);  //pushing the root in the vector
    check[dp[0][n].S] = true; //then marking that this key is pushed in the vector

    for(int i=0,j=n-1,k=1,l=n; i<n ;)
    {
        if(!check[dp[i][j].S]) //whether the element exists in vector
        {
            v.push_back(dp[i][j].S); //if not then pushing it in vector 
            check[dp[i][j].S] = true; // and marking
        }
        if(!check[dp[k][l].S])
        {
            v.push_back(dp[k][l].S);
            check[dp[k][l].S] = true;
        }
        if(k<n-1 && flag1==0) k++;
        else {
            k--;
            l--;
            flag1=1;
        }
        if(j>1 && flag2==0) j--;
        else {
            i++;
            j++;
            flag2=1;
        }
    }

    //Printing the sequence of insert to get the Optimal BST
    for(int i=0;i<v.size();i++)
        cout << x[v[i]].F << " " ;
    cout << endl;

}

int cost(int i,int j,int k)
{
    int w=0;
    for(int c=i+1;c<=j;c++)
        w+=x[c].S;

    return dp[i][k-1].F+dp[k][j].F+w;
}

int main()
{
    fin;
    int cost1,cost2,p,i,j;
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
			int k,mark ;
            for(k=1;k<=j;k++)
			{
                if(k>i)
				{
                    cost2=cost1;
                    cost1= min(cost(i,j,k),cost1);
                    if(cost1<cost2)
                        mark = k;
				}
			}
            dp[i][j].F = cost1;
			dp[i][j].S = mark;
            i++,j++;
        }
    }

   print();
   makeTree();
   
    // cout << dp[0][n] << endl;
    return 0;
} 
