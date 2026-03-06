// Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
// не содержат пробелов. При выполнении заданий не следует использовать оператор цикла.
// Вывести значение целочисленного выражения, заданного в виде строки S. Выражение
// определяется следующим образом (функция M возвращает максимальный из своих параметров,
// а функция m — минимальный) :
//	 <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Преобразует последовательность цифр в целое число
int ParseNumber(const std::string& InString, size_t& InOutPos)
{
    int Number = 0;
    while (InOutPos < InString.length() && InString[InOutPos] >= '0' && InString[InOutPos] <= '9')
    {
        Number = Number * 10 + (InString[InOutPos] - '0');
        InOutPos++;
    }
    return Number;
}

// Вычисляет значение арифметического выражения
int CalculateExpression(const std::string& InString, size_t& InOutPos)
{
    if (InString[InOutPos] >= '0' && InString[InOutPos] <= '9')
    {
        return ParseNumber(InString, InOutPos);
    }

    if (InString[InOutPos] == 'M' || InString[InOutPos] == 'm')
    {
        char Operation = InString[InOutPos];
        InOutPos++;

        // Пропускаем символы до открывающей скобки
        while (InOutPos < InString.length() && InString[InOutPos] != '(')
        {
            InOutPos++;
        }
        InOutPos++; // Пропускаем '('

        int LeftValue = CalculateExpression(InString, InOutPos);

        // Пропускаем символы до запятой
        while (InOutPos < InString.length() && InString[InOutPos] != ',')
        {
            InOutPos++;
        }
        InOutPos++; // Пропускаем ','

        int RightValue = CalculateExpression(InString, InOutPos);

        // Пропускаем символы до закрывающей скобки
        while (InOutPos < InString.length() && InString[InOutPos] != ')')
        {
            InOutPos++;
        }
        InOutPos++; // Пропускаем ')'

        if (Operation == 'M')
        {
            return std::max(LeftValue, RightValue);
        }
        else
        {
            return std::min(LeftValue, RightValue);
        }
    }

    if (InString[InOutPos] == '(')
    {
        InOutPos++; // Пропускаем '('
        int Result = CalculateExpression(InString, InOutPos); // продолжаем вычислять уже внутреннее выражение
        if (InOutPos >= InString.length() || InString[InOutPos] != ')')
        {
            std::cout << "Ошибка: ожидается закрывающая скобка" << std::endl;
            return 0;
        }
        InOutPos++; // Пропускаем ')'
        return Result;
    }

    // Если дошли до этой точки, значит выражение некорректно
    std::cout << "Ошибка: некорректное выражение" << std::endl;
    return 0;
}

int Task4()
{
    //FIX_ME: Неправильная установка кодировки
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    std::cout << "Добро пожаловать! " << std::endl;
    std::cout << "Перед нами стоит задача: найти значение выражения типа" << std::endl;
    std::cout << " <выражение> ::= <цифра> | M(<выражение> , <выражение>) | " << std::endl;
    std::cout << "m(<выражение>, <выражение>)" << std::endl;
    std::cout << "где M - функция, которая выбирает большее значение из двух чисел." << std::endl;
    std::cout << "а m - функция, которая выбирает меньшее значение из двух чисел." << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Ваша задача - записать любое выражение, которое вы захотите" << std::endl;
    std::cout << "БЕЗ ИСПОЛЬЗОВАНИЯ ПРОБЕЛОВ" << std::endl;
    std::cout << "А мы посчитаем значение и выведем его на экран." << std::endl;
    std::cout << "Важное замечание: вводить можно только целые неотрицательные числа." << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Выражение может выглядеть так:" << std::endl;
    std::cout << "M(1234,m(12345,M(175,m(1270,1980))))" << std::endl;
    std::cout << "m(M(12759,m(1370,140)),m(1345,6789))" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::string InputString;
    std::cout << "Введите выражение: ";
    std::getline(std::cin, InputString);

    size_t Position = 0;
    int Result = CalculateExpression(InputString, Position);

    std::cout << std::endl;
    std::cout << "Полученный результат равен: ";
    std::cout << Result << std::endl;

    return 0;
}
