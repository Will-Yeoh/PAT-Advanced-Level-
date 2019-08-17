#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M=26*26*26*10+10;
vector<int> selectCourse[M];

int getID(char name[])
{
	int id=0;
	for(int i=0;i<3;i++)
	{
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}

int main()
{
	char name[5];
	int n,k;
//	cin>>n>>k;
    scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int course,x;                          //course：课程编号；x：选这门课的人数 
//		cin>>course>>x;
        scanf("%d%d",&course,&x);
		for(int j=0;j<x;j++)
		{
//			cin>>name;
            scanf("%s",name);
			int id=getID(name);
			selectCourse[id].push_back(course);
		} 
	} 
	for(int i=0;i<n;i++)
	{
//		cin>>name;
		scanf("%s",name);
		int id=getID(name);
		sort(selectCourse[id].begin(),selectCourse[id].end());
//		cout<<name<<" "<<selectCourse[id].size();
		printf("%s %d",name,selectCourse[id].size());
		for(int j=0;j<selectCourse[id].size();j++)
		{
//			cout<<" "<<selectCourse[id][j];
			printf(" %d",selectCourse[id][j]);
		}
//		cout<<endl;
        printf("\n");
	} 
	
	return 0;
}
