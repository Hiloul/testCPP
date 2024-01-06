#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

class Characters
{
public:
    std::string name;
    int pointsRelationship;

    Characters(std::string name) : name(name), pointsRelationship(0) {}

    void talk(std::string dialogue)
    {
        std::cout << name << ": " << dialogue << std::endl;
    }

    std::string getAnswer(std::vector<std::string> options)
    {
        std::cout << name << ", que reponds tu ?" << std::endl;
        for (int i = 0; i < options.size(); ++i)
        {
            std::cout << i + 1 << ". " << options[i] << std::endl;
        }
        std::string answer;
        std::getline(std::cin, answer);
        return answer;
    }

    void adjustPointsRelationship(int points)
    {
        pointsRelationship += points;
        if (pointsRelationship > 10)
        {
            pointsRelationship = 10;
        }
        else if (pointsRelationship < -10)
        {
            pointsRelationship = -10;
        }
    }
};

// Fonction pour jouer à Pierre-Papier-Ciseaux
void playRockPaperScissors(Characters &player1, Characters &player2)
{
    std::vector<std::string> rpsOptions = {"Pierre", "Feuille", "Ciseaux"};
    std::cout << "Choisissez une option :\n";
    for (int i = 0; i < rpsOptions.size(); ++i)
    {
        std::cout << i + 1 << ". " << rpsOptions[i] << std::endl;
    }

    int choice;
    std::cout << "Votre choix : ";
    std::cin >> choice;

    // Génération aléatoire du choix de l'ordinateur (Carlos)
    int computerChoice = rand() % rpsOptions.size() + 1;

    std::cout << player1.name << " a choisi " << rpsOptions[choice - 1] << std::endl;
    std::cout << player2.name << " a choisi " << rpsOptions[computerChoice - 1] << std::endl;

    // Logique du jeu
    if (choice == computerChoice)
    {
        std::cout << "Égalité !" << std::endl;
    }
    else if ((choice == 1 && computerChoice == 3) ||
             (choice == 2 && computerChoice == 1) ||
             (choice == 3 && computerChoice == 2))
    {
        std::cout << player1.name << " remporte la partie !" << std::endl;
        player1.adjustPointsRelationship(1);
    }
    else
    {
        std::cout << player2.name << " remporte la partie !" << std::endl;
        player2.adjustPointsRelationship(1);
    }
}

int main()
{
    Characters gabrielle("Gabrielle");
    Characters carlos("Carlos");

    // Conversation initiale
    gabrielle.talk("Bonjour Carlos ! Comment ça va ?");
    carlos.talk("Salut Gabrielle ! Ça va bien, merci.");

    // Troisième question de Gabrielle
    std::string answer = gabrielle.getAnswer({"Oui", "Non", "Je sais pas"});
    if (answer == "Oui")
    {
        // Carlos peut répondre "Oui" ou "Non" comme les précédentes questions
        std::string carlosAnswer = carlos.getAnswer({"Oui", "Non", "Je sais pas"});
        if (carlosAnswer == "Oui")
        {
            // Lancer le mini-jeu de Pierre-Papier-Ciseaux
            playRockPaperScissors(gabrielle, carlos);
        }
        else if (carlosAnswer == "Non")
        {
            gabrielle.talk("Oh, dommage. Une autre fois peut-être.");
        }
        else
        {
            gabrielle.talk("Tu ne veux pas jouer ? Peut-être une prochaine fois.");
        }
    }
    else
    {
        gabrielle.talk("D'accord, peut-être une autre fois.");
    }

#ifdef _WIN32
    system("pause");
#endif

    return 0;
}
