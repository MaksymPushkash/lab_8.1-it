#include <iostream>
#include <cstring>

using namespace std;

// Функція для підрахунку кількості трійок "OGO" або "AGA"
int CountOccurrences(char* str) {
    int count = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len - 2; i++) {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
            count++;
        }
    }
    return count;
}

// Функція для заміни трійок "OGO" або "AGA" на "**"
char* ReplaceOccurrences(char* str) {
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1]; // Створюємо тимчасовий рядок для результату
    char* t = tmp;
    tmp[0] = '\0'; // Початкове значення

    for (int i = 0; i < len;) {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
            strcat(t, "**");
            t += 2; // Пропускаємо трійку
            i += 3;
        }
        else {
            *t++ = str[i++]; // Копіюємо символ у тимчасовий рядок
        }
    }

    *t = '\0'; // Завершуємо рядок
    return tmp; // Повертаємо змінений рядок
}
