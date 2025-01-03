#include<iostream>
#include"clsStrig.h"
using namespace std;

int main()
{
	clsString S1;
	clsString S2("Maytham hassn","#//#",'/');

	cout << S2.CountEachWordInString();
	cout << S2.Value<<endl;
	S1.Value = "King Maytham 1m0";
	cout << S1.Value << endl;
	cout<<S2.LowerAllLetterOfString()<<endl;
	cout << S2.UpperAllLetterOfString();

	cout<<clsString::UpperAllLetterOfString("Maytham");
	system("pause>0");
	return 0;
}