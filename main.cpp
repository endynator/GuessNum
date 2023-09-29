#include <iostream>
#include <random>
#include <SFML/Audio.hpp>

using namespace std;

int randInt() {
	random_device truly_random_seed;
	default_random_engine dank_engine(truly_random_seed());
	uniform_int_distribution<int> distribution(1, 10);
	return distribution(dank_engine);
}

int main() {
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;

	if (!buffer1.loadFromFile("succes.OGG")) {
		cout << "Unable to find file.";
	}
	if (!buffer2.loadFromFile("fail.OGG")) {
		cout << "Unable to find file.";
	}
	sf::Sound win, fail;
	win.setBuffer(buffer1);
	fail.setBuffer(buffer2);

	int n = -1, randNum = randInt();
	do {
		cout << "Guess the number: "; cin >> n;
		if (n == randNum) {
			win.play();
			cout << "You guessed the number.";
		}
		else {
			fail.play();
		}
	} while (true);
	
	return 0;
}
