#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Book
{
	std::string Author;
	std::string Title;
	int Year;
};

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
	std::ofstream file(filename);
	for (auto book : data) {
		file << book.Author << endl;
		file << book.Title << endl;
		file << book.Year << endl;
	}
	file.close();
}

int main1() {//для saveToFile
	setlocale(LC_ALL, "RU");
	std::ofstream gh;
	gh.open("lab72.txt");
	std::vector<Book> Books = {
		{"Достоевский","Игрок",1866},
		{"Мандельштам","Ленинград",1932},
		{"Ахматова","Сероглазый Король",1910}
	};
	saveToFile("lab72.txt", Books);
	gh.close();
	return 0;
}

void loadFromFile(const std::string filename, std::vector<Book> outData) {
	std::ifstream file(filename);
	Book fg;//переменная fg,которая берет данные из struct Book 
	int ind = 0;
	while (std::getline(file, fg.Author)) {
		if (!std::getline(file, fg.Title)) {//считывает название книги и если не получится,то прервет 
			break;
		}
		if (!(file >> fg.Year)) {//считывает год,а если это конец файла,то прервет 
			break;
		}
	}
	outData.push_back(fg);
}

int main2() {//для loadFromFile
	std::vector<Book> Books;
	std::ifstream hj;
	hj.open("lab722.txt");
	loadFromFile("lab722.txt", Books);
	for (auto book : Books) {
		std::cout << "Автор: " << book.Author << ", Заголовок: " << book.Title << ", Год: " << book.Year << std::endl;
	}
	hj.close();
	return 0;
}
