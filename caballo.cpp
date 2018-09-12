#include <bits/stdc++.h>
using namespace std;
int a,b;
int uno_x, dos_y,limite_y,limite_x;
vector<int> vec;
char tablero[100][100];
int ban=1;
int renglones;
int columnas;
void fun(int con, int x, int y)
{

	
	for(int h=renglones-1; h>=0; h--)
		{
			for(int g=0; g<columnas; g++)
			
				cout<<tablero[h][g]<<" ";
			cout<<endl;
		}
	//cout<<"aqui  "<<x+1<<"  "<<y+1<<"  con: "<<con<<endl;
	if(x>limite_x or x<0 or y>limite_y or y<0 or (tablero[x][y]!='*' and ban!=1))
	{	
		//con--;
		return;
	}
	if(tablero[y][x]=='w')
	{
		//cout<<uno_x<<"  "<<dos_y<<endl;
		vec.push_back(con);
		return;
	}
	tablero[y][x]='h';
	ban=0;
	
	if(tablero[x+1][y+2]=='*' and x+1<limite_x and y+2<limite_y )
		{
			//x+=1;y+=2;
			cout<<" en: "<<1<<endl;
			fun(con+1,x+1,y+2);
			//x-=1;y-=2;	
		}
	
	if(x-1>=0)
	if(tablero[x-1][y+2]=='*' and y+2<limite_y )
		{
			//x-=1;y+=2;
			cout<<" en: "<<2<<endl;
			fun(con+1,x-1,y+2);
			//x+=1;y-1;
		}
	
	
	if(tablero[x+2][y+1]=='*' and x+2<limite_x and y+1<limite_y )
		{
			//x+=2;y+=1;
			cout<<" en: "<<3<<endl;
			fun(con+1,x+2,y+1);
			//x-=2;y-=1;
		}
	
	if(y-1>=0)
	if(tablero[x+2][y-1]=='*' and x+2<limite_x  )
		{
			//x+=2;y=-1;
			cout<<" en: "<<4<<endl;
			fun(con+1,x+2,y-1);
			//x-=2;y+=1;
		}
	
	if(y-2>=0)
	if(tablero[x+1][y-2]=='*' and x+1<limite_x )
		{
			//x+=1;y-=2;
			cout<<" en: "<<5<<endl;
			fun(con+1,x+1,y-2);
			//x-=1;y+=2;
		}
	
	if(x-1>=0 and y-1>=0)
	if(tablero[x-1][y-1]=='*')
		{
			//x-=1;y-=2;
			cout<<" en: "<<6<<endl;
			fun(con+1,x-1,y-2);
			//x+=1;y+=2;
		}
	
	if(y-1>=0)
	if(tablero[x+2][y-1]=='*' and x+2<limite_x )
		{
			//x+=2;y-=1;
			cout<<" en: "<<7<<endl;
			fun(con+1,x+2,y-1);
			//x-=2;y+=1;
		}
		if(y-1>=0 and x-2>=0)
		if(tablero[x-2][y-1]=='*' )
		{
			//x-=2;y-=1;
			cout<<" en: "<<8<<endl;
			fun(con+1,x-2,y-1);
			//x+=2;y+=1;
		}
	

}
int main()
{
	int casos;
	cin>>casos;
	memset(tablero,0,sizeof(tablero));
	for(int i=0; i<casos; i++)
	{
		int con=0,x,y;
		cin>>renglones>>columnas;
		limite_y=renglones-1;
		limite_x=columnas-1;
		
		for(int h=renglones-1; h>=0; h--)
		{
			for(int g=0; g<columnas; g++)
			{
				cin>>tablero[h][g];
				if(tablero[h][g]=='c')
				{
					x=g;
					y=h;
				}
			}

		}
	
		cin>>dos_y>>uno_x;	
		//cout<<" dos_y: "<<dos_y<<" uno_x: "<<uno_x<<endl;
		dos_y--;
		uno_x--;	
		tablero[dos_y][uno_x]='w';
		fun(0,x,y);
		if(vec.size()!=0)
		{
			sort(vec.begin(),vec.end());
			cout<<vec[0]<<endl;
		}
		
	}
}