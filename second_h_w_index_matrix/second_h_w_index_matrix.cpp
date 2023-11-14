#include <iostream>
#include <vector>
#include <clocale>
#include <algorithm>

bool isSymmetric(int* arr, int M) {
    return std::equal(arr, arr + M / 2, arr + M - 1, std::greater<int>());
}

int main() {
    setlocale(LC_ALL, "Rus");
    int N, M;
    std::cout << "Введите размеры матрицы NxM: ";
    std::cin >> N >> M;

    std::vector<int*> matrix(N);
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
        std::cout << "Введите элементы " << i + 1 << "-й строки матрицы: ";
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        B[i] = isSymmetric(matrix[i], M) ? 1 : 0;
    }

    std::cout << "Массив B: ";
    for (int i = 0; i < N; ++i) {
        std::cout << B[i] << ' ';
    }

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }

    return 0;
}
