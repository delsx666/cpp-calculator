#include "calculator.h"

// из пред. задания по сути заменяет std::cin >> curr_num
// ф-ция ReadNumber впринипе принимает чё угодно, что было объявленно в коде
// главное в качестве аргумента передавать число, иначе ошибка, так как std::cin
// не может записать в "double" что то кроме числа 
bool ReadNumber(Number& result) { 
    if (std::cin >> result) {
        return true;
    } else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

// вообщем по сути всё из старого задания перенеслось сюда
// добавлена логика s и l, впринципе как и предыдущие команды
bool RunCalculatorCycle() { 
    Number total_summ;
    Number numInMemory = 0; 
    bool isInMemory = false;

    if (!ReadNumber(total_summ)) {
        return false;
    }

    std::string expression;

    // смысл цикла такой, сначалы мы считали число и сразу записали его в сумму
    // потом цикл ожидает либо математические операции, либо команду-букву
    // если после числа идёт ещё 1 число, выкидывает ошибку
    // после мат.операции создаётся временная переменная,
    // которая и хранит значение введённого после операции числа
    // потом делает с этим числом то, что до этого было введено в expression 
    while (std::cin >> expression) { 
        if (expression == "+" || expression == "-" || expression == "*" || expression == "/" || expression == "**" || expression == ":") {
            Number curr_num;
            if (!ReadNumber(curr_num)) {
                return false;
            }

            if (expression == "+") {
                total_summ += curr_num;
            } else if (expression == "-") {
                total_summ -= curr_num;
            } else if (expression == "*") {
                total_summ *= curr_num;
            } else if (expression == "/") {
                total_summ /= curr_num;
            } else if (expression == "**") {
                total_summ = std::pow(total_summ, curr_num);
            } else if (expression == ":") {
                total_summ = curr_num;
            }
        } else if (expression == "=") {
            std::cout << total_summ << std::endl;
        } else if (expression == "c") {
            total_summ = 0;
        } else if (expression == "q") {
            return true;
        } else if (expression == "s") {
            numInMemory = total_summ;
            isInMemory = true;
        } else if (expression == "l") {
            if (isInMemory) {
                total_summ = numInMemory;
            } else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        } else {
            std::cerr << "Error: Unknown token " << expression << std::endl;
            return false;
        }
    }

    return true;
}