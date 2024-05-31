#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstring>  
#include "project.h"


using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t\tЛабораторна робота №9\n\n";

	
	cout << "\n\t\tЗавдання №1\n\n";

	char phrase[101];
	cout << "Введіть речення(але максимальна кількість символів буде 100): ";
	cin.getline(phrase, 100);
	char* word;
	char* longest_word = nullptr;
	int longest_word_len = 0;
	char delim[] = ".,/\\\'\";:[]{}()-_*!? ";
	word = my_strtok(phrase, " ");

	algoritm_for_first_task(word, longest_word, longest_word_len, delim);

	if (longest_word_len) {
		cout << "Розмір найдовшого слова: " << longest_word_len << endl;
		cout << "Саме слово: ";
		for (int i = longest_word_len;i >= 0; i--) {
			cout << longest_word[i];
		}
		cout << endl;
	}
	else {
		cout << "Ви не ввели жодного слова" << endl;
	}

	
	
	cout << "\n\n\t\tЗавдання №2\n\n";

	int choose_an_option_for_task_2;
	char sentense[100], elements[10];
	
	while (true) {
		cout << endl << "Введіть число для вибору функції\n";
		cout << "Де 0 - ви нічого не обираєте, та йдете на слідуюче завдання\n";
		cout << "1 - обираєте функцію strpbrk, 2 - обираєте функцію strtol\n";
		cout << "Введіть цифру: ";
		cin >> choose_an_option_for_task_2;
		while (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ви ввели не число" << endl;
			cout << "Введіть цифру: ";
			cin >> choose_an_option_for_task_2;
		}
		if (choose_an_option_for_task_2 == 1) {
			cin.ignore(32767, '\n');

			cout << "Введіть речення, але максимальна довжина його 100 символів: ";
			cin.getline(sentense, sizeof(sentense));
			cout << "Введіть символи для пошуку, але максимальна кількість 10: ";
			cin.getline(elements, sizeof(elements));

			char* ptr_1 = func_strpbrk(sentense, elements);
			cout << "Робота прописаної функції" << endl;
			if (ptr_1 != nullptr) {
				cout << "Перше вхождення: " << *ptr_1 << endl;
			}
			else {
				cout << "Жодних відповідностей не знайдено." << endl;
			}
			cout << "Робота стандартної функції" << endl;
			char* ptr_2 = strpbrk(sentense, elements);

			if (ptr_2 != nullptr) {
				cout << "Перше вхождення: " << *ptr_2 << endl;
			}
			else {
				cout << "Жодних відповідностей не знайдено." << endl;
			}

		}
		else if (choose_an_option_for_task_2 == 2) {
			char number_sentense[101];
			int type_num;
			cin.ignore(32767, '\n');
			cout << "Введіть якесь число: ";
			cin.getline(number_sentense, 100);
			cout << "Введіть в якій із систем числення буде повертати \nУ разі некоректного введення то поверне у 10 річній системі" << endl;
			cout << "Введіть систему числення: ";
			cin >> type_num;
			char* end;
			long value = func_tol(number_sentense, &end, type_num);
			cout << "Результат роботи прописаної функції: " << value << endl;
			long int number_2 = strtol(number_sentense, &end, type_num);
			cout << "Результат роботи стандартної функції: "<< number_2 <<endl;
		}
		else {
			break;
		}
	}

	
	
	cout << "\t\tЗавдання №3\n\n";
	char input[20];
	char end_of_input[5] = ".txt";
	cout << "Введіть ім'я вхідного файлу (тип .txt автоматично буде обраний): ";
	cin.getline(input, 15);
	
	while (strlen(input) > 15) {
		cout << "Ви ввели ім'я більше за 15 символів\n";
		cout << "Введіть інм'я файлу(тип .txt автоматично буде обраний): ";
		cin.getline(input, 10);
	}
	char prototype_input[15];
	strcpy(prototype_input, input);
	strcat(input, end_of_input);

	char output[13];
	char end_of_fille_name[9] = "_out.dat";
	
	prototype_input[3] = '\0';

    if (prototype_input[2] == '.') {
		prototype_input[2] = '\0';
		strcpy(output, prototype_input);
		strcat(output, end_of_fille_name);
	}
	else if (prototype_input[1] == '.') {
		prototype_input[1] = '\0';
		strcpy(output, prototype_input);
		strcat(output, end_of_fille_name);
	}
	
	else{
		strcpy(output, prototype_input);
		strcat(output, end_of_fille_name);
	}
	
	

	char temp_for_empty_file[81];
	int count_of_words;
	int counter_for_empty_file = 0;
	bool flag = true;
	cout << "Введіть кількість слів у реченні: ";
	cin >> count_of_words;
	while (!cin) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Ви ввели не число" << endl;
		cout << "Введіть кількість слів у реченні: ";
		cin >> count_of_words;
	}
	ifstream fin(input);
	ofstream fout(output);
	if (!fin.is_open()) {
		cout << "Файл " << input << " не було відкрито за певинх умов" << endl;
	}
	else {
		cout << "Файл " << input << " було успішно відкрито" << endl;
	}
	if (!fout.is_open()) {
		cout << "Файл " << output << " не було відкрито за певинх умов" << endl;
	}
	else {
		cout << "Файл " << output << " було успішно відкрито" << endl;
	}
	if (fin.is_open()) {
		while (fin.getline(temp_for_empty_file,80)) {
			++counter_for_empty_file;
		}
	}
	if (counter_for_empty_file == 0) {
		cout << endl << "Ваш файл пустий тому програма не може обробляти ваші дані з файлу" << endl;
		cout << "Будь ласка введіть дані у файл" << endl;
		flag = false;
	}
	fin.close();

	if (counter_for_empty_file != 0) {
		if (flag) {
			int index_for_third_task;


			Third_task_fstream(count_of_words, input, output);

			cout << "Дані були успішно записанні у вихідний файл" << endl;
			cout << "1 - Програма виведе на екран дані з вхідного файлу" << endl;
			cout << "2 - Програма виведе на екран дані з вихідного файлу" << endl;
			cout << "будь-яке інше число, вихід з програми" << endl;
			cout << "Введіть число: ";
			cin >> index_for_third_task;
			while (true) {
				if (index_for_third_task == 1) {
					fin.open(input);
					cout << endl << "Дані з вхідного файлу: " << endl;
					char output_word_fille_1[81];
					while (fin.getline(output_word_fille_1, 80)) {
						cout << output_word_fille_1 << endl;
					}
					fin.close();
					cout << "1 - Програма виведе на екран дані з вхідного файлу" << endl;
					cout << "2 - Програма виведе на екран дані з вихідного файлу" << endl;
					cout << "будь-яке інше число, вихід з програми" << endl;
					cout << "Введіть число: ";
					cin >> index_for_third_task;


				}
				else if (index_for_third_task == 2) {
					fin.open(output);
					cout << endl << "Дані з вихідного файлу: " << endl;
					char output_word_fille_2[81];
					while (fin.getline(output_word_fille_2, 80)) {
						cout << output_word_fille_2 << endl;
					}
					fin.close();
					cout << "1 - Програма виведе на екран дані з вхідного файлу" << endl;
					cout << "2 - Програма виведе на екран дані з вихідного файлу" << endl;
					cout << "будь-яке інше число, вихід з програми" << endl;
					cout << "Введіть число: ";
					cin >> index_for_third_task;


				}
				else {
					break;
				}
			}

		}
	}
	fin.close();
	fout.close();
	
	system("pause");
	return 0;
}

