#include <iostream>
#include <cstring>

using namespace std;

// ������� ��� ��������� ������� ����� "OGO" ��� "AGA"
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

// ������� ��� ����� ����� "OGO" ��� "AGA" �� "**"
char* ReplaceOccurrences(char* str) {
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1]; // ��������� ���������� ����� ��� ����������
    char* t = tmp;
    tmp[0] = '\0'; // ��������� ��������

    for (int i = 0; i < len;) {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
            strcat(t, "**");
            t += 2; // ���������� �����
            i += 3;
        }
        else {
            *t++ = str[i++]; // ������� ������ � ���������� �����
        }
    }

    *t = '\0'; // ��������� �����
    return tmp; // ��������� ������� �����
}
