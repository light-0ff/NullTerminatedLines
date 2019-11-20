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
void isPalindrome(char str[]);

#define TAB "\t"

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//char str[] = "hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	const int n = 20;
	char str[n];
	cout << "Введите строку: ";
	//cin >> str;
	input_line(str, n);
	cout << TAB << str << endl;
	cout << StrLen(str) << endl; //проверка размера
	
	cout << "преобразует строку в верхний регистр: " << endl;
	UpperCase(str);
	cout << TAB << str << endl;

	cout << "преобразует строку в нижний регистр: " << endl;
	LowerCase(str);
	cout << TAB << str << endl;

	cout << "Каждое Слово С Большой Буквы: " << endl;
	Capitalize(str);
	cout << TAB << str << endl;

	cout << "Удаляем лишние пробелы: " << endl;
	Shrink(str);
	cout << TAB << str << endl;

	cout << "Без пробелов: " << endl;
	RemoveSpaces(str);
	cout << TAB << str << endl;
	
	cout << "Палиндром?: " << endl;
	isPalindrome(str);
	
	
	
}

void input_line(char str[], const int n)
{
	SetConsoleCP(1251); //кодтровка
	cin.getline(str, n);
	SetConsoleCP(866); //Русс для консоли
}
int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++); //будет выполнятся пока не ноль
	return i;
}
// В задании не было ограничения на передаваемые параметры
void UpperCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 32) str[i] -= 32;
	}
}
void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 32) str[i] += 32;
	}
}
void Capitalize(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (i == 0) str[i] -= 32;
		if (str[i - 1] == 32)
		{
			if (str[i] != 32)
			{
				str[i] -= 32;
			}
		}
	}
}
void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i - 1] == 32)
		{
			if (str[i] == 32)
			{
				int buffer = i;
				while (str[buffer] == 32) buffer++;
				do {
					str[i] = str[buffer];
					i++;
					buffer++;
				} while (str[buffer] != '\0');
				str[i] = '\0';
			}
		}
	}
}
void RemoveSpaces(char str[])
{
	for (int i = 0; str[i]; i++)
	{		
		if (str[i] == 32)
		{
			int buffer = i;
			while (str[buffer] == 32) buffer++;
			do {
				str[i] = str[buffer];
				i++;
				buffer++;
			} while (str[buffer] != '\0');
			str[i] = '\0';
		}
	}
}
void isPalindrome(char str[])
{
	int buffer = StrLen(str);
	int i = 0;
	int proverka = 0;
	for (; str[i]; i++)
	{
		if (str[i] == str[buffer - 1]) proverka++;
		buffer--;
	}
	if (i == proverka) cout << TAB << "it IS palindrom" << endl;
	else cout << TAB << "It NOT" << endl;
}