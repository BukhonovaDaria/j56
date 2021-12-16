#include <iostream>
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#include <fstream>

using namespace std;

void encode(char A[], char B[], char C[], int count)
{
    int k = 0;
    char symbol;
    for (int j = 0; j < count; j++) {
        for (int i = 0; i < 54; i++) {
            if (A[j] == B[i]) {
                symbol = C[i];
            }
        }
        A[j] = symbol;
    }
    for (int i = 0; i < count; i++) {
        cout << A[i];
    }
}
void decode(char A[], char B[], char C[], int count) {
    int k = 0;
    for (int j = 0; j < count; j++) {
        for (int i = 0; i < 54; i++) {
            if (A[j] == C[i]) {
                A[j] = B[i];
                i = 54;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        cout << A[i];
    }
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int c = 0;
    while (c == 0) {
        cout << " Выберите действие:\n 1-File\n 2-Test\n 3-Exit\n Ваш выбор : ";
        cin >> c;
        if (c == 1) {
            ifstream file("Текст.txt");
            int count = 0;
            char B[54] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            char C[54] = "ZYXWVUTSRQPONMLKJHGFEDCBAzyxwvutsrqponmlkjihgfedcba";
            char A[100]{};
            if (file.is_open())
            {
                while (!file.eof())
                {
                    file >> A[count];
                    count++;
                }
                file.close();
            }
            count--;
            cout << " Слово из файла: ";
            for (int i = 0; i < count; i++) {
                cout << A[i];
            }
            cout << "\n Зашифрованное слово : ";
            encode(A, B, C, count);
            cout << "\n Расшифрованное слово : ";
            decode(A, B, C, count);
            cout << "\n";
            system("pause");
            c = 0;
        }
        if (c == 2) {
            int count = 0;
            char B[54] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            char C[54] = "ZYXWVUTSRQPONMLKJHGFEDCBAzyxwvutsrqponmlkjihgfedcba";
            char A[100]{};
            char v;
            cout << " Введите тестовый пример : ";
            cin.get(v);
            while (cin.get(v)) {
                if (v == '\n')
                    break;
                A[count] = v;
                count++;
            }
            cout << " Зашифрованное слово : ";
            encode(A, B, C, count);
            cout << "\n Расшифрованное слово : ";
            decode(A, B, C, count);
            cout << "\n";
            system("pause");
            c = 0;
        }
        if (c == 3) {
            return 0;
        }
    }
}