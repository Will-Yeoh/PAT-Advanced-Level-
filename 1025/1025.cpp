#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[15];                  //准考证号 
	int score;                    // 分数 
	int location_number;          //考场号 
	int local_rank;               //场内排名 
}stu[1000];

bool cmp(Student a,Student b)
{
	if(a.score != b.score)
		return a.score>b.score;
	else
	    return strcmp(a.id,b.id)<0;
}

int main()
{
	int n,k,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>stu[num].id>>stu[num].score;
			stu[num].location_number=i;
			num++;
		}	
		sort(stu+num-k,stu+num,cmp);            //考场内考生排序 
		stu[num-k].local_rank=1;
		for(int j=num-k+1;j<num;j++)
		{
			if(stu[j].score == stu[j-1].score)
			{
				stu[j].local_rank=stu[j-1].local_rank;
			}
			else
			{
				stu[j].local_rank=j+1-(num-k);
			} 
		}	
	}
	cout<<num<<endl;
	sort(stu,stu+num,cmp);
	int r=1;
	for(int i=0;i<num;i++)
	{
		if(i>0 && stu[i].score!=stu[i-1].score)
		{
			r=i+1;
		}
		cout<<stu[i].id<<" "<<r<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<endl;
	}
	return 0;
}
