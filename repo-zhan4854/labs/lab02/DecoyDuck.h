#ifndef LAB2_DECOYDUCK_H
#define LAB2_DECOYDUCK_H

#include <string>
#include "Duck.h"

class DecoyDuck: public Duck {
public:
	DecoyDuck();
	void performQuack();
	std::string getDescription();
};

#endif