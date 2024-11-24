#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

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


enum Score {
    Unsatisfactory = 2,
    Satisfactory,
    Good,
    Excellent
};

struct Student {
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::ifstream file(filename);
    std::string rt, gr;//переменные,которые будут хранить текущую строку 
    while (std::getline(file, rt)) {
        if (isupper(rt[0])){//isupper проверяет заглавная это буква или нет,если да,то это название группы,а если нет,то информация о учащемся  
            gr = rt;//присваиваем текущую группу 
            outGroups[gr];//создаем новую группу
        }
        else {
            std::istringstream ft(rt);//создает поток для данных из строки 
            Student stu;//переменная stu,которая берет данные из struct Book
            std::string sub;//переменная для хранения названия предметов 
            ft >> stu.Name >> stu.Year;//считывает имя учащегося и год
            while (ft >> sub) {//считывает пока там что-то есть
                int sc;
                ft >> sc;//считывает оценку для текущего учащегося и предмета
            }
            outGroups[gr].push_back(stu);
        }
    }
    file.close();
}

int main2() {//для loadFromFile
    Groups group;
    std::ifstream yt;
    yt.open("lab733.txt");
    loadFromFile("lab733.txt", group);
    for (auto q : group) {
        std::cout << "Group:" << q.first << std::endl;
        for (auto q1 : q.second) {
            std::cout << "Name" << q1.Name << std::endl;
            for (auto q2 : q1.RecordBook) {
                std::cout << q2.first << q2.second << std::endl;
            }
        }
    }
    yt.close();
    return 0;
}

