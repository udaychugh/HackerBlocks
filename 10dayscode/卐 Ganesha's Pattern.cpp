#include<iostream>
using namespace std;
int main() 
{
	int n;
	cin>>n;
	int hn=(n+1)/2;
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        if(i==hn||j==hn||(i==1 && j>hn)||(i==n && j<hn)||(j==1 && i<hn)||(j==n && i>hn))
	        cout<<"*";
	        else cout<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}