#ifndef LAB2_MYSTERYDUCK_H
#define LAB2_MYSTERYDUCK_H

#include <string>
#include "Duck.h"

class MysteryDuck: public Duck {
public:
	MysteryDuck(std::string description, std::string sound);
	void performQuack();
	std::string getDescription();
private:
	std::string sound;
	std::string description;
};

#endif