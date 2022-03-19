#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
//=====================================================================
struct Production
{
	string firma;		// �������� ����� ����������
	string adr2;		// ����������� ����� 
	int type;			// 1- ��������� �����, 2- ��������� ������������	
	double balance;		// ������
};
//=====================================================================
void f1(vector <Production> arr, int* n)
{
	string name;
	cout << "������� �������� �����: ";
	cin >> name;
	for (int i = 0; i < *n; i++)
	{
		if (name == arr[i].firma)
		{
			cout << "-------------------------������������ " << "#" << i + 1 << "------------------------------" << endl << endl;
			cout << "��������: " << arr[i].firma << endl;
			cout << "��. ������: " << arr[i].adr2 << endl;
			cout << "���: " << arr[i].type << endl;
			cout << "������: " << arr[i].balance << endl;
		}
	}
}
//=====================================================================
void f2(vector <Production> arr, int* n)
{
	int type = 0;
	do
	{
		cout << "������� ���: " << endl;
		cin >> type;
	} while (type != 1 && type != 2);
	for (int i = 0; i < *n; i++)
	{
		if (type == arr[i].type)
		{
			cout << "-------------------------������������ " << "#" << i + 1 << "------------------------------" << endl << endl;
			cout << "��������: " << arr[i].firma << endl;
			cout << "��. ������: " << arr[i].adr2 << endl;
			cout << "���: " << arr[i].type << endl;
			cout << "������: " << arr[i].balance << endl;
		}
	}
}
//=====================================================================
void f3(vector <Production>& arr, int* n)
{
	for (int i = 0; i < *n; i++)
	{
		int SmallestIndex = i;
		for (int j = i + 1; j < *n; j++)
		{
			if (arr[SmallestIndex].balance > arr[j].balance)
				SmallestIndex = j;
		}
		swap(arr[i], arr[SmallestIndex]);
	}
}
//=====================================================================
void f4(vector <Production>& arr, int* n)
{
	int newN = 0;
	cout << "������� ���-�� ����� �����������:";
	cin >> newN;
	newN += *n;
	vector <Production> newArr(newN);
	for (int i = 0; i < *n; i++)
	{
		newArr[i] = arr[i];
	}

	for (int i = *n; i < newN; i++)
	{
		cout << "-------------------------������������ " << "#" << i + 1 << "------------------------------" << endl << endl;
		cout << "��������: ";
		cin >> newArr[i].firma;
		cout << "��. ������: ";
		cin.ignore();
		getline(cin, newArr[i].adr2);
		do
		{
			cout << "���(1- ��������� �����, 2- ��������� ������������): ";
			cin >> newArr[i].type;
		} while (newArr[i].type != 1 && newArr[i].type != 2);
		cout << "������: ";
		cin >> newArr[i].balance;
	}
	*n = newN;
	arr = newArr;
}
//=====================================================================
void f5(vector <Production> arr, int* n)
{
	for (int i = 0; i < *n; i++)
	{
		cout << "-------------------------������������ " << "#" << i + 1 << "------------------------------" << endl << endl;
		cout << "��������: " << arr[i].firma << endl;
		cout << "��. ������: " << arr[i].adr2 << endl;
		cout << "���: " << arr[i].type << endl;
		cout << "������: " << arr[i].balance << endl;
	}
}
//=====================================================================
void save(vector <Production> arr, int* n)
{
	ofstream file_txt;
	file_txt.open("file.txt");

	for (int i = 0; i < *n; i++)
	{
		file_txt << arr[i].firma << endl;
		file_txt << arr[i].adr2 << endl;
	}
	file_txt.close();

	ofstream file_bin;
	file_bin.open("file.bin");

	file_bin << *n << endl;
	for (int i = 0; i < *n; i++)
	{
		file_bin << arr[i].type << endl;
		file_bin << arr[i].balance << endl;
	}
	file_bin.close();
}
//=====================================================================
int load(vector <Production>& arr)
{
	ifstream file_bin;
	file_bin.open("file.bin");
	if (!(file_bin.is_open()))
	{
		return 0;
	}
	else
	{
		int size = 0;
		file_bin >> size;
		arr.resize(size);

		for (int i = 0; i < size; i++)
		{
			file_bin >> arr[i].type;
			file_bin >> arr[i].balance;
		}
		file_bin.close();


		ifstream file_txt;
		file_txt.open("file.txt");

		for (int i = 0; i < size; i++)
		{
			file_txt >> arr[i].firma;
			file_txt.ignore();
			getline(file_txt, arr[i].adr2);
		}
		file_txt.close();

		return size;
	}
}
//=====================================================================
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	vector <Production> arr(n);
	n = load(arr);
	if (n != 0)
	{
		cout << "���� ������ ���������" << endl;
	}
	else
	{
		cout << "������� ���-�� �����������:" << endl;
		cin >> n;
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			cout << "-------------------------������������ " << "#" << i + 1 << "------------------------------" << endl << endl;
			cout << "��������: ";
			cin >> arr[i].firma;
			cout << "��. ������: ";
			cin.ignore();
			getline(cin, arr[i].adr2);
			do
			{
				cout << "���(1- ��������� �����, 2- ��������� ������������): ";
				cin >> arr[i].type;
			} while (arr[i].type != 1 && arr[i].type != 2);
			cout << "������: ";
			cin >> arr[i].balance;
		}
	}
C:
	int menu = 0;

	cout << "---------------------------------------------------------" << endl << endl;
	cout << "����� ���������� �� �������� �����.......................1" << endl;
	cout << "������ �� ����  (����� ����������� ��������� ����).......2" << endl;
	cout << "����������� �� ���������� ������.........................3" << endl;
	cout << "�������� ����� ������� � ����............................4" << endl;
	cout << "���������� ������ � ��������� ����.......................5" << endl;
	cout << "����� �� ���������.......................................6" << endl;

	cin >> menu;

	switch (menu)
	{
	case 1: {f1(arr, &n); break; }
	case 2: {f2(arr, &n); break; }
	case 3: {f3(arr, &n); cout << "�������������" << endl; break; }
	case 4: {f4(arr, &n); break; }
	case 5: {f5(arr, &n); break; }
	case 6: {save(arr, &n); goto F; }
	}
	goto C;
F:
	return 0;
}