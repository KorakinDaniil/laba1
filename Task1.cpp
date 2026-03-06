#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <Windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

/*
//FIX_ME: Непонятные названия переменных
void SelectArts(vector<vector<int>>& dp, int k, int s, vector<int>& weights, vector<int>& time)
{

    //FIX_ME: рекурсия без накопления результата
    if (k == 0 || s == 0)
        return;
    if (dp[k][s] == dp[k - 1][s])
    {
        SelectArts(dp, k - 1, s, weights, time);
    }
    else
    {
        cout << k << ' ';
        SelectArts(dp, k - 1, s - weights[k], weights, time);
    }
}
*/

// Восстанавливает номер выбранных артефактов
void SelectArtifacts(const std::vector<std::vector<int>>& InDp, int InK, int InS,
    const std::vector<int>& InWeights, std::vector<int>& OutSelectedIndices)
{
    if (InK == 0 || InS == 0)
    {
        return;
    }

    // Проверяем границы массивов
    if (InK - 1 >= 0 && InS < static_cast<int>(InDp[InK].size()))
    {
        // Проверяем, был ли артефакт InK не взят
        if (InDp[InK][InS] == InDp[InK - 1][InS])
        {
            SelectArtifacts(InDp, InK - 1, InS, InWeights, OutSelectedIndices);
        }
        else
        {
            // Артефакт был взят (индексация в InWeights с 0, поэтому используем InK-1)
            OutSelectedIndices.push_back(InK); // Сохраняем номер артефакта (1-based для вывода)
            if (InK - 1 >= 0 && InS - InWeights[InK - 1] >= 0)
            {
                SelectArtifacts(InDp, InK - 1, InS - InWeights[InK - 1], InWeights, OutSelectedIndices);
            }
        }
    }
}

int Task1()
{
    //FIX_ME: Неправильная установка кодировки
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    std::ifstream InputFile("1.1.txt");
    if (!InputFile.is_open())
    {
        std::cout << "Ошибка при открытии файла" << std::endl;
        return 1;
    }

    int N = 0, Z = 0;
    InputFile >> N >> Z;

    //FIX_ME: Индексация с 0 вместо 1 для упрощения
    std::vector<int> Weights(N);
    std::vector<int> Taxes(N);

    for (int i = 0; i < N; ++i)
    {
        InputFile >> Weights[i];
    }

    for (int i = 0; i < N; ++i)
    {
        InputFile >> Taxes[i];
    }

    InputFile.close();

    int MaxWeight = 0;
    for (int W : Weights)
    {
        MaxWeight += W;
    }

    //FIX_ME: Использование магического числа 999
    //vector<vector<int>> dp(N + 1, vector<int>(max_weight + 1, 999));
    const int INF = std::numeric_limits<int>::max() / 2;
    std::vector<std::vector<int>> Dp(N + 1, std::vector<int>(MaxWeight + 1, INF));

    for (int i = 0; i <= N; ++i)
    {
        Dp[i][0] = 0;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int s = 1; s <= MaxWeight; ++s)
        {
            Dp[k][s] = Dp[k - 1][s];

            if (s >= Weights[k - 1] && Dp[k - 1][s - Weights[k - 1]] != INF)
            {
                int NewValue = Dp[k - 1][s - Weights[k - 1]] + Taxes[k - 1];
                Dp[k][s] = std::min(Dp[k][s], NewValue);
            }
        }
    }

    //FIX_ME: Использование магического числа 9999
    //int min_time = 9999;
    int MinTax = INF;
    int TotalWeight = 0;

    for (int s = Z + 1; s <= MaxWeight; ++s)
    {
        if (Dp[N][s] < MinTax)
        {
            MinTax = Dp[N][s];
            TotalWeight = s;
        }
    }

    std::vector<int> SelectedIndices;
    SelectArtifacts(Dp, N, TotalWeight, Weights, SelectedIndices);

    //FIX_ME: Вывод в обратном порядке из-за рекурсии
    std::cout << "Выбранные артефакты -> ";
    for (auto It = SelectedIndices.rbegin(); It != SelectedIndices.rend(); ++It)
    {
        std::cout << *It << ' ';
    }
    std::cout << std::endl;

    std::cout << "Суммарный вес -> " << TotalWeight << " кг" << std::endl;
    std::cout << "Общее налоговое бремя -> " << MinTax << std::endl;

    return 0;
}
