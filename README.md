# laba1

Общие изменения

using namespace std; ->	Убрано, добавлен префикс std::

Подключение Windows.h	-> setlocale(LC_ALL, "ru")

SetConsoleCP/SetConsoleOutputCP	 -> setlocale

Магические числа (999, 9999, 100) ->	Заменены на константы INF или вычисляемые значения

Комментарии	Улучшены и приведены к стандарту

Добавлены отступы, фигурные скобки

Task01

SelectArts -> SelectArtifacts

Параметры dp, k, s, weights, time -> const std::vector<std::vector<int>>& InDp, int InK, int InS, const std::vector<int>& InWeights, std::vector<int>& OutSelectedIndices

Индексация с 1 ->	Индексация с 0 с преобразованием для вывода

Рекурсия без накопления -> Рекурсия с накоплением результатов в вектор

vector<vector<int>> dp ->	std::vector<std::vector<int>> Dp

int max_weight ->	int MaxWeight

int min_time = 9999 ->	int MinTax = INF

int min_time ->	int MinTax

int total_weight ->	int TotalWeight

vector<int> selected ->	std::vector<int> SelectedIndices

Вывод в прямом порядке ->	Вывод в обратном порядке

Отсутствие проверки границ ->	Добавлена проверка InS < static_cast<int>(InDp[InK].size())

Task02

input ->	InputFile

output ->	OutputFile

weights ->	Weights

taxes ->	Taxes

dp ->	Dp

selected ->	Selected

min_tax ->	MinTax

best_weight ->	BestWeight

best_selection ->	BestSelection

int max_possible_weight = Z + 100 ->	int MaxPossibleWeight = TotalWeight (вычисляется реальная сумма)

Отсутствие проверок открытия файлов ->	Добавлены проверки is_open()

Неинициализированные переменные ->	Явная инициализация int N = 0, Z = 0

Task03

dp ->	Dp

result ->	Result

K, N без инициализации	-> int K = 0, N = 0

Отсутствие проверок входных данных ->	

Добавлены проверки:
- K < 2 || K > 10 → ошибка
- N <= 1 || N >= 20 → ошибка
- K + N >= 26 → ошибка

Неинформативные комментарии ->	Добавлены пояснения: // DP[i][j] - количество чисел длины i, заканчивающихся на цифру j

Task04

num ->	ParseNumber

calc ->	CalculateExpression

s ->	InString

pos ->	InOutPos (для изменяемых) / Position (для локальных)

op ->	Operation

number ->	Number

left/right ->	LeftValue/RightValue

result ->	Result

Ручное сравнение if (left > right) ->	std::max(left, right)

Ручное сравнение if (left < right) ->	std::min(left, right)

Отсутствие обработки ошибок ->

Добавлены проверки:
- Наличие закрывающей скобки
- Некорректное выражение
- Пустой ввод
