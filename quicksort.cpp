#include<bits/stdc++.h>
using namespace std;
int Partition(int a[],int left,int right)
{
    int low=left;
    int high=right;
    int pivot=a[left];
    while(high>low){
        while(a[low]<=pivot)low++;
        while(a[high]>pivot)high--;
       if(high>low){
                swap(a[low],a[high]);
        }
    }
    a[left]=a[high];
    a[high]=pivot;
    return high;
}
void quicksort(int a[],int left,int right)
{
    int pivot;
    if(right>left)
    {
        pivot=Partition(a,left,right);
        //pivot postion is fixed
        quicksort(a,left,pivot-1);
        quicksort(a,pivot+1,right);
    }
}
int main()
{
    int a[]={4,3,2,5,4,6,8,1,3,5};
    int i=sizeof(a)/sizeof(int);
    //cout<<i;
    //int b[i];
    quicksort(a,0,i-1);
   for(int j=0;j<i;j++)cout<<a[j]<<" ";
    return 0;
}
