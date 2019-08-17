#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n,m,v,k,s1,s2;
	cin>>n;
	set<int> a[n];
	for(int i=0;i<n;i++)
	{
		cin>>m;
		for(int j=0;j<m;j++)
		{
			cin>>v;
			a[i].insert(v);
		}
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>s1>>s2;
		int sameNum=0,totalNum=a[s2-1].size();
		for(set<int>::iterator it=a[s1-1].begin();it!=a[s1-1].end();it++)
		{
			if(a[s2-1].find(*it)!=a[s2-1].end())
			{
				sameNum++;
			}
			else
			{
				totalNum++;
			}
		}
//		double ans=(double)sameNum/totalNum*100;
//		printf("%.1f%\n",ans);
		printf("%.1f%\n",sameNum*100.0/totalNum);         //100.0
	}
	return 0;
}
