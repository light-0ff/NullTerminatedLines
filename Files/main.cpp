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
	std::ofstream fout; //Создание потока
	fout.open("File.txt", std::ios::app);//Создает файл "file.txt" //ios для рерима дозаписи (а не перезаписи)

	fout << "Hello World" << std::endl;
	fout << "Sam privet" << std::endl;
	/*fout.open("AnotherFile.txt"); //нелься пока не отвяжем прошлый файл
	fout << ("Sam privet")*/
	fout.close(); //Закрываем поток

	system("notepad File.txt");
#endif // write_to_file
#ifdef read_from_file
	std::ifstream fin;
	fin.open("File.txt");

	const int n = 256;
	char sz_buffer[n] = {};
	
	while (!fin.eof()) //пока не конец файла, выполняем программу //eof - возврящает true
	{
		//fin >> sz_buffer;
		fin.getline(sz_buffer, n);
		std::cout << sz_buffer << std::endl;
	}

	fin.close();
#endif // read_from_file
#ifdef switchs
	//открыть 2 файла
	//создать 2 буффера
		//один для мак адресов, другой для IP
	std::ifstream fin;
	//fin.open("list.txt");

	const int n = 256;
	char source_name[n] = {};
	std::cout << "Введите название соуса: "; std::cin.getline(source_name, n);
	if (!strstr(source_name, ".txt"))strcat(source_name, ".txt"); // для работы с тхт файлами
	fin.open(source_name);

	char mac_buffer[n] = {};
	char ip_buffer[n] = {};

	char filename[n]{}; //новый документ для переноса
	std::cout << "Введите название: "; std::cin.getline(filename, n);
	std::ofstream fout; 
	if (!strstr(filename, ".txt"))strcat(filename, ".txt"); //проверка на разширение .txt
	fout.open(filename);// сюда записываем
	while (!fin.eof()) 
	{
		fin >> mac_buffer; // копируем до пробела
		fin >> ip_buffer; //копируем после пробела
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
	std::cout << "Введите название: "; std::cin.getline(filename, n);
	std::ofstream fout; //Создание потока
	//char str2[] = ".txt";
	if(!strstr(filename, ".txt"))strcat(filename, ".txt");
	fout.open(filename);
	fout << "Hello World" << std::endl;
	fout << "Sam privet" << std::endl;
	fout.close();
#endif // create



}