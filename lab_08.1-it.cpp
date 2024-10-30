#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int CountOccurrences(char* str) 
{
    int count = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len - 2; i++) 
    {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') || (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) 
        {
            count++;
        }
    }
    return count;
}


char* ReplaceOccurrences(char* str) 
{
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1]; 
    char* t = tmp;
    tmp[0] = '\0'; 

    for (int i = 0; i < len;) 
    {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') || (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) 
        {
            strcat(t, "**");
            t += 2;
            i += 3; 
        } 
        else 
        {
            *t++ = str[i++]; 
            *t = '\0';
        }
    }

    strcpy(str, tmp); 
    return tmp; 
}

int main() 
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains " << CountOccurrences(str) << " occurrences of 'OGO' or 'AGA'" << endl;

    char* modifiedStr = ReplaceOccurrences(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; 
    return 0;
}
