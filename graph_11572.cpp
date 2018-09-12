#include<bits/stdc++.h>
using namespace std;
int ss;
int con;
map <int,int> mapa;
map <int,int> ind;
int arr[1000002];
void fun(int a)
{
	//cout<<a<<endl;
	con++;
	if(mapa[a]==-1)
	{
		mapa[a]=0;
	}
	if( mapa[a]==0)
		return;
	ss=mapa[a];
	mapa[a]=0;
	//ind[a]=0;
	fun(ss);
	return;
}
 int main()
 {
 	int casos,numeros;
 	cin>>casos;
 	int a;
 	for(int i=0; i<casos; i++)
 	{
 		int pp=0;
 		int ant;
 		int may=0;
 		//memset(arr,0,sizeof(arr));
 		cin>>numeros;
 		for(int j=1; j<=numeros; j++)
 		{
 			/*cout<<j<<endl;
 			for(auto q: mapa)
 			{
 				cout<<q.first<<" :"<<q.second<<endl;
 			}
 			cout<<endl;*/
 			cin>>a;
 			if(a==0)
 				a=-5;
 			if(j==1)
 			{	
 				pp++;
 				mapa[a]=-1;
 			}
 			else
 			{

	 			if(mapa[a]!=0 )
	 			{
	 				//cout<<"  :"<<pp<<endl;
	 				if(may<pp)
	 					may=pp;
	 				con=0;
	 				if(mapa[a]!=-1)
	 				{
		 				fun(mapa[a]);
		 				pp-=con;
		 				int gua;
		 				for(auto h: mapa)
		 				{
		 					if(h.second==a)
		 						gua=h.first;
		 				}
		 				mapa[gua]=-1;
		 				mapa[a]=ant;
		 			}
		 			else
		 			{
		 				int u=-1;
		 				for(auto h: mapa)
		 				{
		 					if(h.second==a)
		 						u=h.first;
		 				}
		 				if(u==-1)
		 					mapa[a]=u;
		 				else
		 				{
		 					mapa[u]=-1;
		 				}
		 			}


	 			}
	 			else
	 			{
	 				pp++;
	 				mapa[a]=ant;
	 			}
	 			
	 		}
	 		ant =a;
 		}
 		//cout<<pp<<" "<<may<<endl;
 		if(may<pp )
	 		may=pp;

 		cout<<may<<endl;
 	//	cout<<endl;
 		mapa.clear();
 	}

 }