#include <iostream>
#include <string>

using namespace std;

// Функция вывода массива
void print_array(string str[]) {
	for (int i = 0; i < 16; i++) {
		cout << str[i];
	}
}

// Функция перевода из 10 с.с. в 2 с.с.
void TENtoTWO(int x) {
	int ost;
	string binal[16];
	for (int i = 15; i > 0; i--) { // Перебор значений справа налево и ввод их в массив
		ost = x % 2;
		x = x / 2;
		binal[i] = to_string(ost);
	}
	print_array(binal); // Вывод числа
}

// Функция перевода из 10 с.с. в 8 с.с.
void TENtoOCT(int x) {
	int ost;
	string octal[16];
	for (int i = 15; i > 0; i--) { // Перебор значений справа налево и ввод их в массив
		ost = x % 8;
		x = x / 8;
		octal[i] = to_string(ost);
	}

	print_array(octal); // Вывод числа
}

// Функция перевода из 10 с.с. в 16 с.с.
void TENtoHEX(int x) {
	int ost;
	string hexal[16];
	for (int i = 15; i > 0; i--) {
		ost = x % 16;
		x = x / 16;
		if (ost < 10) {
			hexal[i] = to_string(ost);
		}
		else {
			switch (ost) {
			case 10: hexal[i] = 'A'; break;
			case 11: hexal[i] = 'B'; break;
			case 12: hexal[i] = 'C'; break;
			case 13: hexal[i] = 'D'; break;
			case 14: hexal[i] = 'E'; break;
			case 15: hexal[i] = 'F'; break;
			default: cout << "Ошибка!"; break;
			}
		}
	}
	print_array(hexal);
}

// Функция перевода из 2 с.с. в 10 с.с.
void TWOtoTEN(int x) {
	string sBinal = to_string(x); // Конвертация числа в массив символов для рассмотрения каждого числа отдельно
	int stepen = 0, decimal = 0;
	for (int i = (int)sBinal.length() - 1; i >= 0; i--) {
		if (sBinal[i] == '1') {
			decimal += (int)pow(2, stepen);
		}
		else if (sBinal[i] != '1' && sBinal[i] != '0') {
			decimal = 0; break;
		}
		stepen++;
	}
	decimal > 0 ? cout << decimal : x != 0 ? cout << "Ошибка! Число представлено в другой системе счисления." : cout << decimal; // Проверка на систему счисления введенного числа. Вывод числа
}

// Функция перевода из 8 с.с в 10 с.с.
void OCTtoTEN(int x) {
	string sOctal = to_string(x); // Конвертация числа в массив символов для рассмотрения каждого числа отдельно
	int stepen = 0, octal = 0, chislo = 0;
	for (int i = (int)sOctal.length() - 1; i >= 0; i--) {
		chislo = sOctal[i] - '0'; // Конвертация цифры для умножения из типа char в тип int
		if (chislo < 8) {
			octal += chislo * (int)pow(8, stepen);
			stepen++;
		}
		else {
			octal = '\0'; // Произошла ошибка в вычислениях, присваиваем пустое значение переменной
			break;
		}
	}
	octal != '\0' ? cout << octal : cout << "Ошибка! Число представлено в другой системе счисления."; // Проверка на систему счисления
}

void HEXtoTEN(string x) {
	int stepen = 0, hexal = 0, chislo = 0;
	for (int i = (int)x.length() - 1; i >= 0; i--, stepen++) {
		chislo = x[i] - '0'; // Конвертация цифры для умножения из типа char в тип int
		if (chislo < 10) {
			hexal += chislo * (int)pow(16, stepen);
		}
		else {
			switch (x[i]) {
			case 'A': chislo = 10; hexal += chislo * (int)pow(16, stepen); break;
			case 'B': chislo = 11; hexal += chislo * (int)pow(16, stepen); break;
			case 'C': chislo = 12; hexal += chislo * (int)pow(16, stepen); break;
			case 'D': chislo = 13; hexal += chislo * (int)pow(16, stepen); break;
			case 'E': chislo = 14; hexal += chislo * (int)pow(16, stepen); break;
			case 'F': chislo = 15; hexal += chislo * (int)pow(16, stepen); break;
			default: hexal = '\0'; break; // Произошла ошибка в вычислениях, присваиваем пустое значение переменной
			}
		}
	}
	hexal != '\0' ? cout << hexal : cout << "Ошибка! Число представлено в другой системе счисления."; // Проверка на систему счисления
}

int main()
{
	int number, iSist_s;
	string sNumber;
	setlocale(LC_CTYPE, "RUS");
	cout << "Система счисления числа (10, 2, 8, 16): "; cin >> iSist_s;
	switch (iSist_s) // Выбор режима программы
	{
	case 2:
		cout << "Введите число: ";
		cin >> number;
		TWOtoTEN(number);
		break;
	case 8:
		cout << "Введите число: ";
		cin >> number;
		OCTtoTEN(number);
		break;
	case 16:
		cout << "Введите число: ";
		cin >> sNumber;
		HEXtoTEN(sNumber);
		break;
	case 10:
		cout << "Введите число: ";
		cin >> number;
		cout << "В какую систему счисления перевести? (2, 8, 16) "; cin >> iSist_s;
		switch (iSist_s) {
		case 2:
			TENtoTWO(number);
			break;
		case 8:
			TENtoOCT(number);
			break;
		case 16:
			TENtoHEX(number);
			break;
		default:
			cout << "Ошибка!";
		}
		break;
	default:
		cout << "Ошибка!";
	}
	cout << endl;
	system("pause");
}