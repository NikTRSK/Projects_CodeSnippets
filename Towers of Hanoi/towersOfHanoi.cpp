// Basic recursive implementation of towersOfHanoi

#include <iostream>

void printInstructions(int from, int to) {
	std::cout << "Move top disk from " << from << " to " << to << "." << std::endl;
}

void solveTowers(int numItems, int from, int to, int spare) {
	if (numItems == 1)
		printInstructions(from, to);
	else {
		solveTowers(numItems-1, from, spare, to);
		solveTowers(1, from, to, spare);
		solveTowers(numItems-1, spare, to, from);
	}
}

int main() {
	solveTowers(10, 2, 1, 3);

	return 0;
}