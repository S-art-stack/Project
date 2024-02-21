#include <iostream>
#include <stdexcept>
#include <limits>
#include "element.h"

// pre declaration
void showstatus(Element element);

int main()
{
    std::cout << "----- Smart Building Energy Management System -----\n";
    bool program_close = false;
    Element element;
    while (true)
    {
        std::cout << "Status\n";
        showstatus(element);
        short opt;
        while (true)
        {
            std::cout << "Choose an option\nPress 1[Update]/Press 0[Exit]:";
            std::cin >> opt;
            if (std::cin.fail() || (opt != 1 && opt != 0))
            {
                // handling wrong input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Wrong option. (1 or 0)!\n";
            }
            else if (opt == 0)
            {
                // shut down the system
                std::cout << "System is turned of!\n";
                program_close = true;
                break;
            }
        }
        if (program_close)
            break;
        // update section
        
    }
    return 0;
}

// defination
void showstatus(Element element)
{
    std::map<std::string, std::pair<bool, short>> mp = element.getall();
    for (auto pr : mp)
    {
        std::cout << "* " << pr.first << ": ";
        if (pr.second.first)
        {
            std::cout << "ON [" << pr.second.second << "]\n";
        }
        else
            std::cout << "OFF\n";
    }
}