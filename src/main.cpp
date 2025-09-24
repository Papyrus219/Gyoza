#include "experiments/simple_electrostatistic_exp.hpp"
#include<string>

int main(int argv, char **argc)
{
    std::cout << "#ELECTRONS AND PROTONS REACTIONS\n";
    std::cout << "#Powered with Gyoza by: Papyrus219\n\n";

    std::string mode{};
    if(argv > 1)
        mode = argc[1];

    exp1::Start(mode);

    return 0;
}
