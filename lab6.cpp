// ЛР 6. Двумерные массивы.
//
#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

const int MAXST = 10;
const int MAXSTR = 10;
int randint;
/*
12. Дана матрица размера M × N. Вывести ее элементы в следующем
порядке: первый столбец сверху вниз, второй столбец снизу вверх, третий
столбец сверху вниз, четвертый столбец снизу вверх и т. д
*/
void solution_1() {
    int array[MAXST][MAXSTR];
    int usern, userm;
    cin >> usern >> userm;
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            array[i][j] = rand();
        };
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            cout << array[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец исходного массива\n";
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            if (j % 2 != 0) {
                cout << array[usern - 1 - i][j] << '\t';
            }
            else {
                cout << array[i][j] << '\t';
            };
        };
        cout << "\n";
    };
    cout << "Конец итогового массива\n";
}

void dynamic_solution_1() {
    int usern, userm;
    //выделяем память для массива указателей
    int** arr{ new int* [MAXST] {}}; //указатель на указатель
    //выделяем память для каждого отдельного массива
    for (int i = 0; i < MAXST; i++) {
        arr[i] = new int [MAXSTR] {};
    };
    cin >> usern >> userm;
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            arr[i][j] = rand();
        };
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            cout << arr[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец исходного массива\n";
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            if (j % 2 != 0) {
                cout << arr[usern - 1 - i][j] << '\t';
            }
            else {
                cout << arr[i][j] << '\t';
            };
        };
        cout << "\n";
    };
    cout << "Конец итогового массива\n";
    for (int i = 0; i < MAXST; i++) {
        delete[] arr[i];
    };
    delete[] arr;

}

/*
12. Дана матрица размера M × N и целое число K (1 ≤ K ≤ N ). Удалить столбец матрицы с номером K.
*/
void solution_2() {
    int array[MAXST][MAXSTR];
    int usern, userm, k;
    cin >> usern >> userm >> k;
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            array[i][j] = rand();
        };
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            cout << array[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец исходного массива\n";
    for (int i = 0; i < usern; i++) {
        for (int j = k - 1; j < userm; j++) {
            array[i][j] = array[i][j + 1];
        };
        cout << "\n";
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm - 1; j++) {
            cout << array[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец итогового массива\n";
}



void dynamic_solution_2() {
    int usern, userm, k;
    int** arr{ new int* [MAXST] {} };
    for (int i = 0; i < MAXST; i++) {
        arr[i] = new int [MAXSTR] {};
    };
    cin >> usern >> userm >> k;
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            arr[i][j] = rand();
        };
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm; j++) {
            cout << arr[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец исходного массива\n";
    for (int i = 0; i < usern; i++) {
        for (int j = k - 1; j < userm; j++) {
            arr[i][j] = arr[i][j + 1];
        };
        cout << "\n";
    };
    for (int i = 0; i < usern; i++) {
        for (int j = 0; j < userm - 1; j++) {
            cout << arr[i][j] << '\t';
        };
        cout << "\n";
    };
    cout << "Конец итогового массива\n";
    for (int i = 0; i < MAXST; i++) {
        delete[] arr[i];
    };
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int UserChoise;
    while (true) {
        cout << "Здравствуйте, напишите номер подпрограммы, в которую хотите попасть\n(1, 2, а для выхода введите -1)\n";
        cin >> UserChoise;
        if (UserChoise == 1) { solution_1(); }
        else if (UserChoise == 2) { solution_2(); }
        else if (UserChoise == 3) { dynamic_solution_1(); }
        else if (UserChoise == 4) { dynamic_solution_2(); }
        else if (UserChoise == -1) { break; }
        else { cout << "Неправильная цифра!"; };
        cout << "\n";
    }
    return 0;
}
