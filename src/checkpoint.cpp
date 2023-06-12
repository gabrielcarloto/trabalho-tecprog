#include <iostream>
#include <string>
#include "checkpoint.hpp"
using namespace std;
checkpoint(fachada state): state_(state) {
    this->state_ = state;
    time_t now = time(0);
    this->info_ = ctime(&now);
}
fachada* checkpoint::state() {
	return this->state_;
}
string checkpoint::nome() {
	return info_;
}
string checkpoint::info() {
	return this->info_;
}
