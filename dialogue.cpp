#include <iostream>
#include <string>
// Class Personnages
class Characters {
    public:
        std::string name;
        Characters(std::string name) : name(name)
    {}
        void talk(std:: string dialogue) {
            std::cout << name << ": " << dialogue << std::endl;
        }
};

int main(){
    Characters characters ("Hiloul");
    characters.talk("Coucou ! Je test le C++");
        return 0;
}