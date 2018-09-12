#include <bits/stdc++.h>
using namespace std;
int main()
{
	map <int,vector<int>> mapa;
	int cant,consul;

	while(scanf("%d",&cant)==1)
	{
		cin>>consul;
		int a;
		for(int i=1;i<=cant; i++)
		{
			cin>>a;
			if(mapa[a].size()==0)
				mapa[a].push_back(i);
			
			else
				mapa[a].push_back(i);
		}
		int k, v;
		//for(auto a:mapa[3])
		//	cout<<a<<" ";
		//cout<<endl;
		for(int i=0; i<consul; i++)
		{
			cin>>k>>v;
			if(mapa[v].size()==0 or mapa[v].size()<k)
				cout<<0<<endl;
			else
				cout<<mapa[v][k-1]<<endl;
		}
		mapa.clear();
	}
}