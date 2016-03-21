#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    vector<int> x;
    int a,b;
    int count=0;
    cin>>a;
    for(int k=0;k<a;k++)
    {
        cin>>b;
        x.push_back(b);
    }
    int left[a],right[a];
    left[0]=x[0];
    right[a-1]=x[a-1];
    for(int i=1;i<a;i++)
        left[i]=max(left[i-1],x[i]);
    for(int j=a-2;j>=0;j--)
        right[j]=max(right[j+1],x[j]);
    for(int l=0;l<a;l++)
        count=count+min(left[l],right[l])-x[l];
    cout<<count<<endl;


    return 0;
}
