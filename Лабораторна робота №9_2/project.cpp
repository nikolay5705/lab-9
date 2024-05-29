#include "project.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;


void algoritm_for_firsst_task(char* word, char*& longest_word, int& longest_word_len) {
	while (word) {
		if (strlen(word) > longest_word_len) {
			longest_word = word;
			longest_word_len = strlen(word);
		}
		word = strtok(NULL, ".,/\\\'\";:[]{}()-_*!? ");
	}
}

char* func_strpbrk(char* sentense, char* elements) {
	while (*sentense != '\0') {
		for (char* c = elements; *c != '\0'; ++c) {
			if (*sentense == *c) {
				return sentense;
			}
		}
		++sentense;
	}
}

long func_tol(const char* str, char** endptr, int base) {
	const char* s = str;
	long result = 0;
	int sign = 1;

	// Пропускаємо початкові пробіли
	while (isspace(*s)) {
		s++;
	}
	// Визначення знака числа
	if (*s == '-') {
		sign = -1;
		s++;
	}
	else if (*s == '+') {
		s++;
	}
	// Визначення основи числа
	if (base == 0) {
		if (*s == '0') {
			if (s[1] == 'x' || s[1] == 'X') {
				base = 16;
				s += 2;
			}
			else {
				base = 8;
				s++;
			}
		}
		else {
			base = 10;
		}
	}
	else if (base == 16) {
		if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
			s += 2;
		}
	}

	// Основний цикл перетворення рядка в число
	while (*s) {
		int digit = 0;

		if (isdigit(*s)) {
			digit = *s - '0';
		}
		else if (*s >= 'a' && *s <= 'z') {
			digit = *s - 'a' + 10;
		}
		else if (*s >= 'A' && *s <= 'Z') {
			digit = *s - 'A' + 10;
		}
		else {
			break;
		}

		if (digit >= base) {
			break;
		}

		// Перевірка на переповнення
		if (result > (LONG_MAX - digit) / base) {
			result = (sign == 1) ? LONG_MAX : LONG_MIN;
			if (endptr != nullptr) {
				*endptr = (char*)s;
			}
			return result;
		}

		result = result * base + digit;
		s++;
	}

	if (endptr != nullptr) {
		*endptr = (char*)s;
	}

	return result * sign;
}




void Third_task_fstream(int count_of_words, const char* input, const char* output) {
	ifstream fin(input);
	ofstream fout(output, ios::app);
	if (!fin.is_open()) {
		fout << "Файл " << input << " не було відкрито за певинх умов" << endl;
	}
	if (!fout.is_open()) {
		fout << "Файл " << output << " не було відкрито за певинх умов" << endl;
	}

	fout << endl << "Наші речення: " << endl;

	char output_word_fille_1[81];
	while (fin.getline(output_word_fille_1, 80)) {
		fout << output_word_fille_1 << endl;
	}
	
	fout.close();
	fin.close();
	fout.open(output, ios::app);
	fin.open(input);

	char* word_task_third;
	char sentense_task_third[81];
	char prototype_sentense[81];
	int count_of_sentense = 0;
	int count_task_third = 0;
	cout << endl << endl; 
	fout << endl << "Результат дії: " << endl;
	while (fin.getline(sentense_task_third, 80)) {

		strcpy(prototype_sentense, sentense_task_third);
		word_task_third = strtok(sentense_task_third, " ");
		while (word_task_third) {
			count_task_third++;

			word_task_third = strtok(NULL, ".,/\\\'\";:[]{}()-_*!? ");

		}

		if (count_task_third == count_of_words) {
			fout << prototype_sentense << endl;
			count_of_sentense++;

		}

		count_task_third = 0;
	}
	fout << "Всього " << count_of_sentense << " речень з " << count_of_words << " словами " << endl << endl;
	
	
	fout.close();
	fin.close();

}