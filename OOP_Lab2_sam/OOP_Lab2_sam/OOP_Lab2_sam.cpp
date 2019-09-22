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
	member one;
	member two;
	member three;

	float success_one;
	float success_two;
	float success_three;

	char mas[100];
public:

	void display() {
		cout << "Название команды: " << mas << endl;
		one.display();
		two.display();
		three.display();
	}

	void real_profit() {
		float sum_one, sum_two, sum_three;
		success_one = one.profit();
		success_two = two.profit();
		success_three = three.profit();

		float sum = (success_one + success_two + success_three)/3.;
		cout << "Вероятность успеха всей команды: " << sum << endl << endl << endl;
	}

	// второй метод
	void min_profit() {
		float c1, c2, c3;
		int c_end;
		c1 = one.all_cups();
		c2 = two.all_cups();
		c3 = three.all_cups();
		if (c1 < c2) {
			if (c3 < c1) c_end = 3;
			else c_end = 1;
		}
		else {
			if (c3 > c2) c_end = 2;
			else c_end = 3;
		}

		if (c_end == 1) cout << "Наименьший объем выпитого кофе: первый" << endl << endl << endl;
		else {
			if (c_end == 2) cout << "Наименьшая объем выпитого кофе: второй" << endl << endl << endl;
			else cout << "Наименьшая объем выпитого кофе: третий" << endl << endl << endl;
		}
	}

	void profit() {
		float one_p, two_p, three_p;
		one_p = one.all_cups();
		two_p = two.all_cups();
		three_p = three.all_cups();

		cout << "Количество выпитых чашек первым участником: " << one_p << endl;
		cout << "Количество выпитых чашек вторым участником: " << two_p << endl;
		cout << "Количество выпитых чашек третьим участником: " << three_p << endl << endl << endl;
	}

	void read_team() {
		cout << "Введите название команды" << endl;
		fflush(stdin);
		fflush(stdin);
		fflush(stdin);
		cin >> mas;
	
		one.read();
		two.read();
		three.read();

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

