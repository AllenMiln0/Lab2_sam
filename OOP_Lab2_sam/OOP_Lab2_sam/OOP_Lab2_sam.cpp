/* Вагон, содержит поле - количество мест (целое число) и цена билета по данному маршруту (вещественная).
Реализовать метод, вычисляющий общую ожидаемую сумму от продаж билетов в вагоне.
Основным классом является поезд, содержащий три поля типа вагонов и процент заполнения каждого вагона(три целых поля).
Реализовать метод, вычисляющий реальный доход от данного маршрута и вагон с наименьшей ожидаемой суммой продаж. */

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>


using namespace std;

class member {
private:
	int speed;
	int win_tour;
	int cups;
public:
	float profit() {
		float pro;
		pro = win_tour / 20.;
		return (pro);
	}

	int all_cups() {
		int all = cups * win_tour;
		return (all);
	}

	void init() {
		speed = 30;
		win_tour = 3;
		cups = 2;
	}

	void display() {
		cout << "Скорость набора кода: " << speed << endl;
		cout << "Количество побед в 20 турнирах: " << win_tour << endl;
		cout << "Количество чашек кофе за один турнир: " << cups << endl;
	}

	void read() {
		cout << "Введите скорость набора кода: " << endl;
		cin >> speed;
		cout << "Количество побед в 20 турнирах: " << endl;
		cin >> win_tour;
		cout << "Количество выпитых чашек за один турнир: " << endl;
		cin >> cups;
	}
};

class team {
private:
	member *one;
	float success[3];
	char mas[100];
public:
	team() {
		one = new member[3];
	}

	~team(){
		delete[] one;
	}


	void display() {
		cout << "Название команды: " << mas << endl;
		for (int i = 0; i < 3; i++) {
			one[i].display();
		}
	}

	void real_profit() {
		float sum = 0;
		for (int i = 0; i < 3; i++) {
			success[i] = one[i].profit();
			sum += success[i];
			sum /= 3.;
		}
		cout << "Вероятность успеха всей команды: " << sum << endl << endl << endl;
	}

	// второй метод
	void min_profit() {
		float c1[3];
		int c_end;

		for (int i = 0; i < 3; i++) {
			c1[i] = one[i].all_cups();
		}
		c_end = c1[0];
		for (int i = 0; i < 3; i++)
			if (c_end < c1[i]) c_end = c1[i];

		int t;
		for (int i = 0; i < 3; i++)
			if (c_end == c1[i]) t = i;

		cout << "Наименьший объем выпитого кофе: "<< (t+1) << endl << endl << endl;
	}

	void profit() {
		float one_p[3];
		for (int i = 0; i < 3; i++) {
			one_p[i] = one[i].all_cups();

			cout << "Количество выпитых чашек " << i+1 << " участником: " << one_p[i] << endl;
		}
	}

	void read_team() {
		cout << "Введите название команды" << endl;
		fflush(stdin);
		cin >> mas;
	
		for (int i = 0; i < 3; i++)
			one[i].read();

	}
};

void menu() {
	cout << "***************** Меню ***************" << endl;
	cout << "* 1. Ввод скорости печати, кол-ва выйгранных турниров и \n*\tкол-во чашек кофе на один турнир *" << endl;
	cout << "* 2. Вывести на экран данные о трех участниках *" << endl;
	cout << "* 3. Рассчитать количество выпитого кофе каждым участником*" << endl;
	cout << "* 4. Рассчитать вероятность победы команды *" << endl;
	cout << "* 5. Определить наименьший по объемам выпитого кофе участника *" << endl;
	cout << "* 6. Выход *" << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	do {
		menu();
		team computer;
		cin >> choice;
		switch (choice) {
		case 1:	computer.read_team();
			break;
		case 2: computer.display();
			break;
		case 3: computer.profit();
			break;
		case 4:	computer.real_profit();
			break;
		case 5:	computer.min_profit();
			break;
		case 6: return 3;
			break;
		default: cout << "Такого пункта меню нет. " << endl;
			break;
		}
	} while (choice != 6);
}

