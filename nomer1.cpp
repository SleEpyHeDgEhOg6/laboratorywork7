#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
	std::ofstream file(filename);
	for (auto d : data) {
		file << d << std::endl;
	}
	file.close();
}

int main1() { // для saveToFile
	std::ofstream gh;
	gh.open("lab7.txt");
	std::vector<std::string> words = { "Скоро", "Новый", "Год", "И сессия(" };
	saveToFile("lab7.txt", words);
	gh.close();
	return 0;
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
	std::ifstream file(filename);
	std::string ch;
	while (std::getline(file, ch)) {
		outData.push_back(ch);
	}
	file.close();
}

int main2() {//для loadFromFile
	std::vector<std::string>otvet;
	loadFromFile("lab71.txt", otvet);
	for (auto fg : otvet) {
		std::cout << fg << std::endl;
	}
	return 0;
}
