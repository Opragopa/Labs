#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<cstdio>

#pragma warning(disable : 4996)

//� ������� ����� ����� ����� ����� ������������� 
//�����, ������ ��������� �����������, ���� a[i] > a[i + 1] > a[i + 2]

int sorting(int* array, int size)		//���������� "�����"
	{
		int count = 0;
		for (int i = 0; i < (size - 2); i++) {
			if ((array[i] > array[i + 1]) && (array[i + 1] > array[i + 2])) {
				count += 1;
			}
		}
		return count;
	}

int main()
	{
	//1) ����������� ������
	const int sizeOfConst = 10;
	int constArray[sizeOfConst] = { 6,5,4,3,6,7,4,10,13,17 };
	std::cout << "Size of constArray = " << sizeOfConst << std::endl;
	for (int i = 0; i < sizeOfConst; i++)
	{
		std::cout << constArray[i] << " ";
	}
	std::cout << "\nAmount = " << sorting(constArray, sizeOfConst) << std::endl;
	//

	std::cout << "\n";

	//2) ������������ ������
	srand(time(nullptr));
	int sizeOfDynamic;
	std::cout << "Size of dynamicArray = ";
	std::cin >> sizeOfDynamic;
	int* dynamicArray = new int[sizeOfDynamic];
	for (int i = 0; i < sizeOfDynamic; i++) {
		dynamicArray[i] = rand() % 100 + 1;
		std::cout << dynamicArray[i] << " ";
	}
	std::cout << "\nAmount = " << sorting(dynamicArray, sizeOfDynamic) << "\n";
	delete []dynamicArray;
	//

	std::cout << "\n";

	//3) ������ ������� �� �����

	freopen("Array.txt", "r", stdin);
	int sizeOfFileArray;
	while (std::cin >> sizeOfFileArray) {
		int* fromFileArray = new int[sizeOfFileArray];
		for (int i = 0; i < sizeOfFileArray; i++) {
			std::cin >> fromFileArray[i];
			std::cout << fromFileArray[i] << " ";
		}

		std::cout << "\nAmount = " << sorting(fromFileArray, sizeOfFileArray);
		delete[]fromFileArray;
	}

	//���� - ���������� �� ����� � ������� ������� fstream[����������];

	//int N3 = 0;
	//int* fromFileArray = new int[N3];
	//std::string line;
	//std::string path = "Array.txt"; // ���� � �����
	//std::ifstream file(path); // �������� ���� ��� ������
	//if (file.is_open())
	//{
	//	bool checkLine = true;
	//	std::cout << "File is open!\n\n";
	//	while (getline(file, line))
	//	{
	//		if (checkLine = true) 
	//		{
	//			N3 = atoi(line.c_str()); // atoi - �������������� string � int;
	//			checkLine = false;
	//		}
	//		if (checkLine = false)
	//		{
	//			for (int i = 0; i < N3; i++)
	//			{
	//				*fromFileArray = atoi(line.c_str());
	//			}
	//			checkLine = true;
	//		}
	//	}
	//}
	//else
	//{
	//	std::cout << "Reading error!\n";
	//}
	//file.close();
	//

	//

	return -1;
	}