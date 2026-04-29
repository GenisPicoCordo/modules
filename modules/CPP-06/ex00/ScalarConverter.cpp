#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{ 
    (void)other; 
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(const std::string &literal)
{
    e_type type = detectType(literal);

    if (type == TYPE_CHAR)
        convertFromChar(literal);
    else if (type == TYPE_INT)
        convertFromInt(literal);
    else if (type == TYPE_FLOAT)
        convertFromFloat(literal);
    else if (type == TYPE_DOUBLE)
        convertFromDouble(literal);
    else if (type == TYPE_SPECIAL)
        convertSpecial(literal);
    else
        std::cout << "Error: invalid literal" << std::endl;
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string &literal)
{
    if (literal.empty() || !hasOnlyPrintableChars(literal))
        return (TYPE_INVALID);
    if (isSpecial(literal))
        return (TYPE_SPECIAL);
    if (isChar(literal))
        return (TYPE_CHAR);
    if (isInt(literal))
        return (TYPE_INT);
    if (isFloat(literal))
        return (TYPE_FLOAT);
    if (isDouble(literal))
        return (TYPE_DOUBLE);
    return (TYPE_INVALID);
}

bool ScalarConverter::hasOnlyPrintableChars(const std::string &literal)
{
    for (std::size_t i = 0; i < literal.length(); ++i)
    {
        if (!std::isprint(static_cast<unsigned char>(literal[i])))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isSpecial(const std::string &literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
        || literal == "-inf" || literal == "+inf" || literal == "nan");
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return (literal.length() == 1
        && !std::isdigit(static_cast<unsigned char>(literal[0])));
}

bool ScalarConverter::isInt(const std::string &literal)
{
    std::size_t i = 0;

    if (literal[i] == '+' || literal[i] == '-')
        ++i;
    if (i == literal.length())
        return (false);
    while (i < literal.length())
    {
        if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return (false);
        ++i;
    }
    return (true);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    std::size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        ++i;
    while (i < literal.length() - 1)
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return (false);
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(literal[i])))
            hasDigit = true;
        else
            return (false);
        ++i;
    }
    return (hasDot && hasDigit);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    std::size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (literal[i] == '+' || literal[i] == '-')
        ++i;
    if (i == literal.length())
        return (false);
    while (i < literal.length())
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return (false);
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(literal[i])))
            hasDigit = true;
        else
            return (false);
        ++i;
    }
    return (hasDot && hasDigit);
}

void ScalarConverter::convertFromChar(const std::string &literal)
{
    char c = literal[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
    char *end = NULL;
    errno = 0;
    long value = std::strtol(literal.c_str(), &end, 10);

    if (errno == ERANGE || value < INT_MIN || value > INT_MAX || *end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    printFromDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromFloat(const std::string &literal)
{
    char *end = NULL;
    errno = 0;
    double parsed = std::strtod(literal.c_str(), &end);

    if (errno == ERANGE || end == literal.c_str() || *end != 'f' || *(end + 1) != '\0'
        || parsed > FLT_MAX || parsed < -FLT_MAX)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    printFromDouble(static_cast<double>(static_cast<float>(parsed)));
}

void ScalarConverter::convertFromDouble(const std::string &literal)
{
    char *end = NULL;
    errno = 0;
    double value = std::strtod(literal.c_str(), &end);

    if (errno == ERANGE || end == literal.c_str() || *end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    printFromDouble(value);
}

void ScalarConverter::convertSpecial(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << toFloatSpecial(literal) << std::endl;
    std::cout << "double: " << toDoubleSpecial(literal) << std::endl;
}

void ScalarConverter::printFromDouble(double value)
{
    printChar(value);
    printInt(value);
    printFloat(static_cast<float>(value));
    printDouble(value);
}

void ScalarConverter::printChar(double value)
{
    int intValue;

    if (value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    intValue = static_cast<int>(value);
    if (intValue < 32 || intValue > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

bool ScalarConverter::isIntegerDisplay(double value)
{
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        return (false);
    return (value == static_cast<double>(static_cast<int>(value)));
}

void ScalarConverter::printFloat(float value)
{
    std::cout << "float: " << value;
    if (isIntegerDisplay(static_cast<double>(value)))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value;
    if (isIntegerDisplay(value))
        std::cout << ".0";
    std::cout << std::endl;
}

std::string ScalarConverter::toFloatSpecial(const std::string &literal)
{
    if (literal == "-inf")
        return ("-inff");
    if (literal == "+inf")
        return ("+inff");
    if (literal == "nan")
        return ("nanf");
    return (literal);
}

std::string ScalarConverter::toDoubleSpecial(const std::string &literal)
{
    if (literal == "-inff")
        return ("-inf");
    if (literal == "+inff")
        return ("+inf");
    if (literal == "nanf")
        return ("nan");
    return (literal);
}