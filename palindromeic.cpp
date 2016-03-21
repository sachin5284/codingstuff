#include <iostream>
#include <vector>
using namespace std;
void titleToNumber(int A) {
    vector <int> w;
    string s;
    int x=0;
    while(A>0)
    {
        int a=A%26;
        w.push_back(a);
        if(a==0)A=(A-1)/26;
        else A=A/26;
    }
    while(!w.empty())
    {
        int x=w.back()+64;if(x==64)x=x+26;
        s+=(char) x;
        w.pop_back();
    }
    int y=s.size();
    for(int k=0;k<y;k++)cout<<s[k];
}


int main(){
	titleToNumber(943566);
	return 0;
}
