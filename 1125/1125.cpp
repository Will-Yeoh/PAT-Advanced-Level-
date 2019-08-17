#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int a[N];
	
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+N);
	
	double L=a[0];
	for(int j=0;j<N;j++)
	{
		L=(L+a[j])/2;
	}
	
	cout<<(int)L<<endl;
	
	return 0;
} 
