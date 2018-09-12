#include <bits/stdc++.h>
using namespace std;
vector<int> mat[205];
int visi[205];
int ban=0;
void defect(int nodo)
{
	visi[nodo]=5;
	for(auto a: mat[nodo])
		if(visi[nodo]!=5)
			defect(a);
}
void def(int nodo,int estado)
{
	
		visi[nodo]=1-estado;
		//cout<<" nodo "<<nodo<<"  estado "<<visi[nodo]<<endl;
		for(auto a: mat[nodo])
		{	
			//cout<<"\tnodo : "<<a<<"  estado: "<<visi[a]<<endl;
			if(visi[a]==-1)
			{
				def(a,visi[nodo]);
			}
			else
			{
				if(visi[a]==visi[nodo])
				{
						ban=1;
					//	return;
				}
			}
		}
	
}
int main()
{
	
	int numero,casos,n,oi;
	cin>>casos;
	for(int i=0; i<casos ; i++ )
	{
		cin>>numero;
		for(int j=1; j<=numero; j++)
		{
			cin>>n;
			for(int p=0; p<n; p++)
			{

				cin>>oi;
				if(oi<=numero)
				{
					mat[j].push_back(oi);
					mat[oi].push_back(j);
				}
			}
		}
		int max=0;
		memset(visi,-1,sizeof(visi));
		for(int i=1; i<=numero ; i++)
		{
			ban=0;
			if(visi[i]==-1 and mat[i].size()!=0)
			{
				int uno=0,cero=0;
				def(i,1);
				if(ban==1)
				{
					//cout<<"entro..."<<endl;
					defect(i);
				}
				else
				{		
					for(int i=1; i<=numero; i++)
					{
						if(visi[i]==1)
						{
							visi[i]=5;
							uno++;
						}
						if(visi[i]==0)
						{
							visi[i]=5;
							cero++;
						}
					}
					if(cero<uno)
						max+=uno;
					else
						max+=cero;
				}
				
			}
		}
		for(int i=1; i<=numero ; i++)
			if(visi[i]==-1)
			{
				max++;
			}
			for(int i=0; i<=numero; i++)
				mat[i].clear();
			cout<<max<<endl;	
	}
}