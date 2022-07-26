/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** main
*/

#include "Gps.hpp"

static void printUsage()
{
    std::cout << "\nUSAGE\n\t./autoCompletion dictionary\n" << std::endl;
    std::cout << "DESCRIPTION\n\tdictionary\tfile containing one address per line, as knowledge base\n" << std::endl;

}

int main(int argc, char *argv[])
{
    Gps core = Gps();
    try
    {
        errorHandling(argc, argv);
        if (std::strcmp(argv[1],"-h") == 0) {
            printUsage();
            return (0);
        }
        if (loadFile(argv[1], &core) == 1)
            return (0);
        coreLoop(core);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        return (84);
    }
    return 0;
}
