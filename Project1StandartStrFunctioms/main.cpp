#include<iostream>

void main()
{
	setlocale(LC_ALL, "");
	const int n = 256;
	/*
	char str[n]{};
	std::cout << "¬ведите строчку: "; std::cin.getline(str, n);
	std::cout << str << std::endl;
	std::cout << strlen(str) << std::endl;

	char buffer[n] = {};
	strcpy(buffer, str);
	std::cout << buffer << std::endl;*/

	//char str1[n] = "Hello";
	//char str2[] = "World";
	//strcmp(str1, str2);
	//std::cout << str1 << std::endl;

	const char* words[] =
	{
		"Hello",
		"World",
		"computer",
		"C++",
		"December"
	};
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		for (int j = i + 1; j < sizeof(words) / sizeof(const char*); j++)
		{			
			if (words[i] < words[j])
			{
				const char* buffer = words[i];
				words[i] = words[j];
				words[j] = buffer;
			}			
		}
	}
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
}