#include<iostream>
#include<Windows.h>
//using namespace std;

bool isNomber(char str[]);
int StrToInt(char str[]);
char* dec_to_bin(int dec);
bool isHex(const char* str);
int hex_to_dec(char str[]);

bool is_hex_number(const char* str);
int hex_to_dec2(const char* str);

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

	//std::cout << "¬ведите 16ричную строку: ";
	//std::cin >> str;
	//int hex = hex_to_dec(str);
	//std::cout << hex << std::endl;

	const int q = 9;
	char her[q];
	std::cout << "¬ведите 16ричную строку: "; std::cin >> her;
	std::cout << is_hex_number(her) << std::endl;
	int hex = hex_to_dec(her);
	std::cout << hex << std::endl;
	
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
	for (int i = 0; i < n / 2; i++) std::swap(binary[i], binary[n - 1 - i]);
	return binary;
}
bool isHex(const char* str)
{
	int i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) i = 2;
	for (; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9' ||
			str[i] >= 'A' && str[i] <= 'F' ||
			str[i] >= 'a' && str[i] <= 'f')) return false;
	}
	return true;
}
//int hex_to_dec(char str[])
//{
//	int num = 0;
//	int pow = 1;
//	int otvet = 0;
//	if (isHex(str))
//	{
//		for (int i = strlen(str) - 1; i >= 0; i--, pow *= 16)
//		{
//			if (str[i] >= '0' && str[i] <= '9') num = str[i] - 48;
//			else if (str[i] >= 'A' && str[i] <= 'F') num = str[i] - 55;
//			else num = str[i] - 87;
//			int buffer = num;
//			if (pow != 1) for (int j = 0; j < pow - 1; j++)
//			{
//				num += buffer;
//			}
//			otvet += num;
//		}
//	}
//	return otvet;
//}
int hex_to_dec(char str[])
{
	int num = 0;
	int pow = 1;
	if (isHex(str))
	{
		for (int i = strlen(str) - 1; i >= 0; i--, pow *= 16)
		{
			if (str[i] >= '0' && str[i] <= '9') str[i] = str[i] - 48;
			else if (str[i] >= 'A' && str[i] <= 'F') str[i] = str[i] - 55;
			else str[i] = str[i] - 87;
			int buffer = str[i];
			if (pow != 1) for (int j = 0; j < pow - 1; j++)	str[i] += buffer;
			num += str[i];
		}
	}
	return num;
}
////////////////////////////////
bool is_hex_number(const char* str)
{
	int i = 0;
	if (str[0] == '0' && (str[1] == 'x'|| str[1] == 'X')) i = 2;
	for (; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')) return false;
	}
	return true;
}
int hex_to_dec2(const char* her)
{
	if (!is_hex_number(her)) return 0;
	int decimal = 0;
	int pow = 1;
	for (int i = her[1] == 'x' || her[1] == 'X' ? 2 : 0;her[i]; i++)
	{
		pow *= 16;
		if (her[i] >= '0'&&her[i] >= '9') decimal += her[i] - '0';
		else if (her[i] >= 'A'&&her[i] >= 'F') decimal += her[i] - 'A' + 10;
		else if (her[i] >= 'a'&&her[i] >= 'f') decimal += her[i] - 'a' + 10;
	}
	
	return decimal;
}