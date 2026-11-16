#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 1000;  // Размерность матриц
    int local_N = N / size;  // Количество строк, обрабатываемых каждым процессом

    // Инициализация матриц A, B и C
    double* A = NULL;
    double* C = NULL;
    if (rank == 0) {
        A = (double*)malloc(N * N * sizeof(double));
        C = (double*)calloc(N * N, sizeof(double));  // Итоговая матрица
        // Заполнение матрицы A случайными значениями
        for (int i = 0; i < N * N; i++) {
            A[i] = rand() % 10;
        }
    }

    // Матрица B должна быть доступна на всех процессах
    double* B = (double*)malloc(N * N * sizeof(double));
    // Заполнение матрицы B случайными значениями на процессе 0
    if (rank == 0) {
        for (int i = 0; i < N * N; i++) {
            B[i] = rand() % 10;
        }
    }
    // Распространение матрицы B на все процессы
    MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Распределение строк матрицы A по процессам
    double* local_A = (double*)malloc(local_N * N * sizeof(double));
    MPI_Scatter(A, local_N * N, MPI_DOUBLE, local_A, local_N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Локальная часть матрицы C для каждого процесса
    double* local_C = (double*)calloc(local_N * N, sizeof(double));

    // Умножение локальных подматриц
    for (int i = 0; i < local_N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                local_C[i * N + j] += local_A[i * N + k] * B[k * N + j];
            }
        }
    }

    // Сбор результатов от всех процессов в процессе 0
    MPI_Gather(local_C, local_N * N, MPI_DOUBLE, C, local_N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Вывод результата (только на процессе 0)
    if (rank == 0) {
        printf("Результат умножения матриц:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%.2f ", C[i * N + j]);
            }
            printf("\n");
        }
    }

    // Освобождение памяти
    if (rank == 0) {
        free(A);
        free(C);
    }
    free(B);
    free(local_A);
    free(local_C);

    MPI_Finalize();
    return 0;
}
