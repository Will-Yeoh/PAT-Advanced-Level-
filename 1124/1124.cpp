#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int M,N,S;
	cin>>M>>N>>S;
	vector<string> name(M+1);//存放名单，从1开始 
	set<string> sn;//获奖名单 
    
	
	 for(int i=1;i<=M;i++)
	 {
//	 	scanf("%s",name[i].c_str());
        cin>>name[i];
	 } 
	 
	 if(S>M)
	 {
	 	cout<<"Keep going..."<<endl;
//	 	printf("Keep going...\n");
	 }
	 else
	 {
	 	cout << name[S] << endl;
		sn.insert(name[S]);

		int flag = 0;
		for (int i = S + 1; i <= M; i++)
		{
			if (sn.count(name[i]) == 0)//该人未中过奖
			{
				flag++;
				if (flag == N)//一个一个地往后遍历，获奖的跳过，直到第N个没获奖的捕获 
				{
					cout << name[i] << endl;
					sn.insert(name[i]);
					flag = 0;
				}
			}	
		}

	 }
	 return 0;
	
}
