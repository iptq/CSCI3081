#include <iostream>
#include <string>
#include "DecoyDuck.h"

DecoyDuck::DecoyDuck(): Duck() { 
}

void DecoyDuck::performQuack() {
	std::cout << "..." << std::endl;
}

std::string DecoyDuck::getDescription() {
	std::string desc = "a plastic decoy duck";
	return desc;
}