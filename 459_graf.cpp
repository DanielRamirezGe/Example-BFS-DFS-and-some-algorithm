#include <bits/stdc++.h>
using namespace std;
int con;
int tama;
vector<pair<int,int>> vec;
char mat [999999][99999];
void buca( int i, int j)
{
	if(mat[i][j]=='L')
		return;
	con++;
	mat[i][j]='L';
	pair<int,int> aux;
	aux.first=i;
	aux.second=j;
	vec.push_back(aux);
	buca(i+1,  j);
	buca(i-1,  j);
	buca(i,  j+1);
	buca(i,  j-1);
}
int main()
{
	int casos;
	string cad;
	char blanco;
	cin>> casos;
	int col=0;
	int pon=0;
	while(getline(cin,cad))
	{
		
		if(cad[0]>='0' and cad[0]<='9')
		{
			con=0;
			int a=cad[0]-'0';
			int b=cad[3]-'0';
			if(b<0 or b>9)
				b=cad[2]-'0';
			buca(a,b);
			cout<<con<<endl;
			for(auto a: vec)
			{
				mat[a.first][a.second]='W';
			}
			vec.clear();
			pon=1;
		}
		else
		{
			if(pon==1)
				col=0;
			for(int i=0; i< tama; i++)
				mat[col][i]=cad[i];
			col++;
		}
	
	}
	return 0;
	
}