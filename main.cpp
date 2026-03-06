#include "head.h"

int main()
{
    setlocale(LC_ALL, "ru");

    // Флаг для продолжения
    bool bContinue = false;

    std::cout << "Выполняем запуск Task1" << std::endl;
    Task1();

    std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
    std::cin >> bContinue;

    if (bContinue)
    {
        std::cout << "Выполняем запуск Task2" << std::endl;
        Task2();

        std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
        std::cin >> bContinue;

        if (bContinue)
        {
            std::cout << "Выполняем запуск Task3" << std::endl;
            Task3();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
            std::cin >> bContinue;

            if (bContinue)
            {
                std::cout << "Выполняем запуск Task4" << std::endl;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Task4();
            }
        }
    }

    return 0;
}
