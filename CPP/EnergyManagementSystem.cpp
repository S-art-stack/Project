#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
#include "element.h"

// pre declaration
void gui_line_divider();
void handle_invalid_input();
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
            else
                break;
        }
        if (program_close)
            break;
        // update section
        while (true)
        {
            std::cout << "Choose an option to update:\n";
            std::vector<std::string> v = {"Light ON/OFF", "Shading ON/OFF", "Fan ON/OFF", "Change Temperature", "Number of People in room: "};
            for (short i = 0; i < (short)v.size(); i++)
                std::cout << i + 1 << ". " << v[i] << '\n';
            std::cout << ": ";
            std::cin >> opt;
            if (std::cin.fail())
            {
                // handling wrong input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // show error message
                std::cout << "Wrong opt. Press (1-" << (short)v.size() << ")!\n";
            }
            else if (opt >= 1 && opt <= (short)v.size())
                break;
            else
                std::cout << "Wrong opt. Press (1-" << (short)v.size() << ")!\n";
        }

        // update process
        // light
        if (opt == 1)
        {
            while (true)
            {
                std::cout << "Choose an option:\n\t1. Light ON\n\t2. Light OFF\n\t: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! Press 1/2\n";
                }
                else if (opt >= 1 && opt <= 2)
                {
                    // light on
                    if (opt == 1)
                    {
                        if (element.get("Light").first == true)
                        {
                            std::cout << "Light already on.\n";
                        }
                        else
                        {
                            // turning on light
                            element.set("Light", {true, -1});
                            std::cout << "Light ON Successfully.\n";
                        }
                    }
                    // light off
                    else
                    {
                        if (element.get("Light").first == false)
                        {
                            std::cout << "Light already off.\n";
                        }
                        else
                        {
                            // truning off light
                            element.set("Light", {false, -1});
                            std::cout << "Light ON Successfully.\n";
                        }
                    }
                    break;
                }
                else
                {
                    std::cout << "Wrong option! Press 1/2\n";
                }

            }
        }
        // // shading
        // else if (opt == 2)
        // {
        // }
        // // fan
        // else if (opt == 3)
        // {
        // }
        // // temperature
        // else if (opt == 4)
        // {
        // }
        // // people
        // else if (opt == 5)
        // {
        // }
    }
    return 0;
}

// defination

void gui_line_divider()
{
    for (short i = 0; i < 10; i++)
    {
        std::cout << "- ";
    }
    std::cout << "\n";
}

void handle_invalid_input()
{
    // handling wrong input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showstatus(Element element)
{
    std::map<std::string, std::pair<bool, short>> mp = element.getall();
    for (auto pr : mp)
    {
        std::cout << "* " << pr.first << ": ";
        if (pr.second.first)
        {
            std::cout << "ON\n";
        }
        else
            std::cout << "OFF\n";
    }
}