#include <iostream>
#include <fstream>
#include <string>

// Construye un nuevo string con todas las apariciones de s1 sustituidas por s2,
// usando SOLO find/append/substr, NO string::replace.
static std::string replaceAll_noReplace(const std::string& text, const std::string& s1, const std::string& s2) {
    
    if (s1.empty() || s1 == s2) 
        return text;

    std::string result;
    result.reserve(text.size()); // micro-optimización

    std::string::size_type prev = 0;
    std::string::size_type pos;

    while ((pos = text.find(s1, prev)) != std::string::npos) {
        // tramo previo a la coincidencia
        result.append(text, prev, pos - prev);
        // sustitución
        result.append(s2);
        // saltar s1 encontrada
        prev = pos + s1.size();
    }
    // resto del texto
    result.append(text, prev, std::string::npos);
    return result;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty.\n";
        return 2;
    }

    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
    if (!in) {
        std::cerr << "Error: could not open input file: " << filename << "\n";
        return 3;
    }
    // Leer todo el archivo preservando bytes y saltos de línea
    std::string content((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    in.close();

    std::string replaced = replaceAll_noReplace(content, s1, s2);

    std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
    if (!out) {
        std::cerr << "Error: could not create output file: "
                  << filename << ".replace\n";
        return 4;
    }
    out << replaced;
    out.close();
    return 0;
}
