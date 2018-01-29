#include <iostream>
#include <string>
#include "MysteryDuck.h"

MysteryDuck::MysteryDuck(std::string description, std::string sound): Duck() {
	this->description = description;
	this->sound = sound;
}

void MysteryDuck::performQuack() {
	std::cout << this->sound << std::endl;
}

std::string MysteryDuck::getDescription() {
	return this->description;
}
