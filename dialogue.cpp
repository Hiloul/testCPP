#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h> // Pour Sleep sur Windows
#endif

// Class Personnages
class Characters
{
public:
    std::string name;
    // Introduction de la variable relation
    int pointsRelationship;

    // Constructeur pour intitialiser le nom du personnage
    Characters(std::string name) : name(name), pointsRelationship(0) {}

    // Methode pour faire parler le personnage
    void talk(std::string dialogue)
    {
        std::cout << name << ": " << dialogue << std::endl;
    }

    // Fonction pour choisir la réponse parmi les options
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

    // Fonction pour ajuster les points en fonction de la 2éme question
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
    int player1Score = 0;
    int player2Score = 0;

    while (player1Score < 3 && player2Score < 3)
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

        // Génération aléatoire du choix de l'ordinateur (Adel)
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
            player1Score++;
        }
        else
        {
            std::cout << player2.name << " remporte la partie !" << std::endl;
            player2Score++;
        }
    }

    // Afficher le gagnant de la partie
    std::cout << std::endl
              << std::endl;

    if (player1Score > player2Score)
    {
        std::cout << player1.name << " remporte la partie avec un score de " << player1Score << " à " << player2Score << " !" << std::endl;
    }
    else if (player1Score < player2Score)
    {
        std::cout << player2.name << " remporte la partie avec un score de " << player2Score << " à " << player1Score << " !" << std::endl;
    }
    else
    {
        std::cout << "La partie se termine par une égalité avec un score de " << player1Score << " à " << player2Score << " !" << std::endl;
    }
    
    std::cout << std::endl
              << std::endl;
}

// Fonction principale
int main()
{
    // Titre
    std::cout << "Bienvenue dans ce mini jeu !" << std::endl;

    // Ajouter une ligne vide
    std::cout << std::endl
              << std::endl;

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

    // Ajouter une ligne vide
    std::cout << std::endl
              << std::endl;

    // 2ème question
    while (true)
    {
        hiloul.talk("Est-ce que tu me trouves jolie aujourd'hui ?");

        // Choisir sa réponse
        std::vector<std::string> options2 = {"Oui youhou !", "Non beurk !", "autre"};
        std::string answerAdel2 = adel.getAnswer(options2);
        if (answerAdel2 == "1")
        {
            adel.talk("Oui tu est très belle !");
            hiloul.talk("Merci beaucoup ca me fait plaisir !");
            adel.adjustPointsRelationship(1);
            // break;
        }
        else if (answerAdel2 == "2")
        {
            adel.talk("Non beurk !");
            hiloul.talk("Oh ok tant pis...");
            adel.adjustPointsRelationship(-1);
            // break;
        }
        else
        {
            hiloul.talk("Pas compris ta réponse tu me trouvais jolie ? ?");
        }
        // Correction ici : ajout de la virgule
        hiloul.talk("Points de relation avec Adel: " +
                    std::to_string(adel.pointsRelationship));
        break;
    }

    // Ajouter une ligne vide
    std::cout << std::endl
              << std::endl;

    // Troisième question
    while (true)
    {
        hiloul.talk("Est-ce que tu veux jouer ?");

        // Choisir sa réponse
        std::vector<std::string> options3 = {"Oui je veux jouer !", "Non merci !", "je ne sais pas"};
        std::string answerAdel3 = adel.getAnswer(options3);
        if (answerAdel3 == "1")
        {
            // Lancer le mini-jeu de Pierre-Papier-Ciseaux
            playRockPaperScissors(hiloul, adel);
        }
        else if (answerAdel3 == "2")
        {
            adel.talk("Non merci !");
            hiloul.talk("Oh ok tant pis...");
            adel.adjustPointsRelationship(-1);
            break;
        }
        else
        {
            hiloul.talk("Pas compris ta réponse tu veux jouer ?");
        }
    }

    // Je met ca pour tester le programme.exe sinon disparait hors de while
#ifdef _WIN32
    Sleep(5000); // Délai en millisecondes sur Windows
#endif
    return 0;
}
