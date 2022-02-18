#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>

using namespace std;

class Ticket {
public:
    Ticket() {
        this->cityName = "";
        this->destination = nullptr;
        this->lastVisited = nullptr;
    }

    ~Ticket(){
        Ticket * temp = this->lastVisited;
        while (temp->lastVisited != nullptr) {
            temp = temp->lastVisited;
        }
        while (temp != nullptr) {
            Ticket* temp1 = temp->destination;
            delete temp;
            temp = temp1;
        }
    }

    string cityName;
    Ticket *destination{};
    Ticket *lastVisited{};
};

class TicketList {
public:
    Ticket *head;
    void checkHead() {
        while (head->lastVisited != nullptr) {
            head = head->lastVisited;
        }
    }
};

vector<string> strToVector(const string &str, char del = ' ') {
    vector<string> result;
    string temp;
    stringstream stream(str);
    while (getline(stream, temp, del)) {
        result.push_back(temp);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string a;
    getline(cin, a);
    std::map<std::string, Ticket*> tickets;
    TicketList ticketsList{};

    for (int i = 0; i < n; ++i) {
        getline(cin, a);
        vector<string> temp1 = strToVector(a, ' ');
        Ticket *temp2 = tickets[temp1.at(0)];
        Ticket *temp = tickets[temp1.at(1)];
//        for (auto & ticket : tickets) {
//            if (ticket->cityName == temp1.at(0)) {
//                temp2 = ticket;
//            }
//            if (ticket->cityName == temp1.at(1)) {
//                temp = ticket;
//            }
//            if (ticket->lastVisited == nullptr) {
//                ticketsList.head = ticket;
//            }
//        }
        if (temp2 == nullptr) {
            temp2 = new Ticket();
            temp2->cityName = temp1.at(0);
            temp2->destination = nullptr;
            temp2->lastVisited = nullptr;
            tickets[temp2->cityName] = temp2;
        }
        if (temp != nullptr) {
            temp2->destination = temp;
            temp->lastVisited = temp2;
            ticketsList.head = temp2;
        } else {
            auto * temp3 = new Ticket();
            temp2->destination = temp3;
            temp3->cityName = temp1.at(1);
            temp3->lastVisited = temp2;
            tickets[temp3->cityName] = temp3;
            ticketsList.head = temp2;
        }
    }
    ticketsList.checkHead();
    Ticket* temp = ticketsList.head;
    while (temp != nullptr) {
        cout << temp->cityName << " ";
        temp = temp->destination;
    }
    return 0;
}