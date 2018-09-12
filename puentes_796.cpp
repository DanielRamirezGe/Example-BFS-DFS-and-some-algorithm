#include <bits/stdc++.h>
using namespace std;
int low[1000];
int num[1000];
int padre[1000];
vector<pair<int,int>> puente;
int pun;
int niv;
int hijos;
int raiz;
vector<int> mat[1000];
void dfs(int a)
{
	low[a]=num[a]=niv++;
	for(int i=0; i<mat[a].size(); i++)
	{
		int q=mat[a][i];
		if(num[q]==-1)
		{
			if(mat[a][i]==raiz)
				hijos++;
			padre[q]=a;
			dfs(q);
			/*if(low[q]>=low[a])
				arti[a]=1;*/
			if(low[q]>num[a])
			{
				pun++;
				if(a<q)
					puente.push_back({a,q});
				else
					puente.push_back({q,a});

			}
			low[a]=min(low[q],low[a]);

		}
		else
			if(q!=padre[a])
				low[a]=min(low[a],num[q]);
	}
}
int main()
{
	int nodos,a,b,p;
	char w;
	//cin>>nodos;
	string cad;
	while(scanf("%d",&nodos)==1)
	{
		
		//cout<<nodos<<endl;
		memset(low,1,sizeof(low));
		memset(num,-1,sizeof(num));
		memset(padre,-1,sizeof(padre));
		puente.clear();

		pun=niv=hijos=raiz=0;
		for(int o=0; o<nodos; o++)
		{
			cin>>a;
			cin>>w>>p>>w;
			//cout<<"<<"<<p<<endl;
			for(int i=0; i<p; i++)
			{
				cin>>b;
				mat[a].push_back(b);
				mat[b].push_back(a);
			}
		}

		for(int i=0; i<nodos; i++)
		{
			if(num[i]==-1)
			{
				raiz=i;
				hijos=0;
				dfs(i);
			}
		}
		cout<<pun<<" critical links"<<endl;
		sort(puente.begin(),puente.end());
		for(int i=0; i<pun; i++)
			cout<<puente[i].first<<" - "<<puente[i].second<<endl;		
		cout<<endl;
		//cin>>nodos;
		for(int i=0; i<=nodos; i++)
			mat[i].clear();
	}
	
	return 0;
}