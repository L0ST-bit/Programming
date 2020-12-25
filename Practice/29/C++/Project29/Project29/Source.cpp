#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include "Header.h"

using namespace std;

struct Studennt {
    map<string, int> exams;
    string sName;
    int sgroup;
    Student(string Name, int group, int math, int phys, int hist, int prog) {
        exams = { {"math", math},{"phys", phys},{"hist", hist},{"prog", prog} };
        sName = Name;
        sgroup = group;
};
    ostream& operator << (ostream& out, const :vector<Student>& student_vec)
    {
        auto name_len = student_vec.at(0).data_name.length();
        for (auto itr = student_vec.begin() + 1; itr != student_vec.end(); ++itr)
        {
            if (itr->data_name.length() > name_len)
            {
                name_len = itr->data_name.length();
            }
        }
        auto name_delim = string(name_len, '-');
        out << "+-" << name_delim << "-+-------+------+------+------+------+\n"
            << "| Name " << string(name_len - 4, ' ')
            << "| Group | Math | Phys | Hist | Prog |\n"
            << "+-" << name_delim << "-+-------+------+------+------+------+\n";

        for (auto& student : student_vec)
        {
            out << "| " << student.data_name
                << string(name_len - student.data_name.length(), ' ')
                << " | " << student.data_group
                << "     | " << student.data_exams.at("math")
                << "    | " << student.data_exams.at("phys")
                << "    | " << student.data_exams.at("hist")
                << "    | " << student.data_exams.at("prog")
                << "    |\n"
                << "+-" << name_delim << "-+-------+------+------+------+------+\n";
        }
        return out;
    };


    int main() {
        srand(time(0));
        vector<Student> students = {
                                        Student("Molecula C",      2, 4, 2, 4, 1),
                                        Student("Art K",           3, 2, 5, 5, 4),
                                        Student("Araragi K",       4, 5, 2, 5, 5),
                                        Student("Mishima N",       5, 2, 3, 3, 4),
                                        Student("Hoin K",          8, 4, 4, 5, 5),
                                        Student("Kequing S",       7, 4, 5, 4, 3),
                                        Student("Cyber P",         6, 4, 4, 3, 5),
                                        Student("SonJinVU",        1, 1, 1, 3, 4),
                                        Student("LiMInSon",        9, 5, 1, 3, 3),
                                        Student("ChhaHeIn",        0, 3, 1, 4, 2) };