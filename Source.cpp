#include <iostream>
#include <conio.h>
#include "ClassMatrix.h"

using namespace std;

void AddMatrix();

int n, m, cols, rows;

int main()
{
	setlocale(LC_ALL, "RUS");
	

	//Первичное определение матрицы
	cout << "\n\t Введите количество строк матрицы: ";
	cin >> n;
	cout << "\n\t Введите количество столбцов матрицы: ";
	cin >> m;
	system("cls");

	AddMatrix();
	system("pause");
	return 0;
}

void AddMatrix()
{
	char a, b = NULL;
	int elem, x_on, y_on, x_off, y_off;

	//Выделение памяти под матрицу
	Matrix *Mymatrix = new Matrix(n, m);

	while (b != 'n')
	{
		system("cls");

		//Создание меню программы
		cout << "\n\t\t ****** Выберите операцию ******\n\n";
		cout << "\t 0 - Создать матрицу\n";
		cout << "\t 1 - Удалить матрицу\n";
		cout << "\t 2 - Задать элементы матрицы\n";
		cout << "\t 3 - Задать элемент матрицы\n";
		cout << "\t 4 - Удалить элементы матрицы\n";
		cout << "\t 5 - Просмотреть всю матрицу\n";
		cout << "\t 6 - Просмотреть часть матрицы\n";
		cout << "\t 7 - Просмотреть элемент матрицы\n";
		cout << "\t 8 - Просмотреть количество строк матрицы\n";
		cout << "\t 9 - Просмотреть количество столбцов матрицы\n";
		cout << "\t a - Изменить количество строк матрицы\n";
		cout << "\t b - Изменить количество столбцов матрицы\n";
		cout << "\n\t ";
		cin >> a;
		system("cls");

		switch (a)
		{

		//Создание матрицы
		case '0':
		{
			system("cls");
			cout << "\n\t Введите количество строк матрицы: ";
			cin >> n;
			cout << "\n\t Введите количество столбцов матрицы: ";
			cin >> m;
			system("cls");
			
			//Выделение памяти под матрицу
			Matrix *Mymatrix = new Matrix(n, m);
			break;
		}
		
		//Удаление созданного класса
		case '1':
		{
			delete Mymatrix;
			break;
		}

		//Заполнение элементов матрицы
		case '2':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << "\n\t Введите элемент " << i + 1 << " строки "
						<< j + 1 << " столбца ";
					cin >> elem;
					Mymatrix->SetXY(i, j, elem);
				}
			}
			break;
		}

		//Установка одного элемента матрицы
		case '3':
		{
			cout << "\n\t Элемент какой строки вы хотите изменить? ";
			cin >> x_on;
			cout << "\n\t Элемент какого столбца вы хотите изменить? ";
			cin >> y_on;
			cout << "\n\t Введите элемент " << x_on << " строки "
				<< y_on << " столбца ";
			cin >> elem;
			Mymatrix->SetXY(x_on - 1, y_on - 1, elem);
			break;
		}

		//Удаление элементов матрицы
		case '4':
		{
			Mymatrix->~Matrix();
			break;
		}

		//Просмотр всей матрицы
		case '5':
		{

			Mymatrix->Show();
			break;
		}

		//Просмотр части матрицы
		case '6':
		{
			cout << "\n\t С какой строки начать отображение матрицы ";
			cin >> x_on;
			cout << "\n\t До какой строки отображать матрицу ";
			cin >> x_off;
			
			cout << "\n\t С какого столбца начать отображение матрицы ";
			cin >> y_on;
			cout << "\n\t До какого столбца отображать матрицу ";
			cin >> y_off;
			
			Mymatrix->Show(x_on - 1, x_off - 1, y_on - 1, y_off - 1);
			break;
		}

		//Просмотр элемента матрицы
		case '7':
		{
			cout << "\n\t Какой элемент матрицы вы хотите посмотреть? "
				<< "\n\n\t Укажите номер строки ";
			cin >> x_on;
			
			cout << "\n\t Укажите номер столбца ";
			cin >> y_on;

			cout << "\n\t " << Mymatrix->GetXY(x_on - 1, y_on - 1) << endl;
			break;
		}

		//Просмотр количества строк в матрице
		case '8':
		{
			cout << "\n\t В матрице " << Mymatrix->GetCols() << " строк \n";
			break;
		}
		
		//Просмотр количества столбцов в матрице
		case '9':
		{
			cout << "\n\t В матрице " << Mymatrix->GetRows() << " столбцов \n";
			break;
		}

		case 'a':
		{
			cout << "\n\t Сколько строк установить в матрице? ";
			cin >> n;

			Mymatrix->SetCols(n);
			break;
		}

		case 'b':
		{
			cout << "\n\t Сколько столбцов установить в матрице? ";
			cin >> m;

			Mymatrix->SetRows(m);
			break;
		}
		default: cout << "\n\t ****** Вы не выбрали операцию! ******\n";
		}

		//Продолжить работу?
		cout << "\n\t Хотите продолжить работу? (y/n) ";
		cin >> b;
	}

	system("cls");
}