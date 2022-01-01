#include <fstream>
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;


void strcat_un(char* res, const int len, int un, bool thisFem)
{
	switch (un)
	{
	case 0:
		strcat_s(res, len, "");
		break;
	case 1:
		if (thisFem) strcat_s(res, len, "одна ");
		else strcat_s(res, len, "один ");
		break;
	case 2:
		if (thisFem) strcat_s(res, len, "две ");
		else strcat_s(res, len, "два ");
		break;
	case 3:
		strcat_s(res, len, "три ");
		break;
	case 4:
		strcat_s(res, len, "четыре ");
		break;
	case 5:
		strcat_s(res, len, "пять ");
		break;
	case 6:
		strcat_s(res, len, "шесть ");
		break;
	case 7:
		strcat_s(res, len, "семь ");
		break;
	case 8:
		strcat_s(res, len, "восемь ");
		break;
	case 9:
		strcat_s(res, len, "девять ");
		break;
	}
}

void strcat_ten(char* res, const int len, int ten, int un)
{
	switch (ten)
	{
	case 0:
		strcat_s(res, len, "");
		break;
	case 1:
		switch (un)
		{
		case 0:
			strcat_s(res, len, "десять ");
			break;
		case 1:
			strcat_s(res, len, "одиннадцать ");
			break;
		case 2:
			strcat_s(res, len, "двенадцать ");
			break;
		case 3:
			strcat_s(res, len, "тринадцать ");
			break;
		case 4:
			strcat_s(res, len, "четырнадцать ");
			break;
		case 5:
			strcat_s(res, len, "пятнадцать ");
			break;
		case 6:
			strcat_s(res, len, "шеснадцать ");
			break;
		case 7:
			strcat_s(res, len, "семнадцать ");
			break;
		case 8:
			strcat_s(res, len, "восемнадцать ");
			break;
		case 9:
			strcat_s(res, len, "девятнадцать ");
			break;
		}
		break;
	case 2:
		strcat_s(res, len, "двадцать ");
		break;
	case 3:
		strcat_s(res, len, "тридцать ");
		break;
	case 4:
		strcat_s(res, len, "сорок ");
		break;
	case 5:
		strcat_s(res, len, "пятьдесят ");
		break;
	case 6:
		strcat_s(res, len, "шестьдесят ");
		break;
	case 7:
		strcat_s(res, len, "семьдесят ");
		break;
	case 8:
		strcat_s(res, len, "восемдесят ");
		break;
	case 9:
		strcat_s(res, len, "девяносто ");
		break;
	}
}

void strcat_hun(char* res, const int len, int hun)
{
	switch (hun)
	{
	case 0:
		strcat_s(res, len, "");
		break;
	case 1:
		strcat_s(res, len, "сто ");
		break;
	case 2:
		strcat_s(res, len, "двести ");
		break;
	case 3:
		strcat_s(res, len, "триста ");
		break;
	case 4:
		strcat_s(res, len, "четыреста ");
		break;
	case 5:
		strcat_s(res, len, "пятьсот ");
		break;
	case 6:
		strcat_s(res, len, "шестьсот ");
		break;
	case 7:
		strcat_s(res, len, "семьсот ");
		break;
	case 8:
		strcat_s(res, len, "восемьсот ");
		break;
	case 9:
		strcat_s(res, len, "девятьсот ");
		break;
	}
}

void strcat_or(char* res, const int len, int un, int ten, int hun, char* s1, char* s2, char* s3)
{
	if (un == 0) strcat_s(res, len, "");
	if (un >= 5 && un <= 9 || ten == 1 || un == 0 && (ten != 0 || hun != 0)) strcat_s(res, len, s3);
	else if (un == 1) strcat_s(res, len, s1);
	else if (un >= 2 && un <= 4) strcat_s(res, len, s2);
}


