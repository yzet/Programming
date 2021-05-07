#ifndef __AGENCY_HEADER__
#define __AGENCY_HEADER__

#include <string>

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
private:
    bool is_weekends;
    std::string name;
    int years_on_market;
    person_t director;
    Cities city;

    void PrintDirector() const;

    std::string CityToString() const;

public:
    Agency();
#ifdef DEBUG
    Agency(const Agency &copy);
#endif
    Agency(bool is_weekends_value, std::string name_value, int years_on_market_value, person_t director_value, Cities city_value);

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

};

#endif