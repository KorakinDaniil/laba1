// Археолог нашел N артефактов. Известны веса (сi) и налоговое бремя (di) находок.
// Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг,
// а их общее налоговое бремя оказалось минимальным. Известно, что решение единственно.
// Укажите порядковые номера вещей, которые нужно взять. Исходные данные находятся в
// текстовом файле, в первой строке указаны N и Z, а во второй строке значения весов
// (в кг), в третьей - величина налога по каждой находке. Вывести так же суммарный вес
// и общую ценность результата.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

int Task2()
{
    std::ifstream InputFile("input.txt");
    std::ofstream OutputFile("output.txt");

    if (!InputFile.is_open())
    {
        std::cout << "Ошибка открытия входного файла" << std::endl;
        return 1;
    }

    if (!OutputFile.is_open())
    {
        std::cout << "Ошибка открытия выходного файла" << std::endl;
        return 1;
    }

    int N = 0, Z = 0; // кол-во артефактов и мин. требуемый вес
    InputFile >> N >> Z;

    std::vector<int> Weights(N); // вектор для хранения весов артефактов
    std::vector<int> Taxes(N);   // вектор для хранения налогового бремени

    for (int i = 0; i < N; ++i)
    {
        InputFile >> Weights[i];
    }

    for (int i = 0; i < N; ++i)
    {
        InputFile >> Taxes[i];
    }

    //FIX_ME: Использование магического числа 100
    //int MaxPossibleWeight = Z + 100;
    // Лучше вычислить реальную максимальную сумму весов
    int TotalWeight = 0;
    for (int W : Weights)
    {
        TotalWeight += W;
    }
    int MaxPossibleWeight = TotalWeight;

    std::vector<int> Dp(MaxPossibleWeight + 1, INT_MAX); // dp[j] хранит минимальное налоговое бремя для веса j
    Dp[0] = 0;

    // Массив для хранения выбранных артефактов
    // selected[j][i] указывает, выбран ли i-й артефакт для веса j
    std::vector<std::vector<bool>> Selected(MaxPossibleWeight + 1, std::vector<bool>(N, false));

    for (int i = 0; i < N; ++i) // перебирает все артефакты
    {
        for (int j = MaxPossibleWeight; j >= Weights[i]; --j) // перебирает все возможные веса
        {
            if (Dp[j - Weights[i]] != INT_MAX && Dp[j - Weights[i]] + Taxes[i] < Dp[j])
            {
                Dp[j] = Dp[j - Weights[i]] + Taxes[i]; // обновляет мин нал бремя для веса j
                Selected[j] = Selected[j - Weights[i]]; // копирует выбранные артефакты для веса j - weights[i]
                Selected[j][i] = true;
            }
        }
    }

    // Находим минимальное налоговое бремя для веса, превышающего Z
    int MinTax = INT_MAX;
    int BestWeight = 0;
    std::vector<bool> BestSelection;

    for (int j = Z + 1; j <= MaxPossibleWeight; ++j) // перебирает все веса > Z
    {
        if (Dp[j] < MinTax)
        {
            MinTax = Dp[j];
            BestWeight = j;
            BestSelection = Selected[j];
        }
    }

    // Выводим результат
    OutputFile << "Выбранные артефакты: ";
    for (int i = 0; i < N; ++i)
    {
        if (BestSelection[i])
        {
            OutputFile << i + 1 << " ";
        }
    }
    OutputFile << std::endl;

    OutputFile << "Суммарный вес: " << BestWeight << " кг" << std::endl;
    OutputFile << "Общее налоговое бремя: " << MinTax << std::endl;

    InputFile.close();
    OutputFile.close();

    std::cout << "Результат сохранён в output.txt" << std::endl;

    return 0;
}
