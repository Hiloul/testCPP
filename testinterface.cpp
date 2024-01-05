#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

class CharacterWindow : public QWidget {
public:
    CharacterWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Création des widgets
        characterLabel = new QLabel(this);
        dialogueLabel = new QLabel(this);
        dialogueLabel->setWordWrap(true);

        // Ajout d'une ombre à la bulle de dialogue
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
        effect->setBlurRadius(10);
        effect->setColor("#000000");
        dialogueLabel->setGraphicsEffect(effect);

        // Mise en page
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(characterLabel, 0, Qt::AlignHCenter);
        layout->addWidget(dialogueLabel, 0, Qt::AlignHCenter);
        setLayout(layout);
    }

    // Méthode pour afficher le personnage et le dialogue
    void displayCharacterAndDialogue(const QString &characterImagePath, const QString &dialogueText) {
        characterLabel->setPixmap(QPixmap(characterImagePath));
        dialogueLabel->setText(dialogueText);
    }

private:
    QLabel *characterLabel;
    QLabel *dialogueLabel;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CharacterWindow window;
    window.displayCharacterAndDialogue("path/to/character.png", "Coucou voisin, ça va ?");
    
    window.show();

    return app.exec();
}


// Il faut installer la bibliothèque Qt pour interface c++
