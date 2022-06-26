#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

enum {
	close,
	decrypt,
	colors
};

void decrypting()
{
	FILE* out;

	if ((fopen_s)(&out, "лаба2.txt", "w") == NULL)
		cout << "[MESSAGE] Файл, создан";
	else
		cout << "[MESSAGE] Файл не был создан! ";

	string str;
	int choose;
	string word;
	string key = "вектор";
	int x = str.size();

	cout << "\n\n[DEC] 1. В файле " << "\n[DEC] 2. На экран";
	cout << "\n\n[DEC] Ваш выбор: ";
	cin >> choose;

	char A[33] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };

	for (int i = 0; i < word.size(); i++)
	{
		str = (A[i] - key[i]) % 33;
	}

	if (choose == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			fprintf(out, "%s", str);
		}

		cout << "[MESSAGE] Ответ готов в файле ! ";
		fclose(out);
	}

	else if (choose == 2)
	{
		cout << "[DEC] Введите шифрованное слово: ";
		cin >> word;
		cout << word;
	}
}

void color()
{
	int choose;
	int tryes;

	cout << "[DEC] Выберите цвет - \n1. Красный " << "\n2. Синий " << "\n3. Зеленый ";
	cin >> choose;

	if (choose == 1)
	{
		system("color 4");
	}

	else if (choose == 2)
	{
		system("color 3");
	}

	else if (choose == 3)
	{
		system("color 2");
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int choose;
	int tryes;

	do {
		cout << "--------------МЕНЮ--------------" << endl;
		cout << "[DEC] 0. Выход " << "\n[DEC] 1. Расшифровать текст" << "\n[DEC] 2. Цвета";
		cout << "\n[DEC] Ваш выбор: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case close:
			exit(0);
			break;

		case decrypt:
			decrypting();
			break;

		case colors:
			color();
			break;
		}

		cout << "\n[DEC] Хотите вернуться ? [1 - Да, 0 - Нет]";
		cin >> tryes;
		system("cls");

	} while (tryes != 0);
}