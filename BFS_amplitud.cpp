#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,a,b,nodos,aristas;
	cin>>nodos>>aristas;
	vector <int> lis[nodos+1];
	for(int i=0; i<aristas ; i++)
	{
		cin>>a>>b;
		lis[a].push_back(b);
	}
	int distancia[nodos+1];
	memset(distancia,-1,sizeof(distancia));
	distancia[0]=0;
	queue <int> cola;
	cola.push(0);
	while(!cola.empty())
	{
		m=cola.front();cola.pop();
		for(int i=0; i<lis[m].size(); i++)
		{
			a=lis[m][i];
			if(distancia[a]=-1)
			{
				distancia[a]=distancia[m]+1;
				cola.push(a);
			}
		}
	}
	for(int i=0; i< nodos ; i++)
	{
		cout<<i<<" distancia : "<<distancia[i]<<endl;
	}
	return 0;
}