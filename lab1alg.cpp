#include <iostream>

using namespace std;
/*Первая задача*/

/*int main() {
    int M, N;

    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M]; // Динамическое выделение памяти для массива A
    int* B = new int[N]; // Динамическое выделение памяти для массива B

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* C = new int[min(M, N)]; // Третий массив минимального размера

    int* ptrA = A;
    int* ptrB = B;
    int* ptrC = C;

    for (int i = 0; i < M; i++) {
        ptrB = B; // Сбрасываем указатель на начало B при каждой итерации A
        for (int j = 0; j < N; j++) {
            if (*ptrA == *ptrB) { // Если элементы совпадают
                bool isDuplicate = false;
                int* ptrCtemp = C; // Указатель для проверки на дубликат в C
                for (int k = 0; k < (ptrC - C); k++) {
                    if (*ptrCtemp == *ptrA) {
                        isDuplicate = true;
                        break;
                    }
                    ptrCtemp++;
                }
                if (!isDuplicate) {
                    *ptrC = *ptrA;
                    ptrC++;
                }
            }
            ptrB++;
        }
        ptrA++;
    }

    cout << "Общие элементы двух массивов без повторений: ";
    for (int i = 0; i < (ptrC - C); i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем память, выделенную для динамических массивов
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}*/
/*Вторая задача*/

/*int main() {
    int M, N;

    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M]; // Создаем динамический массив A
    int* B = new int[N]; // Создаем динамический массив B

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* C = new int[M]; // Создаем динамический массив C для хранения результатов
    int count = 0; // Инициализируем счетчик элементов в массиве C

    for (int i = 0; i < M; i++) {
        bool isDuplicate = false;

        // Проверяем, есть ли элемент A[i] в массиве B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isDuplicate = true;
                break;
            }
        }

        // Если элемент A[i] не найден в B и не является дубликатом в C, добавляем его в C
        if (!isDuplicate) {
            bool isAlreadyInC = false;

            for (int k = 0; k < count; k++) {
                if (A[i] == C[k]) {
                    isAlreadyInC = true;
                    break;
                }
            }

            if (!isAlreadyInC) {
                C[count] = A[i];
                count++;
            }
        }
    }

    cout << "Элементы массива A, которые не включаются в B без повторений: ";
    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем память, выделенную для динамических массивов
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}*/
/*Третья задача*/


