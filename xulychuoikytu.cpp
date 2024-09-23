//bai toan dem so tu trong choi
/*
#include<bits/stdc++.h>
using namespace std;
void nhapchuoi(char S[])
{
	cout<<"moi nhap chuoi: ";
	cin.getline(S, 30);
}
int countword(char S[])
{
   int d=0;
   for(int i=0; i<strlen(S)-1; i++)
    if(S[i] == ' ' && S[i+1] != ' ')
        d++;
    if(S[0] != ' ')
        d++;
    return d;
}
int main()
{
	char S[100];
	nhapchuoi(S);
	cout<<"so tu trong chuoi: "<<countword(S);
}
*/
/*
tim kiem ki tu trung nhau va loai bo
#include<bits/stdc++.h>
using namespace std;
void nhapchuoi(char S[])
{
	cout<<"moi nhap chuoi: ";
	cin.getline(S, 30);
}
void deleteall(char S[], char C)
{
   for(int i=0; i<strlen(S); i++)
    while(S[i] == C)
     for(int j=i; j<strlen(S); j++)
    S[j] = S[j+1];
    cout<<S;
}
int main()
{
	char S[100];
	char C;
	nhapchuoi(S);
	cout<<"nhap C: ";
	cin>>C;
	 deleteall(S, C);
}
*/

//kiem tra hop le dau ()
#include<bits/stdc++.h>
using namespace std;
void nhapchuoi(char S[])
{
	cout<<"moi nhap chuoi: ";
	cin.getline(S, 50);
}
bool checkValid(char S[])
{
	int count1 = 0, count2= 0;
	for(int i=0; i<strlen(S); i++)
	{
		if(S[i]=='(')
		count1++;
		if(S[i]==')')
		count2++;
		if(count1 < count2) 
		return false;
	}
	if(count1 != count2) return false;
	return true;
}
int main()
{
	char S[100];
	nhapchuoi(S);
	cout<<"Ket qua kiem tra: "<<endl;
    if(checkValid(S))
    cout<<" hop le."<<endl;
    else
	 cout<<"Khong Hop le.";
}

