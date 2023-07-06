// tp n 10.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <sstream>

std::string ComprimirFrase(const std::string& frase) {
    std::string frase_comprimida = "";
    int contador = 1;

    for (int i = 0; i < frase.length(); ++i) {
        // Comprobar si el carácter actual es igual al siguiente
        if (i + 1 < frase.length() && frase[i] == frase[i + 1]) {
            contador += 1;
        } else {
            // Agregar el carácter y su contador a la frase comprimida
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
        // Obtener el carácter actual
        char caracter = frase[i];

        // Obtener el número de repeticiones del carácter
        std::stringstream ss;
        i += 1;

        while (i < frase.length() && isdigit(frase[i])) {
            ss << frase[i];
            i += 1;
        }

        int contador;
        ss >> contador;

        // Agregar el carácter repetido a la frase descomprimida
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

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
