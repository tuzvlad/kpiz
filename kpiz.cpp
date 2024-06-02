#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Participant {
private:
    string country;
    string sport;
    string name;

public:
    Participant(const string& country, const string& sport, const string& name)
        : country(country), sport(sport), name(name) {}

    void display() const {
        setlocale(LC_CTYPE, "ukr");
        cout << "Країна: " << country << ", Вид спорту: " << sport << ", Iм'я: " << name << endl;
    }

    string getCountry() const { return country; }
    string getSport() const { return sport; }
    string getName() const { return name; }
};

void demonstrateContainerOperations() {
    vector<Participant> participants;
    setlocale(LC_CTYPE, "ukr");
    participants.emplace_back("Україна", "Бокс", "Олександр Усик");
    participants.emplace_back("США", "Плавання", "Майкл Фелпс");
    participants.emplace_back("Ямайка", "Легка атлетика", "Усейн Болт");

    cout << "Список учасникiв:" << endl;
    for (const auto& participant : participants) {
        participant.display();
    }

    string searchCountry = "США";
    cout << "\nПошук учасникiв з " << searchCountry << ":" << endl;
    for (const auto& participant : participants) {
        if (participant.getCountry() == searchCountry) {
            participant.display();
        }
    }

    string deleteName = "Усейн Болт";
    participants.erase(
        remove_if(participants.begin(), participants.end(),
            [&deleteName](const Participant& p) { return p.getName() == deleteName; }),
        participants.end()
    );

    cout << "\nСписок учасникiв пiсля видалення:" << endl;
    for (const auto& participant : participants) {
        participant.display();
    }
}

int main() {
    demonstrateContainerOperations();
    return 0;
}
