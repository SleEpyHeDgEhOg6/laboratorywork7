#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream file(filename);
    for (auto gr : groups) {//
        file << ":" << gr.first << std::endl;
        for (auto st : gr.second) {
            file << "Группа:" << st.Name << std::endl;
            file << "Имя:" << st.Year << std::endl;
            file << "Оценки по предметам: ";
            for (auto ki : st.RecordBook) {
                file << " " << ki.first << ": " << ki.second << std::endl;
            }
        }
    }
    file.close();
}

int main1() {//для saveToFile
    Groups groups = {
        {"Group1", {{"StudentA", 2020, {{"Math", Good}, {"PE", Excellent}}}, {"StudentB", 2020, {{"Math", Satisfactorily}, {"PE", Good}}}}},
        {"Group2", {{"StudentC", 2029, {{"Math", Excellent}, {"PE", Good}}}, {"StudentD", 2029, {{"Math", Satisfactorily}, {"PE", Unsatisfactorily}}}}},
        {"Group3",{{"StudentE",2045,{{"Math",Unsatisfactorily},{"PE",Good}}},{"StudentF",2045,{{"Math",Excellent},{"PE",Good}}}}}
    };
    std::ofstream fr;
    fr.open("lab73.txt");
    saveToFile("lab73.txt", groups);
    fr.close();
    return 0;
}


