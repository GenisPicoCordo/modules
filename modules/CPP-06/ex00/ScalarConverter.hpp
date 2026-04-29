#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cerrno>
# include <cctype>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);

        enum e_type
        {
            TYPE_CHAR,
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_DOUBLE,
            TYPE_SPECIAL,
            TYPE_INVALID
        };

        static e_type      detectType(const std::string &literal);
        static bool        isSpecial(const std::string &literal);
        static bool        isChar(const std::string &literal);
        static bool        isInt(const std::string &literal);
        static bool        isFloat(const std::string &literal);
        static bool        isDouble(const std::string &literal);
        static bool        hasOnlyPrintableChars(const std::string &literal);

        static void        convertFromChar(const std::string &literal);
        static void        convertFromInt(const std::string &literal);
        static void        convertFromFloat(const std::string &literal);
        static void        convertFromDouble(const std::string &literal);
        static void        convertSpecial(const std::string &literal);

        static void        printFromDouble(double value);
        static void        printChar(double value);
        static void        printInt(double value);
        static void        printFloat(float value);
        static void        printDouble(double value);
        static bool        isIntegerDisplay(double value);
        static std::string toFloatSpecial(const std::string &literal);
        static std::string toDoubleSpecial(const std::string &literal);

    public:
        static void        convert(const std::string &literal);
};

#endif