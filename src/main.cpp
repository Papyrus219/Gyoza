#include "experiments/simple_electrostatistic_exp.hpp"
#include<string>

int main()
{
    std::cout << "#ELECTRONS AND PROTONS REACTIONS\n";
    std::cout << "#Powered with Gyoza by: Papyrus219\n\n";

    std::cout << "#Modes: T-Text setup mode | M-Mouse setup mode\n";
    std::cout << "#Chouse mode: \n";

    char mode{};
    std::string buffor{};
    std::cin >> mode;       std::getline(std::cin, buffor);

    exp1::Start(mode);

    return 0;
}
