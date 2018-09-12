#include <bits/stdc++.h>
using namespace std;
vector <int> mat[101];
int dfs_num [101];
int dfs_low[101];
int padre[101];
bool arti[101];
int con;
int nivel;
int raiz;
int hijos;
void dfs(int i)
{
	dfs_num[i]=dfs_low[i]=nivel++;
	for(int a=0; a<mat[i].size() ; a++)
	{
		int q=mat[i][a];
		if(dfs_num[q]==-1)
		{
			padre[q]=i;
			if(raiz==i)
				hijos++;
			dfs(q);
			if(dfs_low[q]>=dfs_num[i]){
				//cout<<"nodo "<<i<<endl;
				arti[i]=1;
			}
			dfs_low[i]=min(dfs_low[i],dfs_low[q]);
		}
		else
			if(q!=padre[i] )
				dfs_low[i]=min(dfs_low[i],dfs_num[q]);
	}

}
int main()
{
	int em,nodos,a,b,pot;
	string cad;
	cin>>nodos;
	while( nodos!=0 )
	{
		nivel=con=0;
		memset(dfs_num,-1,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(padre,0,sizeof(padre));
		memset(arti,0,sizeof(arti));
		//cout<<"nodos: "<<nodos<<endl};
		getline(cin,cad);
		getline(cin,cad);
		while(cad!="0")
		{
			int i;
			pot=0;
			a=cad[0]-'0';
			if(cad[1]!=' ')
			{
				a*=10;
				a+=cad[1]-'0';
				i=3;
			}
			else
				i=2;
			for(; i<cad.size(); i++)
			{
				//cout<<cad[i];
				if(cad[i]!=' ')
				{
					b=b*(10*pot);
					b+=cad[i]-'0';
					//cout<<cad[i]<<endl;
					if(pot==0)
						pot=1;
					else
						pot*=10;

				}
				else
				{
					mat[a].push_back(b);
					mat[b].push_back(a);
					pot=0;
				}
				if(i==cad.size()-1)
				{
					mat[a].push_back(b);
					mat[b].push_back(a);
					pot=0;
				}
			}
			
			/*cout<<"termino"<<endl;
			for(int h=0; h<=nodos; h++)
			{
				cout<<h<<": ";
				for(int i=0; i<mat[h].size(); i++)
				{
					cout<<mat[h][i]<<" ";
				}
				cout<<endl;
			}*/
			getline(cin,cad);
			//cout<<endl;
		}
		for(int i=0 ; i<=nodos; i++)
		{
			if(dfs_num[i]==-1)
			{
				hijos=0;
				raiz=i;
				dfs(i);
				arti[raiz]=(hijos>1);

			}
		}
		for(int i=1; i<=nodos; i++)
			if(arti[i]==1)
			{
				//cout<<"nodo : "<<i<<endl;
				con++;
			}
		cout<<con<<endl;
		for(int i=0; i<=nodos; i++)
			mat[i].clear();
		cin>>nodos;
	}

}