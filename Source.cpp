#include <iostream>
#include <conio.h>
#include "ClassMatrix.h"

using namespace std;

void AddMatrix();

int n, m, cols, rows;

int main()
{
	setlocale(LC_ALL, "RUS");
	

	//��������� ����������� �������
	cout << "\n\t ������� ���������� ����� �������: ";
	cin >> n;
	cout << "\n\t ������� ���������� �������� �������: ";
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

	//��������� ������ ��� �������
	Matrix *Mymatrix = new Matrix(n, m);

	while (b != 'n')
	{
		system("cls");

		//�������� ���� ���������
		cout << "\n\t\t ****** �������� �������� ******\n\n";
		cout << "\t 0 - ������� �������\n";
		cout << "\t 1 - ������� �������\n";
		cout << "\t 2 - ������ �������� �������\n";
		cout << "\t 3 - ������ ������� �������\n";
		cout << "\t 4 - ������� �������� �������\n";
		cout << "\t 5 - ����������� ��� �������\n";
		cout << "\t 6 - ����������� ����� �������\n";
		cout << "\t 7 - ����������� ������� �������\n";
		cout << "\t 8 - ����������� ���������� ����� �������\n";
		cout << "\t 9 - ����������� ���������� �������� �������\n";
		cout << "\t a - �������� ���������� ����� �������\n";
		cout << "\t b - �������� ���������� �������� �������\n";
		cout << "\n\t ";
		cin >> a;
		system("cls");

		switch (a)
		{

		//�������� �������
		case '0':
		{
			system("cls");
			cout << "\n\t ������� ���������� ����� �������: ";
			cin >> n;
			cout << "\n\t ������� ���������� �������� �������: ";
			cin >> m;
			system("cls");
			
			//��������� ������ ��� �������
			Matrix *Mymatrix = new Matrix(n, m);
			break;
		}
		
		//�������� ���������� ������
		case '1':
		{
			delete Mymatrix;
			break;
		}

		//���������� ��������� �������
		case '2':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << "\n\t ������� ������� " << i + 1 << " ������ "
						<< j + 1 << " ������� ";
					cin >> elem;
					Mymatrix->SetXY(i, j, elem);
				}
			}
			break;
		}

		//��������� ������ �������� �������
		case '3':
		{
			cout << "\n\t ������� ����� ������ �� ������ ��������? ";
			cin >> x_on;
			cout << "\n\t ������� ������ ������� �� ������ ��������? ";
			cin >> y_on;
			cout << "\n\t ������� ������� " << x_on << " ������ "
				<< y_on << " ������� ";
			cin >> elem;
			Mymatrix->SetXY(x_on - 1, y_on - 1, elem);
			break;
		}

		//�������� ��������� �������
		case '4':
		{
			Mymatrix->~Matrix();
			break;
		}

		//�������� ���� �������
		case '5':
		{

			Mymatrix->Show();
			break;
		}

		//�������� ����� �������
		case '6':
		{
			cout << "\n\t � ����� ������ ������ ����������� ������� ";
			cin >> x_on;
			cout << "\n\t �� ����� ������ ���������� ������� ";
			cin >> x_off;
			
			cout << "\n\t � ������ ������� ������ ����������� ������� ";
			cin >> y_on;
			cout << "\n\t �� ������ ������� ���������� ������� ";
			cin >> y_off;
			
			Mymatrix->Show(x_on - 1, x_off - 1, y_on - 1, y_off - 1);
			break;
		}

		//�������� �������� �������
		case '7':
		{
			cout << "\n\t ����� ������� ������� �� ������ ����������? "
				<< "\n\n\t ������� ����� ������ ";
			cin >> x_on;
			
			cout << "\n\t ������� ����� ������� ";
			cin >> y_on;

			cout << "\n\t " << Mymatrix->GetXY(x_on - 1, y_on - 1) << endl;
			break;
		}

		//�������� ���������� ����� � �������
		case '8':
		{
			cout << "\n\t � ������� " << Mymatrix->GetCols() << " ����� \n";
			break;
		}
		
		//�������� ���������� �������� � �������
		case '9':
		{
			cout << "\n\t � ������� " << Mymatrix->GetRows() << " �������� \n";
			break;
		}

		case 'a':
		{
			cout << "\n\t ������� ����� ���������� � �������? ";
			cin >> n;

			Mymatrix->SetCols(n);
			break;
		}

		case 'b':
		{
			cout << "\n\t ������� �������� ���������� � �������? ";
			cin >> m;

			Mymatrix->SetRows(m);
			break;
		}
		default: cout << "\n\t ****** �� �� ������� ��������! ******\n";
		}

		//���������� ������?
		cout << "\n\t ������ ���������� ������? (y/n) ";
		cin >> b;
	}

	system("cls");
}