//cout - (ostream)
//cin - (iostream)
//fin - (ofstream)
//fout - (ifstream)
#include<iostream>
#include<fstream>

//#define write_to_file
//#define read_from_file
#define switchs
//#define create

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

	char mac_buffer[n] = {};
	char ip_buffer[n] = {};

	char filename[n]{}; //����� �������� ��� ��������
	std::cout << "������� ��������: "; std::cin.getline(filename, n);
	std::ofstream fout; 
	if (!strstr(filename, ".txt"))strcat(filename, ".txt"); //�������� �� ���������� .txt
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



}