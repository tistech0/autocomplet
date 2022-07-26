/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** formatString
*/

#include "Gps.hpp"
#include "formatString.hpp"
#include <regex>

static bool formatComa(std::string *line)
{
    std::regex adressPattern("(^[a-zA-Z]+)\\s*([0-9]+)\\s*(boulevard|allée|allee|rue|avenue|chemin|impasse|place|quai|square)\\s*[a-zA-Z 'Ü-ü-]+$");
	std::smatch sm;
    std::string result;

    if (std::regex_match(*line, sm, adressPattern)) {
        line->insert(sm[1].str().size(), ",");
        return (true);
    }
    return (false);
}

static bool formatNumber(std::string *line)
{
    std::regex adressPattern("([^\\d]*)(\\d*)([^\\d]*)$");
	std::smatch sm;
    std::string result;

    if (std::regex_match(*line, sm, adressPattern)) {
        if (sm.size() > 2)
            *line = sm[1].str() + sm[3].str();
        line->insert(line->find(",") + 1, " " + sm[2].str());
        line->pop_back();
        return (true);
    }
    return (false);
}

static bool formatCityName(std::string *line)
{
    std::regex adressPattern("(.*)(,)[\\s]*(.*)");
	std::smatch sm;
    std::string result;

    if (std::regex_match(*line, sm, adressPattern)) {
        *line = sm[3].str() + sm[2].str() + " " + sm[1].str();
        return (true);
    }
    return (false);
}

static bool formatStreetType(std::string *line)
{
    std::regex adressPattern("([a-zA-Z,]+)[\\s*]([0-9]+)[\\s*]([a-zA-Z,]+)[\\s*](allée|avenue|boulevard|chemin|impasse|place|quai|rue|square)");
	std::smatch sm;
    std::string result;

    if (std::regex_match(*line, sm, adressPattern)) {
        *line = sm[1].str() + " " + sm[2].str() + " " + sm[4].str() + " " + sm[3].str();
        return (true);
    }
    return (false);
}

static std::string whatMiss(std::string line)
{
    std::regex adressPattern("(^[a-zA-Z ]+)[,]\\s*([0-9]+)\\s*(boulevard|allée|allee|rue|avenue|chemin|impasse|place|quai|square)\\s*[a-zA-Z 'Ü-ü-]+$");
	std::smatch sm;
    std::string lineTmp = line;

    formatCityName(&lineTmp);
    if (std::regex_match(lineTmp, sm, adressPattern))
        return ("city name");
    lineTmp = line;
    formatComa(&lineTmp);
    if (std::regex_match(lineTmp, sm, adressPattern))
        return ("coma");
    lineTmp = line;
    formatNumber(&lineTmp);
    if (std::regex_match(lineTmp, sm, adressPattern))
        return ("number");
    lineTmp = line;
    formatStreetType(&lineTmp);
    if (std::regex_match(lineTmp, sm, adressPattern))
        return ("street type");
    return (NULL);
}

void formatString(std::string *line)
{
    std::string missing = whatMiss(*line);

    if (missing == "city name" && formatCityName(line))
        return;
    if (missing == "coma" && formatComa(line))
        return;
    if (missing == "number" && formatNumber(line))
        return;
    if (missing == "street type" && formatStreetType(line))
        return;
}
