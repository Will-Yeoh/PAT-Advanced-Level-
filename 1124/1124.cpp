#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int M,N,S;
	cin>>M>>N>>S;
	vector<string> name(M+1);//�����������1��ʼ 
	set<string> sn;//������ 
    
	
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
			if (sn.count(name[i]) == 0)//����δ�й���
			{
				flag++;
				if (flag == N)//һ��һ��������������񽱵�������ֱ����N��û�񽱵Ĳ��� 
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
