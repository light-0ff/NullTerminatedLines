#include<iostream>
#include<Windows.h>
using namespace std;

void input_line(char str[], const int n);
int StrLen(char str[]);
void UpperCase(char str[]);
void LowerCase(char str[]);
void Capitalize(char str[]);
void Shrink(char str[]);
void RemoveSpaces(char str[]);
bool isPalindrom(char str[]);

void Capitalize2(char str[]);
void Shrink2(char str[]);
bool isPalindrom2(char str[]);
bool isNomber(char str[]);
int StrToInt(char str[]);
bool isBin(char str[]);
int BinToDec(char str[]);
bool isHex(char str[]);
int HexToDec(char str[]);

#define TAB "\t"

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//char str[] = "hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	const int n = 200;
	char str[n];
	
	cout << "������� ������: ";
	//cin >> str;
	input_line(str, n);
	cout << TAB << str << endl;
	cout << StrLen(str) << endl; //�������� �������
	
	//cout << "����������� ������ � ������� �������: " << endl;
	//UpperCase(str);
	//cout << TAB << str << endl;

	//cout << "����������� ������ � ������ �������: " << endl;
	//LowerCase(str);
	//cout << TAB << str << endl;

	//cout << "������� ������ �������: " << endl;
	//Shrink(str);
	//cout << TAB << str << endl;

	//cout << "������ ����� � ������� �����: " << endl;
	//Capitalize(str);
	//cout << TAB << str << endl;

	//cout << "��� ��������: " << endl;
	//RemoveSpaces(str);
	//cout << TAB << str << endl;
	////////////////////////////
	//cout << "���������?: " << endl;
	//bool palindrom = isPalindrome(str);
	//if (palindrom) cout << TAB << "it IS palindrom" << endl;
	//else cout << TAB << "It's NOT" << endl;
	////////////////////////////
	
	//cout << "��������� ������� � int: " << endl;
	//int into = StrToInt(str);
	//cout << into << endl;

	//cout << "��������� ������� � ����������: " << endl;
	//int bin = BinToDec(str);
	//cout << bin << endl;

	//cout << isHex(str) << endl;
	cout << "��������� ������� � 16������: " << endl;
	int hex = HexToDec(str);
	cout << hex << endl;
	
}

void input_line(char str[], const int n)
{
	SetConsoleCP(1251); //���������
	cin.getline(str, n);
	SetConsoleCP(866); //���� ��� �������
}
int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++); //����� ���������� ���� �� ����
	return i;
}
// � ������� �� ���� ����������� �� ������������ ���������
void UpperCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�') str[i] -= 32;
	}
}
void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�') str[i] += 32;
	}
}
void Capitalize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�') str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] > ' ')
			{
				str[i] -= 32;
			}
		}
	}
}
void Shrink(char str[])
{
	int buffer = 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i - 1] == ' ') && (str[i] == ' '))
		{
			buffer = i;
			while (str[buffer] == ' ') buffer++; // ����� �� 0
		}
		if (buffer != 0)
		{
			str[i] = str[buffer];
			buffer++;
		}
		if (str[buffer] == '\0') str[i + 1] = '\0';
	}
}
void RemoveSpaces(char str[])
{
	int buffer = 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == ' ') && (str[i] < 1))
		{
			buffer = i;
			while (str[buffer] == ' ') buffer++; // ����� �� "������"
		}
		if (str[buffer] != 0)str[i] = str[buffer];
		if (str[i] == ' ') i--;
		buffer++;
		if (str[buffer] == '\0') str[i + 1] = '\0';
	}
}
bool isPalindrom(char str[])
{
	int buffer = StrLen(str);
	char copy[200];
	for (int i = 0; i <= buffer; i++) copy[i] = str[i];
	RemoveSpaces(copy); //��� ��������
	LowerCase(copy); //��� � ��������� �
	int i = 0;
	int proverka = 0;
	for (; copy[i]; i++)
	{
		if (copy[i] == copy[buffer - 1]) proverka++;
		buffer--;
	}
	if (i == proverka) return true;
	else return false;
}
//void Shrink(char str[])
//{
//	for (int i = 0; str[i]; i++)
//	{
//		if (str[i - 1] == 32)
//		{
//			if (str[i] == 32)
//			{
//				int buffer = i;
//				while (str[buffer] == 32) buffer++;
//				do {
//					str[i] = str[buffer];
//					i++;
//					buffer++;
//				} while (str[buffer] != '\0');
//				str[i] = '\0';
//			}
//		}
//	}
//}
//void RemoveSpaces(char str[]) //�� �������� � ����������� ����������
//{
//	int buffer = 0;
//	for (int i = 0; str[i]; i++)
//	{		
//		if (str[i] == 32)
//		{
//			if (buffer == 0 ) buffer = i;
//			while (str[buffer] == 32) buffer++;
//			do {
//				str[i] = str[buffer];
//				i++;
//				buffer++;
//			} while ((str[i] != 32) && (str[buffer] != '\0'));
//			if(str[buffer] == '\0') str[i] = '\0';
//			else i -= 2;
//		}
//	}
//}
void Capitalize2(char str[])
{

	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�') str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{

		if (
			(str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�') &&
			str[i - 1] == ' ')
		{
			str[i] -= 32;
		}
	}
}
void Shrink2(char str[])
{
	int buffer = 0;
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
				for (int j = i + 1; str[i]; i++)	str[i] = str[j + 1];
		}
	}
}
bool isPalindrom2(char str[])
{
	//int size = StrLen(str);
	//char* buffer = new char[size + 1] {};
	//for (int i = 0; i < size; i++)buffer[i] = str[i]; // ��������� ������
	//LowerCase(buffer);
	//RemoveSpaces(buffer); //��� ��������
	//size = StrLen(buffer);
	//for (int i = 0; i < size / 2; i++)
	//{
	//	if (buffer[i] != buffer[size - 1 - i]) return false;
	//}
	//return true;
	int size = StrLen(str);
	for (int i = 0; i < size / 2; i++)
	{
		if (str[i] == ' ')i++; size++;
		if (str[size - 1 - i] == ' ')size--;
		if (str[i] != str[size - 1 - i])
		{
			if (str[i] + 32 != str[size - 1 - i] && str[i] != str[size - 1 - i])return false;
		}
	}
	return true;
}
bool isNomber(char str[]) //��������� �������� �� ������� ��������
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0'&&str[i] <= '9')) return false;
	}
	return true;
}
int StrToInt(char str[])
{
	int num = 0; 
	if (isNomber(str))
	{
		for (int i = 0; str[i]; i++) 
		{
			num *= 10;
			num += str[i] - 48;
		}
	}

	return num;
}
bool isBin(char str[]) 
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] == '0' || str[i] == '1')) return false;
	}
	return true;
}
int BinToDec(char str[]) // �� �������� � ������� � ���������
{
	int num = 0;
	int pow = 1;
	if (isBin(str))
	{
	//	/*for (int i = 0; i < StrLen(str); i++)
	//	{
	//		if (str[i] == '1')
	//		{
	//			int stepen = 2;
	//			for (int j = 1; j < StrLen(str) - i; j++)
	//			{
	//				stepen *= 2;
	//			}
	//			num += stepen;
	//		}
	//	}
	//	num /= 2;
		for (int i = StrLen(str) - 1; i >= 0; i--, pow *= 2)
		{
			if (str[i] == '1')num += pow;
		}
	}
		
	return num;
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
int HexToDec(char str[])
{
	int num = 0;
	int pow = 1;
	int otvet = 0;
	if (isHex(str))
	{
		for (int i = StrLen(str) - 1; i >= 0; i--, pow *= 16)
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
