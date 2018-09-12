#include <bits/stdc++.h>
using namespace std;
int con;
int tama;
int col;
vector<pair<int,int>> vec;
string mat [9999];
void buca( int i, int j)
{
	if(mat[i][j]=='L')
		return;
	//cout<<i<<" "<<j<<" "<<tama<<" "<<col<<endl;
	con++;
	mat[i][j]='L';
	pair<int,int> aux;
	aux.first=i;
	aux.second=j;
	vec.push_back(aux);
	if(i<col-1)
		buca(i+1,  j);
	if(i!=0)
		buca(i-1,  j);
	if(j<tama-1)
		buca(i,  j+1);
	if(j!=0)
		buca(i,  j-1);
	if(i<col-1 and j<tama-1)
		buca(i+1,  j+1);
	if(i!=0 and j!=0)
		buca(i-1,  j-1);
	if(i!=0 and j<tama-1)
		buca(i-1,  j+1);
	if(j!=0 and i<col-1)
		buca(i+1,  j-1);
}
int main()
{
	int casos;
	string cad;
	char blanco;
	cin>> casos;
	col=0;
	int pon=0;
	while(getline(cin,cad))
	{
		
		if(cad[0]>='0' and cad[0]<='9')
		{

			stringstream ss(cad);
			con=0;
			int a;
			ss>>a;
			a--;
			int b;
			ss>>b;
			b--;
			//cout<<a<<" "<<b<<" "<<mat[a][b]<<endl<<endl;
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
			if(cad.size()!=0)
			{
				if(pon==1)
				{ 
					cout<<endl;
					string aux="";
					for(int i=0; i<col;i++)
						{
							//cout<<mat[i]<<endl;
							mat[i].clear();
							//cout<<mat[i]<<endl;
						}

					col=0;
					pon=0;
				}
				//cout<<cad<<endl;
				tama=cad.size();
				//cout<<" uno"<<endl;
				for(int i=0; i< cad.size(); i++)
					{
						mat[col].push_back(cad[i]);
						//cout<<cad[i]<<" ";
					}
					/*cout<<"  "<<mat[col];
					cout<<endl;*/
				col++;
			}

		}
	
	}
	return 0;
	
}