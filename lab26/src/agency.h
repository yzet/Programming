#ifndef __AGENCY_HEADER__
#define __AGENCY_HEADER__

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sstream>

struct Person {
    std::string name;
    std::string surname;
    std::string email;
} typedef person_t;

enum Cities {
    Kharkiv,
    Kiyv,
    London
};

class Agency {
protected:
    bool is_weekends;
    std::string name;
    int years_on_market;
    person_t director;
    Cities city;

    void PrintDirector() const;

    std::string CityToString() const;
    std::string CityToString(Cities city_value) const;

    Cities StringToCity(const std::string &city_string) const;

    static void ValueToAgencyByIndex(Agency &agency, int32_t index, const std::string &value);

public:
    Agency();

    Agency(bool is_weekends_value, std::string name_value, int years_on_market_value, person_t director_value,
           Cities city_value);

    ~Agency();

    bool GetIsWeekends() const;

    void SetIsWeekends(bool value);

    std::string GetName() const;

    void SetName(const std::string &value);

    int GetYearsOnMarket() const;

    void SetYearsOnMarket(int value);

    person_t GetDirector() const;

    void SetDirector(const person_t &value);

    Cities GetCity() const;

    void SetCity(Cities value);

    void PrintAgency() const;

    std::string toString() const;

    static Agency FromString(std::string agency_string);

//    Agency &operator=(const Agency &agency);

    bool operator==(const Agency &agency) const;

    friend std::ostream &operator<<(std::ostream &output, const Agency &agency);

    friend std::istream &operator>>(std::istream &input, Agency &agency);

};

#endif