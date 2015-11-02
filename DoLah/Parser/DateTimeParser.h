#pragma once

#include <string>
#include <vector>
#include <regex>
#include <iterator>

#include "boost/algorithm/string/erase.hpp"

#include "ParserLibrary.h"
#include "TimeManager.h"

namespace DoLah {
    class DateTimeParser {
    public:
        DateTimeParser();
        ~DateTimeParser();

        // Converts string array into std::tm.
        // Second parameter is the lowerBound of the time.
        // By default, the current time will be used (done so inside the method).
        static std::tm toDateFormat(std::vector<std::string>, std::tm = std::tm());
        static int getDay(std::string);
        static int getMonth(std::string);
        static int getYear(std::string);
        static int getDate(std::string);
        static int getTime(std::string);
        
        static std::vector<std::string> formatArr(std::vector<std::string>);

        // Date provides an indirect indication to a certain day.
        // Add modifier to the current day to find that day.
        static int getDateModifier(int, bool);

        // Time that is relative to today such as in 10 days, in a week, tomorrow
        static int checkDateModifier(std::vector<std::string>);

        static std::tm classifyDate(std::vector<std::string>);
        // 25th December 2015
        static std::tm checkDMYformat(std::vector<std::string>);
        // December 25th 2015
        static std::tm checkMDYformat(std::vector<std::string>);
    private:
        static int REJECT;
        static std::string CENTURY;
        static int DAYINSECS;
        static int WEEKINSECS;
        static int MONTHINSECS;
        static int DEFAULT_TIME;

        // this week, next week (not implemented)
        static std::string relativePattern;
        static std::vector<std::string> datePattern;
        static std::vector<std::string> monthPattern;

        // 1st, 2nd, 3rd, 4th
        static std::string dayAppendixPattern;
        // 25th of December 2015
        static std::vector<std::string> decorators;
        // Sunday, 17th of March
        static std::vector<std::string> punctuations;
        // 25/12/2015, 25-12-2015, 25.12.2015,
        static std::vector<std::string> dateDividers;

        // today
        static std::vector<std::string> todayPattern;
        // tomorrow
        static std::vector<std::string> tomorrowPattern;
        // a week
        static std::vector<std::string> articlePattern;
        // in 10 days
        static std::vector<std::string> dayDescriptionPattern;
        // in 2 weeks
        static std::vector<std::string> weekDescriptionPattern;
        // in a month (will add 30 days per month)
        static std::vector<std::string> monthDescriptionPattern;
        // next week
        static std::vector<std::string> nextPattern;

        static std::string AM;
        static std::string PM;
        static std::string timeDivider;
    };
}