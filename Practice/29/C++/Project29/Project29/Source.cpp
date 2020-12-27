#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>


using namespace std;

struct Student{
    string StNames;
    int group;
    map<string, int> marks;
};

bool operator > (Student first, Student second){
    return first.StNames > second.StNames;
}

ostream& operator<<(ostream& print, vector<Student> dwoech_list){
    print << "+-------------+-------+------+------+------+------+" << endl
          << "| Name        | Group | Math | Phys | Hist | Prog |" << endl
          << "+-------------+-------+------+------+------+------+" << endl;
    for (auto student : dwoech_list){
    print << "|" << student.StNames << setw(14 - student.StNames.length())
          << "|" << student.group << setw(7)
          << "|" << student.marks["math"] << setw(6)
          << "|" << student.marks["phys"] << setw(6)
          << "|" << student.marks["hist"] << setw(6)
          << "|" << student.marks["prog"] << setw(6)       << "|" << endl
          << "+-------------+-------+------+------+------+------+" << endl;
    }

    return print;
}

ostream& operator<<(ostream& print, Student dwoech_list){
    print << "+-------------+-------+------+------+------+------+" << endl
          << "| Name        | Group | Math | Phys | Hist | Prog |" << endl
          << "+-------------+-------+------+------+------+------+" << endl
          << "|" << dwoech_list.StNames << setw(14 - dwoech_list.StNames.length())
          << "|" << dwoech_list.group << setw(7)
          << "|" << dwoech_list.marks["math"] << setw(6)
          << "|" << dwoech_list.marks["phys"] << setw(6)
          << "|" << dwoech_list.marks["hist"] << setw(6)
          << "|" << dwoech_list.marks["prog"] << setw(6)   << "|" << endl
          << "+-------------+-------+------+------+------+------+" << endl;

    return print;
}



template <class T>
vector<T> BozoSort(vector <T> type1, bool check = true) {
    int a = 0, random1, random2;
    int n = type1.size();
    if (check) {
        while (!check) {
            for (int i = 0; i < n; i++) {
                random1 = rand() % n;
                random2 = rand() % n;
                T a = type1[random1];
                type1[random1] = type1[random2];
                type1[random2] = a;

                check = true;

                for (int i = 1; i < n; i++)
                {
                    if (type1[i - 1] > type1[i])
                    {
                        check = false;
                        break;
                    }
                }
            }
            
        }
        return type1;
    }
}

    int main() {
        srand(time(NULL));
        vector<Student> students, dwoech_list;
        students = {
            {"Molecula C",      2,   {{"math",4}, {"phys",2}, {"hist",4}, {"prog",1}} },
            {"Art K",           3,   {{"math",2}, {"phys",5}, {"hist",5}, {"prog",4}} },
            {"Parovozov A",     4,   {{"math",5}, {"phys",2}, {"hist",5}, {"prog",5}} },
            {"Petrov K",        5,   {{"math",2}, {"phys",3}, {"hist",3}, {"prog",4}} },
            {"Chebel A",        8,   {{"math",4}, {"phys",4}, {"hist",5}, {"prog",5}} },
            {"Kequing S",       7,   {{"math",4}, {"phys",5}, {"hist",4}, {"prog",3}} },
            {"Cyber P",         6,   {{"math",4}, {"phys",4}, {"hist",3}, {"prog",5}} },
            {"Strizh D",        1,   {{"math",1}, {"phys",1}, {"hist",3}, {"prog",4}} },
            {"Smirnov I",       9,   {{"math",5}, {"phys",1}, {"hist",3}, {"prog",3}} },
            {"Antonov M",       0,   {{"math",3}, {"phys",1}, {"hist",4}, {"prog",2}} } };

        int count = 0;

        for (auto dwoech : students)
        {
            for (auto mark : dwoech.marks)
            {
                if (mark.second == 2)
                {
                    count++;
                    dwoech_list.push_back(dwoech);
                    break;
                }
            }
        }

        if (count){
            cout << BozoSort(dwoech_list) << endl
                << "Expulsion\n" << endl
                << dwoech_list[rand() % dwoech_list.size()];
        }
        else 
            cout << "Not found";
    }