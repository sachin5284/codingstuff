#include<bits/stdc++.h>
using namespace std;
int combination(int n,int m)
{
    if(m==0 || n==m)return 1;
    else return combination(n-1,m)+combination(n-1,m-1);
}
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        m+=pow(combination(n,i),2);
    }
    cout<<m;
}
