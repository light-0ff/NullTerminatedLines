#include<iostream>
#include<Windows.h>
using namespace std;

bool isNomber(char str[]);
int StrToInt(char str[]);
char* dec_to_bin(int dec);
bool isHex(char str[]);
int hex_to_dec(char str[]);

#define TAB "\t"

void main()
{
	setlocale(LC_ALL, "");
	/*int dec;
	cout << "¬ведите дес€тмчное число: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary;
	delete[] binary;*/
	const int n = 100;
	char str[n];

	cout << "¬ведите 16ричную строку: ";
	cin >> str;
	int hex = hex_to_dec(str);
	cout << hex << endl;
}
char* dec_to_bin(int dec) 
{
	int n = 32;
	char* binary = new char[n] {};
	for (int i = 0; dec; i++, dec /= 2)	binary[i] = dec % 2 + 48;
	/*for (n--; n >= 0; n--)
	{
		cout << binary[n];
		if (n % 8 == 0)cout << " ";
		if (n % 4 == 0)cout << " ";
	}
	cout << endl;*/
	n = strlen(binary);
	for (int i = 0; i < n / 2; i++) swap(binary[i], binary[n - 1 - i]);
	return binary;
}
bool isHex(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9' ||
			str[i] >= 'A' && str[i] <= 'F' ||
			str[i] >= 'a' && str[i] <= 'f')) return false;
	}
	return true;
}
int hex_to_dec(char str[])
{
	int num = 0;
	int pow = 1;
	int otvet = 0;
	if (isHex(str))
	{
		for (int i = strlen(str) - 1; i >= 0; i--, pow *= 16)
		{
			if (str[i] >= '0' && str[i] <= '9') num = str[i] - 48;
			else if (str[i] >= 'A' && str[i] <= 'F') num = str[i] - 55;
			else num = str[i] - 87;
			int buffer = num;
			if (pow != 1) for (int j = 0; j < pow - 1; j++)
			{
				num += buffer;
			}
			otvet += num;
		}
	}
	return otvet;
}
////////////////////////////////
