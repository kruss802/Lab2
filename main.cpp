#include <locale.h>
#include "Train.h"

#define _CRT_SECURE_NO_WARNINGS_

void print_menu() {
    system("cls");
    printf("��� �� ������ �������?\n");
    printf("1. �������� ������\n");
    printf("2. ������� ��� ������ �� �����\n");
    printf("3. �����\n");
    printf(">");
}

//int get_variant(int count) {
//    int variant;
//    char s[100];
//    cin >> s;
//    while (sscanf_s(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
//        cout << ("������������ ����, ���������� �����: ");
//        cin >> s;
//    }
//    return variant;
//}

int main()
{
    int variant;
    setlocale(LC_ALL, "rus");
    Train p;
    do {
        print_menu(); 
        cin >> variant;

        switch (variant) {
        case 1:
            p.Add();
            break;

        case 2:
            p.Show();
            break;
        }

        if (variant != 3)
            system("pause"); 
    } while (variant != 3);

    return 0;
}