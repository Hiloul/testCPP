#include <iostream>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h> // Pour Sleep sur Windows
#endif

int main() {
    // Affiche "Hello, World!"
    std::cout << "Hello, World!" "HOW ARE YOU" << std::endl;

    // Ajoute un délai de 5 secondes (vous pouvez ajuster la durée selon vos besoins)
#ifdef _WIN32
    Sleep(5000); // Délai en millisecondes sur Windows
#endif

    // Termine le programme
    return 0;
}
