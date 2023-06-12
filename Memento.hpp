#include <iostream>
using namespace std;

 class Memento {
   public:
       virtual ~Memento(){};
       virtual string nome() const = 0;
       virtual string info() const = 0;
       virtual string state() const = 0;
 };


