#include <iostream>
#include <vector>
#include <list>
#include <originator.h>

class Armazena {
    private:
        vector<Memento *> mementos_;
        originator *originator_;

    public:
        Armazena();
        ~Armazena();
        void backup();
        void undo();
        void historico();

};
