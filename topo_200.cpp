#include <bits/stdc++.h>
using namespace std;
int visitado[30];
vector<int> mat[32];
vector<int> res;	
void dfs(int n)
{
	visitado[n]=1;
	for(int i=0; i<mat[n].size(); i++)
	{
		int q=mat[n][i];
		if(visitado[q]==0)
			dfs(q);
	}
	res.push_back(n);
}
int main()
{
	map <char,int> mapa; 
	char a='A';
	for(int i=1; i<=30; i++)
	{
		mapa[a]=i;
		a++;
		//cout<<a<<endl;
	}
	string cad,cad2;
	//getline(cin,cad);
	//cout<<cad<<endl;
	while(cin>>cad)
	{
		memset(visitado,0,sizeof(visitado));
		int pp=0;
		char el;
		while(1)
		{
			//printf("%s\n",cad );
			if(cad=="#")
				break;
			if(pp==0)
			{
				pp=1;
				el=cad[0];
			}

			cin>>cad2;
			if(cad2=="#")
				break;
			//cout<<cad<<endl<<cad2<<endl;
			int con=0,ban=0;
			char p,o;
			while(1)
			{

				if(con>=cad.size() or con>=cad2.size())
				{
					ban=1;
					break;
				}
				p=cad[con];
				o=cad2[con];
				//cout<<p<<"  "<<o<<endl;
				if(p!=o)
					break;
				con++;
			}
			if(ban!=1)
			{
				mat[mapa[p]].push_back(mapa[o]);
			}
			cad=cad2;

		}
		dfs(mapa[el]);
		a='A';
		for(int i=res.size()-1; i>=0 ; i--)
		{
			printf("%c",a+res[i]-1);
		}
		cout<<endl;
		res.clear();
		for(int i=0; i<32; i++)
			mat[i].clear();
		//vector<int> mat[32];
		vector<int> res;
		//getline(cin,cad);

	}
}