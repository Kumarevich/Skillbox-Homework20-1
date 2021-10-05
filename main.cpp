#include <iostream>
#include <fstream>
#include <string>

void check_date (std::string &date) {
    if (date.length() != 8) {
        std::cout << "Wrong date input. Try again (DD.MM.YY): ";
        std::cin >> date;
        check_date(date);
    }
    int dd = std::stoi(date.substr(0, 2));
    int mm = std::stoi(date.substr(3, 2));
    int yy = std::stoi(date.substr(6, 2));
    if (!(dd > 0 && dd < 32 && mm > 0 && mm < 13 && yy > 0 && yy < 22)) {
        std::cout << "Wrong date input. Try again (DD.MM.YY): ";
        std::cin >> date;
        check_date(date);
    }
}

void check_name (std::string &name) {
    for (int i = 0; i < name.length(); ++i) {
        if (name[i] < 'A' || name[i] > 'Z') {
            std::cout << "Wrong NAME input. Try again: ";
            std::cin >> name;
            check_name(name);
        }
    }
}
void check_surname (std::string &surname) {
    for (int i = 0; i < surname.length(); ++i) {
        if (surname[i] < 'A' || surname[i] > 'Z') {
            std::cout << "Wrong SURNAME input. Try again: ";
            std::cin >> surname;
            check_surname(surname);
        }
    }
}

void check_payment (std::string &payment) {
    int money = std::stoi(payment);
    if (money <= 0) {
        std::cout << "Wrong PAYMENT input. Try again: ";
        std::cin >> payment;
        check_payment(payment);
    }
}

void input_data(std::string &name, std::string &surname, std::string &date, std::string &payment) {
    std::cout << "Input new line in 'NAME SURNAME DD.MM.YY PAYMENT' format: ";
    std::cin >> name >> surname >> date >> payment;
}

void checking_data(std::string &name, std::string &surname, std::string &date, std::string &payment) {
    check_name(name);
    check_surname(surname);
    check_date(date);
    check_payment(payment);
}

int main() {
    std::string name, surname, date, payment;
    std::ofstream file("..\\statement.txt", std::ios::app);
    if (!file.is_open()) {
        std::cout << "Open file error!";
        return 1;
    }
    input_data(name, surname, date, payment);
    checking_data(name, surname, date, payment);
    file << name << " " << surname << " "  << date << " "  << payment << std::endl;
    file.close();
    return 0;
}
