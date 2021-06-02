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
    char TYPE;

    bool is_weekends;
    std::string name;
    int years_on_market;
    person_t director;
    Cities city;

    virtual void PrintDirector() const = 0;

    virtual std::string CityToString() const = 0;

    virtual std::string CityToString(Cities city_value) const = 0;


    static void ValueToAgencyByIndex(Agency * agency, int32_t index, const std::string &value);

public:
    Agency();

    Agency(bool is_weekends_value, std::string name_value, int years_on_market_value, person_t director_value,
           Cities city_value);

    virtual ~Agency();

    virtual bool GetIsWeekends() const = 0;

    virtual void SetIsWeekends(bool value) = 0;

    virtual std::string GetName() const = 0;

    virtual void SetName(const std::string &value) = 0;

    virtual int GetYearsOnMarket() const = 0;

    virtual void SetYearsOnMarket(int value) = 0;

    virtual person_t GetDirector() const = 0;

    virtual void SetDirector(const person_t &value) = 0;

    virtual Cities GetCity() const = 0;

    virtual void SetCity(Cities value) = 0;

    virtual void PrintAgency() const = 0;

    virtual std::string toString() const = 0;
    virtual void getAgencyFromConsole(std::istream &input,  Agency &agency) const = 0;

//    static Agency * FromString(std::string agency_string); // TODO: edit to *

//    Agency &operator=(const Agency &agency);

    virtual bool operator==(const Agency &agency) const = 0;

    virtual char GetType() const = 0;
    virtual void SetType(char type) = 0;

    virtual std::string ServiceToString() const = 0;

    friend std::ostream &operator<<(std::ostream &output, const Agency &agency);

    friend std::istream &operator>>(std::istream &input, Agency &agency);

    virtual Agency * Clone() const = 0;
    virtual Cities StringToCity(const std::string &city_string) const = 0;

};


#endif