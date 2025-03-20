// Задача 1

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#define N 5

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    void minimum(float matrix[N][N]);
    void maximum(float matrix[N][N]);
    void maximumLowTriangular(float matrix[N][N]);
    void maximumTopTriangular(float matrix[N][N]);
    void minimumLowTriangular(float matrix[N][N]);
    void minimumTopTriangular(float matrix[N][N]);
    void minimumTriangular(float matrix[N][N]);
    void maximumTriangular(float matrix[N][N]);
    void minimumTriangularReverse(float matrix[N][N]);
    void maximumTriangularReverse(float matrix[N][N]);
    void average(float matrix[N][N]);
    void averageLowTriangular(float matrix[N][N]);
    void averageTopTriangular(float matrix[N][N]);
    void sumRows(float matrix[N][N]);
    void sumСolumns(float matrix[N][N]);
    void sumRowsMin(float matrix[N][N]);
    void sumСolumnsMin(float matrix[N][N]);
    void sumRowsMax(float matrix[N][N]);
    void sumСolumnsMax(float matrix[N][N]);
    void avverageRows(float matrix[N][N]);
    void avverageСolumns(float matrix[N][N]);
    void sumLowTriangular(float matrix[N][N]);
    void sumTopTriangular(float matrix[N][N]);
    void avverageEquals(float matrix[N][N]);


    float m[N][N];

    std::cout << "Исходная матрица" << std::endl;

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            std::cout << "\t" << std::setw(8) << std::setprecision(5) << m[i][j];
        }
        std::cout << std::endl;
    }
    // getch();
    minimum(m);
    maximum(m);
    maximumLowTriangular(m);
    maximumTopTriangular(m);
    minimumLowTriangular(m);
    minimumTopTriangular(m);
    minimumTriangular(m);
    maximumTriangular(m);
    minimumTriangularReverse(m);
    maximumTriangularReverse(m);
    average(m);
    averageLowTriangular(m);
    averageTopTriangular(m);
    sumRows(m);
    sumСolumns(m);
    sumRowsMin(m);
    sumСolumnsMin(m);
    sumRowsMax(m);
    sumСolumnsMax(m);
    avverageRows(m);
    avverageСolumns(m);
    sumLowTriangular(m);
    sumTopTriangular(m);
    avverageEquals(m);
    //  getch();
    return 0;
}

// минимум матрицы, воспользуемся решением в лоб
void minimum(float matrix[N][N])
{
    if (matrix != NULL)
    {
        auto min = matrix[0][0];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                }
            }
        }
        std::cout << "минимум матрицы:" << std::setw(8) << std::setprecision(5) << min << std::endl;
    }
}

// максимум матрицы, воспользуемся решением в лоб
void maximum(float matrix[N][N])
{
    auto max = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    std::cout << "максимум матрицы:" << std::setw(8) << std::setprecision(5) << max << std::endl;
}

// нижнетреугольная часть матрицы - часть матрицы, где все элементы выше главной диагонали равны нулю или в нашем случае не учитываются
// максимум такой матрицы
void maximumLowTriangular(float matrix[N][N])
{
    auto max = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    std::cout << "максимум нижнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << max << std::endl;
}

// Верхнетреугольная часть матрицы - часть матрицы, где все элементы ниже главной диагонали равны нулю или в нашем случае не учитываются
// максимум такой матрицы
void maximumTopTriangular(float matrix[N][N])
{
    auto max = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    std::cout << "максимум верхнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << max << std::endl;
}

// нижнетреугольная часть матрицы - часть матрицы, где все элементы выше главной диагонали равны нулю или в нашем случае не учитываются
// минимум такой матрицы
void minimumLowTriangular(float matrix[N][N])
{

    auto min = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    std::cout << "минимум нижнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << min << std::endl;
}

// Верхнетреугольная часть матрицы - часть матрицы, где все элементы ниже главной диагонали равны нулю или в нашем случае не учитываются
// минимум такой матрицы
void minimumTopTriangular(float matrix[N][N])
{
    auto min = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    std::cout << "минимум верхнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << min << std::endl;
}

// минимум главной диагонали
void minimumTriangular(float matrix[N][N])
{
    auto min = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        if (matrix[i][i] < min)
        {
            min = matrix[i][i];
        }
    }
    std::cout << "минимум главной диагонали матрицы:" << std::setw(8) << std::setprecision(5) << min << std::endl;
}

// максимум главной диагонали
void maximumTriangular(float matrix[N][N])
{

    auto max = matrix[0][0];

    for (int i = 0; i < N; i++)
    {
        if (matrix[i][i] > max)
        {
            max = matrix[i][i];
        }
    }
    std::cout << "максимум главной диагонали матрицы:" << std::setw(8) << std::setprecision(5) << max << std::endl;
}

// минимум второстепенной диагонали
void minimumTriangularReverse(float matrix[N][N])
{
    auto min = matrix[0][N - 1];

    for (int i = 0; i < N; i++)
    {
        if (matrix[i][N - 1 - i] < min)
        {
            min = matrix[i][N - 1 - i];
        }
    }
    std::cout << "минимум второстепенной диагонали матрицы:" << std::setw(8) << std::setprecision(5) << min << std::endl;
}

// максимум второстепенной диагонали
void maximumTriangularReverse(float matrix[N][N])
{
    auto max = matrix[0][N - 1];

    for (int i = 0; i < N; i++)
    {
        if (matrix[i][N - 1 - i] > max)
        {
            max = matrix[i][N - 1 - i];
        }
    }
    std::cout << "максимум второстепенной диагонали матрицы:" << std::setw(8) << std::setprecision(5) << max << std::endl;
}

