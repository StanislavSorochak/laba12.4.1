#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link;
	inform inf;
};

void Creata(Spusok*& L, Spusok*& T, inform inf);
void COUT(Spusok*& T, Spusok*& L);
void Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* L = NULL;
	Spusok* L1 = NULL;
	Spusok* L2 = NULL;
	Spusok* T, * G;

	int x = 0;
	for (int i = 0; i < 6; i++)
	{
		T = L;
		x = 6 - rand() % 12;
		Creata(L, T, x);
	}

	cout << "������ �����������:" << endl << endl;
	T = L;
	COUT(T, L);

	T = L;
	Process(L, L1, L2, T, G);
	cout << "������ � �������� ������� �����������:" << endl << endl;
	T = L1;
	COUT(T, L1);
	cout << "������ � ��'������ ������� �����������:" << endl << endl;
	T = L2;
	COUT(T, L2);

	return 0;
}

void Creata(Spusok*& L, Spusok*& T, inform inf)
{
	Spusok* tmp = new Spusok;

	if (L != NULL)
		while (T->link != L)
			T = T->link;

	tmp->inf = inf;
	if (L == NULL)
		L = tmp;
	else
		T->link = tmp;
	tmp->link = L;
}

void COUT(Spusok*& T, Spusok*& L)
{
	inform inf;

	while (T->link != L)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link;
	}
	inf = T->inf;
	cout << inf << "   ";
	cout << endl << endl;
}

void Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G)
{
	int zmina = 0;
	inform index;
	while (T->link != L)
	{
		index = T->inf;            // 1('index' ������ �������� �� ��������(�������������� ����))
		T = T->link;               // 2(������� ��������� 'T' �� �������� �������(������))
		if (index >= 0)
		{
			G = L1;                // 3(���� 'index >= 0' �� �������� 'G' ������(��������) ������ ��������� 'L1')
			Creata(L1, G, index);  // 4(���� 'index >= 0' �� ���������� ��������� ������ ������(�������) � ���������� ������� �������)
		}
		else
		{
			G = L2;                // 3(������ �������� 'G' ������(��������) ������ ��������� 'L2')
			Creata(L2, G, index);  // 4(������ ����������� ��������� ������ ������(�������) � ���������� ������� �������)
		}
	}

	if (index >= 0)           //��� �������� ���������� ������
	{
		G = L1;
		Creata(L1, G, index);
	}
	else
	{
		G = L2;
		Creata(L2, G, index);
	}
}
