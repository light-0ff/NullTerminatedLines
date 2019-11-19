#include<iostream>
using namespace std;


void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//char str[] = "hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	const int n = 20;
	char str[n];
	cout << "¬ведите строку: ";
	//cin >> str;
	cin.getline(str, n);
	cout << str << endl;

}