/*int main() {
    int M, N;

    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M]; // Создаем динамический массив A
    int* B = new int[N]; // Создаем динамический массив B

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* C = new int[M + N]; // Создаем динамический массив C для хранения результатов
    int count = 0; // Инициализируем счетчик элементов в массиве C

    // Перебираем элементы массива A
    for (int i = 0; i < M; i++) {
        bool isDuplicate = false;

        // Проверяем, есть ли элемент A[i] в массиве B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isDuplicate = true;
                break;
            }
        }

        // Если элемент A[i] не найден в B и не является дубликатом в C, добавляем его в C
        if (!isDuplicate) {
            bool isAlreadyInC = false;

            for (int k = 0; k < count; k++) {
                if (A[i] == C[k]) {
                    isAlreadyInC = true;
                    break;
                }
            }

            if (!isAlreadyInC) {
                C[count] = A[i];
                count++;
            }
        }
    }

    // Перебираем элементы массива B
    for (int i = 0; i < N; i++) {
        bool isDuplicate = false;

        // Проверяем, есть ли элемент B[i] в массиве A
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                isDuplicate = true;
                break;
            }
        }

        // Если элемент B[i] не найден в A и не является дубликатом в C, добавляем его в C
        if (!isDuplicate) {
            bool isAlreadyInC = false;

            for (int k = 0; k < count; k++) {
                if (B[i] == C[k]) {
                    isAlreadyInC = true;
                    break;
                }
            }

            if (!isAlreadyInC) {
                C[count] = B[i];
                count++;
            }
        }
    }

    cout << "Элементы, которые не являются общими для A и B без повторений: ";
    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Освобождаем память, выделенную для динамических массивов
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}*/
/*Четвертая задача*/
/*
// Функция для добавления блока элементов в конец массива
void appendBlock(int*& arr, int& size, const int* block, int blockSize) {
    // Создаем новый временный массив с увеличенным размером
    int newSize = size + blockSize;
    int* tempArr = new int[newSize];

    // Копируем существующие элементы из arr в tempArr
    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }

    // Копируем блок элементов в конец tempArr
    for (int i = 0; i < blockSize; i++) {
        tempArr[size + i] = block[i];
    }

    // Освобождаем память, выделенную для старого массива
    delete[] arr;

    // Обновляем указатель и размер массива
    arr = tempArr;
    size = newSize;
}

int main() {
    int* myArray = new int[5]; // Исходный массив с 5 элементами
    int size = 5; // Размер исходного массива

    // Задаем числа для исходного массива
    myArray[0] = 1;
    myArray[1] = 2;
    myArray[2] = 3;
    myArray[3] = 4;
    myArray[4] = 5;

    // Выводим исходный массив
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;



    // Ввод блока элементов с клавиатуры
    int blockSize;
    cout << "Введите размер блока элементов: ";
    cin >> blockSize;

    int* block = new int[blockSize];
    cout << "Введите элементы блока: ";
    for (int i = 0; i < blockSize; i++) {
        cin >> block[i];
    }

    // Вызываем функцию для добавления блока в конец массива
    appendBlock(myArray, size, block, blockSize);

    // Выводим обновленный массив
    cout << "Обновленный массив: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Освобождаем память, выделенную для массива и блока
    delete[] myArray;
    delete[] block;

    return 0;
}*/
/*Пятая задача*/

/*
void insertBlock(int*& arr, int& size, const int* block, int blockSize, int index) {
    if (index < 0 || index > size) {
        cout << "Ошибка: Неверный индекс для вставки." << endl;
        return;
    }

    // Создаем новый временный массив с увеличенным размером
    int newSize = size + blockSize;
    int* tempArr = new int[newSize];

    // Копируем элементы до указанного индекса
    for (int i = 0; i < index; i++) {
        tempArr[i] = arr[i];
    }

    // Копируем блок элементов вставки
    for (int i = 0; i < blockSize; i++) {
        tempArr[index + i] = block[i];
    }

    // Копируем оставшиеся элементы из исходного массива после индекса
    for (int i = index; i < size; i++) {
        tempArr[index + blockSize + (i - index)] = arr[i];
    }

    // Освобождаем память, выделенную для старого массива
    delete[] arr;

    // Обновляем указатель и размер массива
    arr = tempArr;
    size = newSize;
}



int main() {
    int* myArray = new int[5]; // Исходный массив с 5 элементами
    int size = 5; // Размер исходного массива

    // Задаем числа для исходного массива
    myArray[0] = 1;
    myArray[1] = 2;
    myArray[2] = 3;
    myArray[3] = 4;
    myArray[4] = 5;

    // Выводим исходный массив
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Ввод блока элементов с клавиатуры
    int blockSize;
    cout << "Введите размер блока элементов: ";
    cin >> blockSize;

    int* block = new int[blockSize];
    cout << "Введите элементы блока: ";
    for (int i = 0; i < blockSize; i++) {
        cin >> block[i];
    }

    // Ввод индекса, с которого начать вставку
    int insertIndex;
    cout << "Введите индекс для вставки блока: ";
    cin >> insertIndex;

    // Вызываем функцию для вставки блока в массив
    insertBlock(myArray, size, block, blockSize, insertIndex);

    // Выводим обновленный массив
    cout << "Обновленный массив: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Освобождаем память, выделенную для массивов
    delete[] myArray;
    delete[] block;

    return 0;
}*/