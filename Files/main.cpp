//cout - (ostream)
//cin - (iostream)
//fin - (ofstream)
//fout - (ifstream)
#include<iostream>
#include<fstream>

//#define write_to_file
//#define read_from_file
//#define switchs
//#define create
//#define domashka
#define mac_proverka

void main()
{
	setlocale(LC_ALL, "");
#ifdef write_to_file
	std::cout << "Hello World" << std::endl;
	std::ofstream fout; //�������� ������
	fout.open("File.txt", std::ios::app);//������� ���� "file.txt" //ios ��� ������ �������� (� �� ����������)

	fout << "Hello World" << std::endl;
	fout << "Sam privet" << std::endl;
	/*fout.open("AnotherFile.txt"); //������ ���� �� ������� ������� ����
	fout << ("Sam privet")*/
	fout.close(); //��������� �����

	system("notepad File.txt");
#endif // write_to_file
#ifdef read_from_file
	std::ifstream fin;
	fin.open("File.txt");

	const int n = 256;
	char sz_buffer[n] = {};
	
	while (!fin.eof()) //���� �� ����� �����, ��������� ��������� //eof - ���������� true
	{
		//fin >> sz_buffer;
		fin.getline(sz_buffer, n);
		std::cout << sz_buffer << std::endl;
	}

	fin.close();
#endif // read_from_file
#ifdef switchs
	//������� 2 �����
	//������� 2 �������
		//���� ��� ��� �������, ������ ��� IP
	std::ifstream fin;
	//fin.open("list.txt");

	const int n = 256;
	char source_name[n] = {};
	std::cout << "������� �������� �����: "; std::cin.getline(source_name, n);
	if (!strstr(source_name, ".txt"))strcat(source_name, ".txt"); // ��� ������ � ��� �������
	fin.open(source_name);

	char filename[n]{}; //����� �������� ��� ��������
	std::cout << "������� ��������: "; std::cin.getline(filename, n);
	std::ofstream fout; 
	if (!strstr(filename, ".txt"))strcat(filename, ".txt"); //�������� �� ���������� .txt

	char mac_buffer[n] = {};
	char ip_buffer[n] = {};

	fout.open(filename);// ���� ����������
	while (!fin.eof()) 
	{
		fin >> mac_buffer; // �������� �� �������
		fin >> ip_buffer; //�������� ����� �������
		fout << ip_buffer << "\t\t";
		fout << mac_buffer << std::endl;
	}
	fin.close();

	fout.close(); 
	char notepad[n] = "notepad ";
	strcat(notepad, filename);
	system(notepad);
	//system("notepad list.txt");
#endif // switchs
#ifdef create
	const int n = 256;
	char filename[n]{};
	std::cout << "������� ��������: "; std::cin.getline(filename, n);
	std::ofstream fout; //�������� ������
	//char str2[] = ".txt";
	if(!strstr(filename, ".txt"))strcat(filename, ".txt");
	fout.open(filename);
	fout << "Hello World" << std::endl;
	fout << "Sam privet" << std::endl;
	fout.close();
#endif // create
#ifdef domashka
	std::ifstream fin;

	const int n = 256;
	char source_name[n] = {};
	std::cout << "������: result  "; std::cin.getline(source_name, n);
	if (!strstr(source_name, ".txt"))strcat(source_name, ".txt"); // ��� ������ � ��� �������
	fin.open(source_name);

	char buffer_1[40] = {};
	char buffer_2[40] = {};

	char filename[n]{}; //����� �������� ��� ��������
	std::cout << "������: list  "; std::cin.getline(filename, n);
	std::ofstream fout;
	if (!strstr(filename, ".txt"))strcat(filename, ".txt"); //�������� �� ���������� .txt
	fout.open(filename);// ���� ����������

	//for (int i = 0; source_name[i]; i++)
	//{
	//	fin >> buffer_1;	
	//	fin >> buffer_2;
	//	fout << buffer_1 << " ";
	//	fout << buffer_2 << std::endl;
	//	//if(buffer_1 == "{") // ��������� {
	//	//{
	//	//	fout << std::endl << buffer_1 << std::endl;
	//	//}
	//	//else 	fout << buffer_1 << " ";
	//}
	
	while (!fin.eof())
	{
		fin >> buffer_1; // �������� �� �������
		fin >> buffer_2; //�������� ����� �������
		if (buffer_1 != "{" && buffer_1 != "}")	fout << buffer_1 << " ";
		else  fout << std::endl << buffer_1 << std::endl;
		if (buffer_2 != "{" && buffer_2 != "}")	fout << buffer_2 << std::endl;
		else  fout << std::endl << buffer_2 << std::endl;
	}
	fin.close();

	fout.close();
	char notepad[n] = "notepad ";
	strcat(notepad, filename);
	system(notepad);
#endif // domashka
#ifdef mac_proverka

	const int n = 256;

	std::ifstream fin;
	std::ofstream fout;

	char source_file[n]{}; /*����*/					
	std::cout << "������� ��� �����: "; std::cin.getline(source_file, n);
	if (!strstr(source_file, ".txt"))strcat(source_file, ".txt"); 
	fin.open(source_file);
	
	char dest_file[n]{};   /*���� ����������*/		
	std::cout << "������� ��� ��������� �����: "; std::cin.getline(dest_file, n);
	if (!strstr(dest_file, ".txt"))strcat(dest_file, ".txt"); 
	

	/*std::ifstream fin(source_file);
	std::ofstream fout(dest_file);*/

	char mac_buffer[n]{};
	char ip_buffer[n]{};
////////////////////////////////////
	for (int i = 0; !fin.eof(); i++)		//����� ���� �������� ������� �����
	{
		fin >> mac_buffer;
		
		for (int j = 0; mac_buffer[j]; j++)
		{
			if (mac_buffer[j] == '.') 
			{
				std::cout << "this is IP: " << mac_buffer << std::endl;
				break;
			}
			if (mac_buffer[j] == ':')
			{
				std::cout << "this is MAC: " << mac_buffer << std::endl;
				break;
			}
		}
	}
///////////////////////////////////
	fout.open(dest_file);
	for (int i=1; !fin.eof();i++)
	{
		fin >> mac_buffer;
		fin >> ip_buffer;
		fout << "host-" << i << std::endl;
		fout << "{\n";
		fout << "\thehardware-ethernet\t" << mac_buffer << ";\n";
		fout << "\tfixed-address\t" << ip_buffer << ";\n";
		fout << "}\n";

		//fin >> ip_buffer;
		std::cout << "host-" << i << std::endl;
		std::cout << "{\n";
		std::cout << "\thehardware-ethernet\t" << mac_buffer << ";\n";
		std::cout << "\tfixed-address\t" << ip_buffer << ";\n";
		std::cout << "}\n";
	}
	fin.close();
	fout.close();
	char command[n] = "system ";
	strcat(command, dest_file);
#endif // mac_proverka

}