void strcat_nt(char* res, const int len, int un, int ten, int hun, char* s1, char* s2, char* s3, bool thisFem)
{
	cout << "hun = " << hun << ", ten = " << ten << ", un = " << un << "; ";
	strcat_hun(res, len, hun);
	strcat_ten(res, len, ten, un);
	if (ten != 1) strcat_un(res, len, un, thisFem);
	strcat_or(res, len, un, ten, hun, s1, s2, s3);
}


char* transformNumInText(char* num)
{	
	const int len = 200, col = 12;
	int k = 0, g, n = col, ln = strcspn(num, "\n"), dop = 0;
	int* nums = new int[col];
	char* res = new char[len];
	char** ord = new char* [col];
	strcpy_s(res, len, "");
	
	if (num[0] == '0')
	{
		strcpy_s(res, len, "ноль");
		return res;
	}
	else if (num[0] == '-')
	{
		strcpy_s(res, len, "минус ");
		dop++;
	}

	for (int i = 0; i < n + dop; i++)
	{
		if (i + dop < ln) nums[i] = num[ln - 1 - i] - '0';
		else if (i < n) nums[i] = 0;
	}

	for (int i = col - 1; i >= 0; i--) ord[i] = new char[20];

	k = 0;

	strcpy_s(ord[k++], 20, "");
	strcpy_s(ord[k++], 20, "");
	strcpy_s(ord[k++], 20, "");
	strcpy_s(ord[k++], 20, "тысяча ");
	strcpy_s(ord[k++], 20, "тысячи ");
	strcpy_s(ord[k++], 20, "тысяч ");
	strcpy_s(ord[k++], 20, "миллион ");
	strcpy_s(ord[k++], 20, "миллиона ");
	strcpy_s(ord[k++], 20, "миллионов ");
	strcpy_s(ord[k++], 20, "миллиард ");
	strcpy_s(ord[k++], 20, "миллиарда ");
	strcpy_s(ord[k++], 20, "миллиардов ");

	//g = --k;

	//strcat_nt(res, len, nums[g--], nums[g--], nums[g--], ord[k--], ord[k--], ord[k--], false);
	//strcat_nt(res, len, nums[g--], nums[g--], nums[g--], ord[k--], ord[k--], ord[k--], false);
	//strcat_nt(res, len, nums[g--], nums[g--], nums[g--], ord[k--], ord[k--], ord[k--], true);
	//strcat_nt(res, len, nums[g--], nums[g--], nums[g--], ord[k--], ord[k--], ord[k--], false);

	g = k;
	strcat_nt(res, len, nums[--g], nums[--g], nums[--g], ord[--k], ord[--k], ord[--k], false);
	strcat_nt(res, len, nums[--g], nums[--g], nums[--g], ord[--k], ord[--k], ord[--k], true);
	strcat_nt(res, len, nums[--g], nums[--g], nums[--g], ord[--k], ord[--k], ord[--k], false);

	
	//delete[] nums;
	//delete[] res;
	//for (int i = 0; i < col; i++) delete[] ord[i];
	//delete[] ord;
	return res;
}


void firstProgramm()
{
	ifstream inputData;
	inputData.open("inputData.txt");
	char *num = new char;

	if (!inputData.good())
	{
		std::cerr << "Error opening file!" << std::endl;
	}
	else
	{
		while (!inputData.eof())
		{
			inputData >> num;
			cout << num << " - " << transformNumInText(num) << endl;
		}
	}

	inputData.close();
}

void secondProgramm()
{
	char* num = new char[50]; 
	cout << "Введите число: ";
	cin >> num;
	cout << num << " - " << transformNumInText(num) << endl;
}

void menu()
{
	int check;
	while (true)
	{
		cout << "Выполнить преоброзование? (из файла: 1, ввесть самому: 2, нет: 0): ";
		cin >> check;

		if (check == 1) firstProgramm();
		else if (check == 2) secondProgramm();
		else if (check == 0) break;
		else cout << "Введено некоректное значение, попробуйте снова." << endl;
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
}