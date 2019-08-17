#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int maxn = 50;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn],in[maxn],post[maxn];      //�������򡢺���
int n;    //������ 

node* create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL; //�������г���С�ڵ���0ʱ��ֱ�ӷ��� 
	}
	node* root = new node;         //�½�һ���½ڵ㣬������ŵ�ǰ�������ĸ��ڵ� 
	root->data = post[postR];      //�½ڵ��������Ϊ���ڵ��ֵ
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k] == post[postR]){  //�������������ҵ�in[k] == pre[L]�Ľ�� 
			break;
		}
	}    
	int numLeft = k-inL;    //������������
	root->lchild = create(postL,postL+numLeft-1,inL,k-1);
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;     //���ظ��ڵ��ַ 
} 

int num = 0;    //��������ĸ���
void BFS(node* root){
	queue<node*> q;    //���������ǵ�ַ
	q.push(root);      //���ڵ��ַ���
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		cout<<now->data;   //���ʶ���Ԫ�� 
		num++;
		if(num < n){
			cout<<" ";
		} 
		if(now->lchild != NULL){
			q.push(now->lchild);         //�������ǿ� 
		}
		if(now->rchild != NULL){
			q.push(now->rchild);         //�������ǿ� 
		} 
	} 
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>post[i];
	} 
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	node* root = create(0,n-1,0,n-1);       //����
	BFS(root);   //������� 
	return 0;
}
