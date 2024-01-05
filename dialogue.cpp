#include <iostream>
#include <string>
#include <vector>

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
    std::string getAnswer(std::vector<std::string> options)
    {
        std::cout << name << ", que reponds tu ?" << std::endl;
        for (int i = 0; i < options.size(); ++i)
        {
            std::cout << i + 1 << ". "
                      << options[i] << std::endl;
        }
        std::string answer;
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
    // boucle
    while (true)
    {
        // Appel d'une methode pour afficher le dialogue
        hiloul.talk("Coucou ! Comment tu vas ?");

        // Choisir sa réponse
        std::vector<std::string> options = {"Je vais super bien !", "Bof, ça ne va pas", "Je ne sais pas"};
        std::string answerAdel = adel.getAnswer(options);
        if (answerAdel == "1")
        {
            adel.talk("Je vais super bien !");
            hiloul.talk("Tant mieux, je suis heureuse !");
            // Sort de la boucle en cas de réponse valide
            break;
        }
        else if (answerAdel == "2")
        {
            adel.talk("Bof, ça ne va pas");
            hiloul.talk("Oh non que puis-je faire pour toi ?");
            break;
        }
        else
        {
            hiloul.talk("Mauvaise reponse: Coucou ! Comment tu vas ?");
        }
    }

// Je met ca pour tester le programme.exe sinon disparait hors de while
#ifdef _WIN32
    Sleep(5000); // Délai en millisecondes sur Windows
#endif
    return 0;
}