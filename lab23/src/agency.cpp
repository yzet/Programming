#include "agency.hpp"
#include <iostream>

// TODO: rename file from hpp to h

Agency::Agency() {
    is_weekends = false;
    name = "Name";
    years_on_market = 0;
    director.name = "Name";
    director.surname = "Surname";
    director.email = "email@email";
    city = Kharkiv;
}

//Agency::Agency(const Agency &copy) {
//    is_weekends = copy.is_weekends;
//    name = copy.name;
//    years_on_market = copy.years_on_market;
//    director = copy.director;
//    city = copy.city;
//}
//Agency::Agency(const Agency &copy) = default;

Agency::Agency(bool is_weekends_value, std::string name_value, int years_on_market_value, person_t director_value, Cities city_value) {
    is_weekends = is_weekends_value;
    name = std::move(name_value);
    years_on_market = years_on_market_value;
    director = std::move(director_value);
    city = city_value;
}

Agency::~Agency() = default;

bool Agency::GetIsWeekends() const {
    return is_weekends;
}

void Agency::SetIsWeekends(const bool value) {
    is_weekends = value;
}

std::string Agency::GetName() const {
    return name;
}

void Agency::SetName(const std::string &value) {
    name = value;
}

int Agency::GetYearsOnMarket() const {
    return years_on_market;
}

void Agency::SetYearsOnMarket(int value) {
    years_on_market = value;
}

person_t Agency::GetDirector() const {
    return director;
}

void Agency::SetDirector(const person_t &value) {
    director = value;
}

Cities Agency::GetCity() const {
    return city;
}

void Agency::SetCity(Cities value) {
    city = value;
}

void Agency::PrintAgency() const {
    std::cout << "Name: " << name;
    std::cout << std::endl;
    this->PrintDirector();
    std::cout << std::endl;
    std::cout << "Weekend: " << (is_weekends ? "Yes" : "No");
    std::cout << std::endl;
    std::cout << "Years on market: " << years_on_market;
    std::cout << std::endl;
    std::cout << "City: " << CityToString();
}

void Agency::PrintDirector() const {
    std::cout << "Director: ";
    std::cout << "Surname: " << director.surname << " Name: " << director.name << " Email: " << director.email;
}

std::string Agency::CityToString() const {
    std::string result = "NULL";
    switch (city) {
        case Kharkiv:
            result = "Kharkiv";
            break;
        case Kiyv:
            result = "Kyiv";
            break;
        case London:
            result = "London";
            break;
    }
    return result;
}
