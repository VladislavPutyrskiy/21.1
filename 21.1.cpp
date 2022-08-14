#include <iostream>
#include <fstream>
#include <sstream>

struct line {
    std::string name, surname, day, month, year, money;
} a;

int input_check(std::string a)
{
    int b = 0;
    try
    {
        b = stoi(a);
    }
    catch (const std::exception&)
    {
        b = -1;
    }
    return b;
}

void append()
{
    std::cout << "input name, surname, date of payment and amount of money\n";
    std::cout << "name: ";
    std::cin >> a.name;
    std::cout << "surname: ";
    std::cin >> a.surname;
    std::cout << "money: ";
    std::cin >> a.money;
    std::cout << "date (day, month, year)";
    std::cout << "day";
    std::cin >> a.day;
    std::cout << "month";
    std::cin >> a.month;
    std::cout << "year";
    std::cin >> a.year;
    if (input_check(a.money) < 0 || input_check(a.day)   < 1  || input_check(a.day)  > 31   || 
        input_check(a.month) < 1 || input_check(a.month) > 12 || input_check(a.year) < 1900 || 
        input_check(a.year) > 2022)
    {
        std::cout << "invalid input";
    }
    else
    {
        std::ofstream file("statement.txt", std::ios::app);
        if (!file.is_open())
        {
            std::cout << "wrong file path";
        }
        else
        {
            file << a.name << ' ' << a.surname << ' ' << a.money << ' ' << a.day << '.' << a.month << '.' << a.year << std::endl;
        }
    }
}

void list()
{
    std::cout << std::ifstream("statement.txt").rdbuf();
}

int main()
{
    std::string command_word;
    std::cout << "please, input the operation code list or add\n";
    std::cin>> command_word;
    if (command_word == "list")
        {
        list();
        }
    else if (command_word == "add")
        {
         append();
        }
    else
        {
        std::cout << "incorrect input";
        }
}