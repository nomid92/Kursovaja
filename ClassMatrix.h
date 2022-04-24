#pragma once

using namespace std;

class Matrix
{
private:
	int **a;
	int rows, cols;

public:

	Matrix(int Clos, int Rows); 
	~Matrix();

	//Заполнение ячейки x, y
	void SetXY(int Y, int X, int data);	
	//Возвращение номера строки и столбца в котором находится элемент
	int GetXY(int X, int Y);	
	void Show();

	//Вывод матрицы от Rows_beg строки Cols_beg столбца до Rows_beg строки Cols_beg столбца
	void Show(int Cols_beg, int Rows_beg, int Cols_end, int Rows_end);
	
	//Установка количества строк и столбцов
	void SetCols(int Cols);
	void SetRows(int Rows);

	//Возвращение количества строк и столбцов
	int GetCols() { return cols;}
	int GetRows() { return rows;}
};

Matrix::Matrix(int Cols, int Rows)
{
	//Выделение памяти под матрицу
	a = new int *[Cols];
	for (int i = 0; i < Cols; i++)
	{
		a[i] = new int[Rows];
		for (int j = 0; j < Rows; j++)
			a[i][j] = 0;
	}

	cols = Cols;
	rows = Rows;
}

Matrix::~Matrix()
{
	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
		{
			a[i][j] = 0;
		}
}

void Matrix::SetXY(int Y, int X, int data)
{
	if (Y < cols && Y >= 0 && X < rows && X >= 0)
		a[Y][X] = data;
}

int Matrix::GetXY(int X, int Y)
{
	if (Y < rows && X < cols && Y >= 0 && X >= 0)
		return a[X][Y];
	else
		return 1;
}

void Matrix::Show()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
}

void Matrix::Show(int Cols_beg, int Cols_end, int Rows_beg, int Rows_end)
{
	if (Cols_end < cols && Rows_end < rows && Cols_beg >= 0 && Rows_beg >= 0)
	{
		for (int i = Cols_beg; i <= Cols_end; i++)
		{
			for (int j = Rows_beg; j <= Rows_end; j++)
			{
				cout << a[i][j] << "  ";
			}
			cout << endl;
		}
	}
}

void Matrix::SetCols(int Cols)
{
	int **b;
	b = new int *[Cols];
	for (int i = 0; i < Cols; i++)
	{
		b[i] = new int[rows];
		for (int j = 0; j < rows; j++)
			b[i][j] = 0;
	}
	for (int i = 0; i < Cols && i < cols; i++)
		for (int j = 0; j < rows; j++)
			b[i][j] = a[i][j];
	for (int i = 0; i < cols; i++)
		delete[] a[i];
	delete[] a;
	cols = Cols;
	a = b;
}

void Matrix::SetRows(int Rows)
{
	int **b;
	b = new int *[cols];
	for (int i = 0; i < cols; i++)
	{
		b[i] = new int[Rows];
		for (int j = 0; j < Rows; j++)
			b[i][j] = 0;
	}

	for (int i = 0; i < cols ; i++)
		for (int j = 0; j < rows && j < Rows; j++)
			b[i][j] = a[i][j];
	for (int i = 0; i < cols; i++)
		delete[] a[i];
	delete[] a;
	rows = Rows;
	a = b;
}