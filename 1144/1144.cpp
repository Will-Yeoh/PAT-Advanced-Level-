#include<iostream>
#include<map>

using namespace std;

int main(){
	int n,a,num=0;
	map<int,int> m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		m[a]++;
	}
	while(++num){
		if(m[num] == 0){
			cout<<num;
			break;
		}
	}
	return 0;
}
