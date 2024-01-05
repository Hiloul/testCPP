#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h> // Pour Sleep sur Windows
#endif

// Class Personnages
class Characters
{
public:
    std::string name;
    // Constructeur pour intitialiser le nom du personnage
    Characters(std::string name) : name(name)
    {
    }
    // Methode pour faire parler le personnage
    void talk(std::string dialogue)
    {
        std::cout << name << ": " << dialogue << std::endl;
    }
    // Fonction Pour obtenir la réponse du personnage
    std::string getAnswer()
    {
        std::string answer;
        std::cout << name << ", que reponds tu ?";
        std::getline(std::cin, answer);
        return answer;
    }
};

// Fonction principale
int main()
{
    // Création d'objet de la class Characters avec des noms
    Characters hiloul("Hiloul");
    Characters adel("Adel");
    // Appel d'une methode pour afficher le dialogue
    hiloul.talk("Coucou ! Je test le C++");
    // Chosiir sa réponse
    std::string answerAdel = adel.getAnswer();
    if (answerAdel == "1"){
        adel.talk("Oui");
    } else if(answerAdel == "2"){
        adel.talk("Non");
    } else {
        adel.talk("Mauvaise reponse");
    }

    // Je met ca pour tester le programme.exe sinon disparait
    #ifdef _WIN32
    Sleep(5000); // Délai en millisecondes sur Windows
    #endif
    return 0;
}