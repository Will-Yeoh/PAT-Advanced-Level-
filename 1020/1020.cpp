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

int pre[maxn],in[maxn],post[maxn];      //先序、中序、后序
int n;    //结点个数 

node* create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL; //后序序列长度小于等于0时，直接返回 
	}
	node* root = new node;         //新建一个新节点，用来存放当前二叉树的根节点 
	root->data = post[postR];      //新节点的数据域为根节点的值
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k] == post[postR]){  //在中序序列中找到in[k] == pre[L]的结点 
			break;
		}
	}    
	int numLeft = k-inL;    //左子树结点个数
	root->lchild = create(postL,postL+numLeft-1,inL,k-1);
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;     //返回根节点地址 
} 

int num = 0;    //已输出结点的个数
void BFS(node* root){
	queue<node*> q;    //队列里存的是地址
	q.push(root);      //根节点地址入队
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		cout<<now->data;   //访问队首元素 
		num++;
		if(num < n){
			cout<<" ";
		} 
		if(now->lchild != NULL){
			q.push(now->lchild);         //左子树非空 
		}
		if(now->rchild != NULL){
			q.push(now->rchild);         //右子树非空 
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
	node* root = create(0,n-1,0,n-1);       //建树
	BFS(root);   //层序遍历 
	return 0;
}
