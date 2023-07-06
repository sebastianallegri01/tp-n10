#include <iostream>
#include <string>
#include <sstream>

std::string ComprimirFrase(const std::string& frase) {
    std::string frase_comprimida = "";
    int contador = 1;

    for (int i = 0; i < frase.length(); ++i) {
        // Comprobar si el carÃ¡cter actual es igual al siguiente
        if (i + 1 < frase.length() && frase[i] == frase[i + 1]) {
            contador += 1;
        } else {
            // Agregar el carÃ¡cter y su contador a la frase comprimida
            frase_comprimida += frase[i] + std::to_string(contador);
            contador = 1;
        }
    }

    return frase_comprimida;
}

std::string DescomprimirFrase(const std::string& frase) {
    std::string frase_descomprimida = "";
    int i = 0;

    while (i < frase.length()) {
        // Obtener el carÃ¡cter actual
        char caracter = frase[i];

        // Obtener el nÃºmero de repeticiones del carÃ¡cter
        std::stringstream ss;
        i += 1;

        while (i < frase.length() && isdigit(frase[i])) {
            ss << frase[i];
            i += 1;
        }

        int contador;
        ss >> contador;

        // Agregar el carÃ¡cter repetido a la frase descomprimida
        frase_descomprimida.append(contador, caracter);
    }

    return frase_descomprimida;
}

int main() {
    // Frase de ejemplo
    std::string frase = "AAABBBCCCDDD";

    // Comprimir la frase
    std::string frase_comprimida = ComprimirFrase(frase);

    // Descomprimir la frase comprimida
    std::string frase_descomprimida = DescomprimirFrase(frase_comprimida);

    // Concatenar ambas funciones en la frase final
    std::string frase_final = frase + frase_comprimida + frase_descomprimida;

    // Mostrar la frase final
    std::cout << frase_final << std::endl;

    return 0;
}
