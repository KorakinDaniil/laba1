#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <climits>

// Общая проблема

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <Windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Task1

//FIX_ME: Непонятные названия переменных
//void SelectArts(vector<vector<int>>& dp, int k, int s, vector<int>& weights, vector<int>& time);

// Восстанавливает номер выбранных артефактов
void SelectArtifacts(const std::vector<std::vector<int>>& InDp, int InK, int InS,
    const std::vector<int>& InWeights, std::vector<int>& OutSelectedIndices);

int Task1();

// Task2

int Task2();

// Task3

int Task3();

// Task4

// Преобразует последовательность цифр в целое число
int ParseNumber(const std::string& InString, size_t& InOutPos);

// Вычисляет значение арифметического выражения
int CalculateExpression(const std::string& InString, size_t& InOutPos);

int Task4();
