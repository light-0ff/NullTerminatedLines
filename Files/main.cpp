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
	char notepad[] = "notepad ";
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
#ifdef domashka
	std::ifstream fin;

	const int n = 256;
	char source_name[n] = {};
	std::cout << "Напиши: result  "; std::cin.getline(source_name, n);
	if (!strstr(source_name, ".txt"))strcat(source_name, ".txt"); // для работы с тхт файлами
	fin.open(source_name);

	char buffer_1[40] = {};
	char buffer_2[40] = {};

	char filename[n]{}; //новый документ для переноса
	std::cout << "Напиши: list  "; std::cin.getline(filename, n);
	std::ofstream fout;
	if (!strstr(filename, ".txt"))strcat(filename, ".txt"); //проверка на разширение .txt
	fout.open(filename);// сюда записываем

	//for (int i = 0; source_name[i]; i++)
	//{
	//	fin >> buffer_1;	
	//	fin >> buffer_2;
	//	fout << buffer_1 << " ";
	//	fout << buffer_2 << std::endl;
	//	//if(buffer_1 == "{") // ненаходит {
	//	//{
	//	//	fout << std::endl << buffer_1 << std::endl;
	//	//}
	//	//else 	fout << buffer_1 << " ";
	//}
	
	while (!fin.eof())
	{
		fin >> buffer_1; // копируем до пробела
		fin >> buffer_2; //копируем после пробела
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
	const int n = 256;
	char source_file[n]{};
	char dest_file[n]{};
	std::cout << "Введите имя соуса: "; std::cin >> source_file;
	std::cout << "Введите имя конечного файла: "; std::cin >> dest_file;
	if (!strstr(source_file, ".txt"))strcat(source_file, ".txt"); 
	if (!strstr(dest_file, ".txt"))strcat(dest_file, ".txt"); 

	std::ifstream fin(source_file);
	std::ofstream fout(dest_file);

	char mac_buffer[n]{};
	char ip_buffer[n]{};
		
	for (int i=1; !fin.eof();i++)
	{
		fin >> mac_buffer;
		fin >> ip_buffer;
		fout << "host-" << i << std::endl;
		fout<<"{\n";
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

}