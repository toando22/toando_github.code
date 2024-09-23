#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(a ==0 )return b;
	if(b == 0) return a;
	if (a == b) return a;
	if(a> b) return gcd(a - b, b);
	if(a < b) return gcd(a, b- a);
}
int timptnghichdao(int m, int a)
{
	int m0= m;
	int y =0, x =1;
	if(m == 1) return 0;
	while(a > 1){
		int q = a/m;
		int t = m;
		m = a %m, a= t;
		t = y;
		y = x - q*y;
		x =t ;
	}
	if (x< 0)
	x += m0;
	return x;
}
string giaima(string banma, int a, int b)
{
	string cipherText = " ";
	int x = timptnghichdao(26, a);
	for(int i = 0; i < banma.length(); i++)
	{
		if(islower(banma[i])){
			cipherText +=(char)((x*(banma[i] - 'a' - b + 26)% 26) +'a');
		}else if(isupper(banma[i])){
			cipherText +=(char) ((x*(banma[i] - 'A' - b + 26) %26) + 'A');
		}else if(banma[i] == ' '){
			cipherText += ' ';
		}else {
			cipherText += banma[i];
		}
	}
	return cipherText;
}
int main()
{
	int a, b;
	string banma;
	do{
		cout<<"\n Moi nhap a: ";
		cin>>a;
	}while (gcd(26, a) != 1);
		cout<<"\n Moi nhap b: ";
		cin>>b;
		cin.ignore();
		cout<<"\n Moi nhap ban ma: ";
		getline(cin, banma);
		cout<<"\n Ban ro: "<<giaima(banma, a, b);	
}