#include <iostream>
#include <string>

using namespace std;

// ������� ������ �������
void print_array(string str[]) {
	for (int i = 0; i < 16; i++) {
		cout << str[i];
	}
}

// ������� �������� �� 10 �.�. � 2 �.�.
void TENtoTWO(int x) {
	int ost;
	string binal[16];
	for (int i = 15; i > 0; i--) { // ������� �������� ������ ������ � ���� �� � ������
		ost = x % 2;
		x = x / 2;
		binal[i] = to_string(ost);
	}
	print_array(binal); // ����� �����
}

// ������� �������� �� 10 �.�. � 8 �.�.
void TENtoOCT(int x) {
	int ost;
	string octal[16];
	for (int i = 15; i > 0; i--) { // ������� �������� ������ ������ � ���� �� � ������
		ost = x % 8;
		x = x / 8;
		octal[i] = to_string(ost);
	}

	print_array(octal); // ����� �����
}

// ������� �������� �� 10 �.�. � 16 �.�.
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
			default: cout << "������!"; break;
			}
		}
	}
	print_array(hexal);
}

// ������� �������� �� 2 �.�. � 10 �.�.
void TWOtoTEN(int x) {
	string sBinal = to_string(x); // ����������� ����� � ������ �������� ��� ������������ ������� ����� ��������
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
	decimal > 0 ? cout << decimal : x != 0 ? cout << "������! ����� ������������ � ������ ������� ���������." : cout << decimal; // �������� �� ������� ��������� ���������� �����. ����� �����
}

// ������� �������� �� 8 �.� � 10 �.�.
void OCTtoTEN(int x) {
	string sOctal = to_string(x); // ����������� ����� � ������ �������� ��� ������������ ������� ����� ��������
	int stepen = 0, octal = 0, chislo = 0;
	for (int i = (int)sOctal.length() - 1; i >= 0; i--) {
		chislo = sOctal[i] - '0'; // ����������� ����� ��� ��������� �� ���� char � ��� int
		if (chislo < 8) {
			octal += chislo * (int)pow(8, stepen);
			stepen++;
		}
		else {
			octal = '\0'; // ��������� ������ � �����������, ����������� ������ �������� ����������
			break;
		}
	}
	octal != '\0' ? cout << octal : cout << "������! ����� ������������ � ������ ������� ���������."; // �������� �� ������� ���������
}

void HEXtoTEN(string x) {
	int stepen = 0, hexal = 0, chislo = 0;
	for (int i = (int)x.length() - 1; i >= 0; i--, stepen++) {
		chislo = x[i] - '0'; // ����������� ����� ��� ��������� �� ���� char � ��� int
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
			default: hexal = '\0'; break; // ��������� ������ � �����������, ����������� ������ �������� ����������
			}
		}
	}
	hexal != '\0' ? cout << hexal : cout << "������! ����� ������������ � ������ ������� ���������."; // �������� �� ������� ���������
}

int main()
{
	int number, iSist_s;
	string sNumber;
	setlocale(LC_CTYPE, "RUS");
	cout << "������� ��������� ����� (10, 2, 8, 16): "; cin >> iSist_s;
	switch (iSist_s) // ����� ������ ���������
	{
	case 2:
		cout << "������� �����: ";
		cin >> number;
		TWOtoTEN(number);
		break;
	case 8:
		cout << "������� �����: ";
		cin >> number;
		OCTtoTEN(number);
		break;
	case 16:
		cout << "������� �����: ";
		cin >> sNumber;
		HEXtoTEN(sNumber);
		break;
	case 10:
		cout << "������� �����: ";
		cin >> number;
		cout << "� ����� ������� ��������� ���������? (2, 8, 16) "; cin >> iSist_s;
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
			cout << "������!";
		}
		break;
	default:
		cout << "������!";
	}
	cout << endl;
	system("pause");
}