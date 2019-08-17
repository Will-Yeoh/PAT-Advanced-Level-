#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true; 
}

int main(){
	int Tsize,n,m,a;
	cin>>Tsize>>n>>m;
	while(!isPrime(Tsize)){
		Tsize++; 
	}
	vector<int> arr(Tsize);
	for(int i=0;i<n;i++){
		cin>>a;
		int flag = 0;
		for(int j=0;j<Tsize;j++){
			int pos = (a+j*j)%Tsize;
			if(arr[pos] == 0){				
				arr[pos] = a;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			cout<<a<<" cannot be inserted."<<endl;
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		cin>>a;
		for(int j=0;j<=Tsize;j++){                            //<=µÄ¡°=¡±²»ÄÜ¶ª 
		    ans++;
			int pos = (a+j*j)%Tsize;
			if(arr[pos] == a || arr[pos] == 0)
			{
				break;
			}		
		}
	}
	printf("%.1f\n",ans*1.0/m);
	
	return 0;
}
