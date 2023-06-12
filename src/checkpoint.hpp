#include <iostream>
#include <time.h>
#include "memento.hpp"
#include "fachada.h"
using namespace std;
class checkpoint : public Memento {
	private:
		fachada state_;
		string info_;
	public:
		checkpoint(fachada state);
		string nome() const override;
		string info() const override;
		fachada state() const override;
};