// среднее значение
void average(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            value += matrix[i][j];
            count++;
        }
    }
    double result = value / count;
    std::cout << "среднее значение матрицы:" << std::setw(8) << std::setprecision(5) << result << std::endl;
}

// нижнетреугольная часть матрицы - часть матрицы, где все элементы выше главной диагонали равны нулю или в нашем случае не учитываются
// среднее значение
void averageLowTriangular(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            value += matrix[i][j];
            count++;
        }
    }
    double result = value / count;
    std::cout << "среднее нижнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << result << std::endl;
}

// Верхнетреугольная часть матрицы - часть матрицы, где все элементы ниже главной диагонали равны нулю или в нашем случае не учитываются
// среднее значение
void averageTopTriangular(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            value += matrix[i][j];
            count++;
        }
    }
    double result = value / count;
    std::cout << "среднее значение верхнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << result << std::endl;
}

// сумма строк
void sumRows(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double result = 0.0;
        for (int j = i; j < N; j++)
        {
            result += matrix[i][j];
        }
        std::cout << "Сумма строки" << i << " : " << std::setw(8) << std::setprecision(5) << result << std::endl;
    }
}

// сумма столбцов
void sumСolumns(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        double result = 0.0;
        for (int j = i; j < N; j++)
        {
            result += matrix[j][i];
        }
        std::cout << "Сумма столбца" << i << " : " << std::setw(8) << std::setprecision(5) << result << std::endl;
    }
}

// минимальное значение строк
void sumRowsMin(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        auto min = matrix[i][0];
        for (int j = i; j < N; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        std::cout << "минимальное значение строки" << i << " : " << std::setw(8) << std::setprecision(5) << min << std::endl;
    }
}

// минимальное значение столбцов
void sumСolumnsMin(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        auto min = matrix[0][i];
        for (int j = i; j < N; j++)
        {
            if (matrix[j][i] < min)
            {
                min = matrix[j][i];
            }
        }
        std::cout << "минимальное значение столбца" << i << " : " << std::setw(8) << std::setprecision(5) << min << std::endl;
    }
}

// максимальное значение строк
void sumRowsMax(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        auto max = matrix[i][0];
        for (int j = i; j < N; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        std::cout << "максимальное значение строки" << i << " : " << std::setw(8) << std::setprecision(5) << max << std::endl;
    }
}

// максимальное значение столбцов
void sumСolumnsMax(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        auto max = matrix[0][i];
        for (int j = i; j < N; j++)
        {
            if (matrix[j][i] > max)
            {
                max = matrix[j][i];
            }
        }
        std::cout << "максимальное значение столбца" << i << " : " << std::setw(8) << std::setprecision(5) << max << std::endl;
    }
}

// среднее значение строк
void avverageRows(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            value += matrix[i][j];
            count++;
        }
        auto result = value / count;
        std::cout << "среднее значение строки" << i << " : " << std::setw(8) << std::setprecision(5) << result << std::endl;
    }
}

// среднее значение столбца
void avverageСolumns(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            value += matrix[j][i];
            count++;
        }
        auto result = value / count;
        std::cout << "среднее значение столбца" << i << " : " << std::setw(8) << std::setprecision(5) << result << std::endl;
    }
}

// нижнетреугольная часть матрицы - часть матрицы, где все элементы выше главной диагонали равны нулю или в нашем случае не учитываются
// сумма такой матрицы
void sumLowTriangular(float matrix[N][N])
{
    double result = 0.0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            result += matrix[i][j];
        }
    }
    std::cout << "сумма нижнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << result << std::endl;
}

// Верхнетреугольная часть матрицы - часть матрицы, где все элементы ниже главной диагонали равны нулю или в нашем случае не учитываются
// сумма такой матрицы
void sumTopTriangular(float matrix[N][N])
{
    double result = 0.0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            result += matrix[i][j];
        }
    }
    std::cout << "сумма верхнетреугольной части матрицы:" << std::setw(8) << std::setprecision(5) << result << std::endl;
}

// среднее значение
float averageHelp(float matrix[N][N])
{
    double value = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            value += matrix[i][j];
            count++;
        }
    }
    double result = value / count;
   return (float) result;
}


// наиболее близкий к среднеарефметическому
void avverageEquals(float matrix[N][N])
{
    float average = averageHelp(matrix);
    float min;
    if (average<0){
        if(matrix[0][0]<0){
        min = std::abs(average - matrix[0][0]);
        }
        else {
            min = std::abs(average + matrix[0][0]);  
        }
    }
    else {
        if(matrix[0][0]<0){
            min = std::abs(average + matrix[0][0]);
            }
            else {
                min = std::abs(average - matrix[0][0]);  
            }
    }

     

    std::cout << "Начальный минимум:" << std::setw(8) << std::setprecision(5) << min << std::endl;

    int index1=0, index2=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float nebalans;
            if (average<0){
                if(matrix[i][j]<0){
                min = std::abs(average - matrix[i][j]);
                }
                else {
                    min = std::abs(average + matrix[i][j]);  
                }
            }
            else {
                if(matrix[i][j]<0){
                    min = std::abs(average + matrix[i][j]);
                    }
                    else {
                        min = std::abs(average - matrix[i][j]);  
                    }
            }

            if (nebalans<min){
                min =nebalans;
                index1=i;
                index2=j;
            }
        }
    }
    std::cout << "наиболее близкий к среднеарефметическому" << average <<" элемент :" <<"["<< index1<<"]"<<"["<< index2<<"]" << std::setw(8) << std::setprecision(5) << matrix[index1][index2] << std::endl;
}