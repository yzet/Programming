#include "agency.h"

Agency::Agency() {
    is_weekends = false;
    name = "Name";
    years_on_market = 0;
    director.name = "Name";
    director.surname = "Surname";
    director.email = "email@email";
    city = Kharkiv;

#ifdef DEBUG
    std::cout << "Default constructor called for Agency" << std::endl;
#endif
}

//Agency::Agency(const Agency &copy) {
//    is_weekends = copy.is_weekends;
//    name = copy.name;
//    years_on_market = copy.years_on_market;
//    director = copy.director;
//    city = copy.city;
//}
#ifdef DEBUG
Agency::Agency(const Agency &copy) {
    std::cout << "Copy constructor called for Agency" << std::endl;
}
#endif

Agency::Agency(bool is_weekends_value, std::string name_value, int years_on_market_value, person_t director_value,
               Cities city_value) {
    is_weekends = is_weekends_value;
    name = std::move(name_value);
    years_on_market = years_on_market_value;
    director = std::move(director_value);
    city = city_value;

#ifdef DEBUG
    std::cout << "Constructor with parameters called for Agency" << std::endl;
#endif
}


#ifdef DEBUG
Agency::~Agency() {
    std::cout << "Destructor called for Agency with name '" << name << '\'' << std::endl;
}
#else

Agency::~Agency() = default;

#endif


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

std::string Agency::toString() const {
    std::stringstream agency_ss;
    agency_ss << "Agency{\n" << "-Name:" << name << "," << std::endl <<
              "-Weekends:" << (is_weekends ? "Yes" : "No") << "," << std::endl <<
              "-Director:{" << std::endl << "--Name:" << director.name << "," << std::endl <<
              "--Surname:" << director.surname << "," << std::endl <<
              "--Email:" << director.email << std::endl << "-}" << std::endl <<
              "-Years on market:" << years_on_market << "," << std::endl <<
              "-City:" << CityToString() << std::endl << "}" << std::endl;

    return agency_ss.str();
}

Agency Agency::FromString(std::string agency_string) { // TODO: test this
    char desired_symbol = '-';
    auto pos_for_replace = (int32_t) agency_string.find(desired_symbol);

    while (pos_for_replace != -1) {
        agency_string.replace((unsigned long) pos_for_replace, 1, 0, desired_symbol);
        pos_for_replace = (int32_t) agency_string.find(desired_symbol);
        if (pos_for_replace == -1 && desired_symbol != '\n') {
            desired_symbol = '\n';
            pos_for_replace = (int32_t) agency_string.find(desired_symbol);
        }
    }

    Agency result_agency;
    std::string read_data;
    size_t key_index = 0;
    size_t next_delimiter_index = 0;

    std::string keys[] = {
            "Name",
            "Weekends",
            "Name",
            "Surname",
            "Email",
            "Years on market",
            "City"
    };
    size_t keys_length = 7;

    for (size_t i = 0; i < keys_length; i++) {
        key_index = agency_string.find(keys[i], key_index);
        next_delimiter_index = std::min(agency_string.find(',', key_index),
                                        agency_string.find('}', key_index)); // TODO: can return -1?
        size_t first_value_index = key_index + keys[i].length() + 1;
        read_data = agency_string.substr(first_value_index, next_delimiter_index - first_value_index);
        Agency::ValueToAgencyByIndex(result_agency, (int)i, read_data);
    }

    return result_agency;
}

void Agency::ValueToAgencyByIndex(Agency &agency, int32_t index, const std::string &value) { // TODO: why is not static
    switch (index) {
        case 0:
            agency.SetName(value);
            break;
        case 1:
            agency.SetIsWeekends(value == "Yes");
            break;
        case 2:
            agency.director.name = value;
            break;
        case 3:
            agency.director.surname = value;
            break;
        case 4:
            agency.director.email = value;
            break;
        case 5: {
            std::stringstream ss;
            ss << value;
            int years_on_market = 0;
            ss >> years_on_market;
            agency.SetYearsOnMarket(years_on_market);
        }
            break;
        case 6:
            agency.SetCity(agency.StringToCity(value));
            break;
        default:
            break;
    }
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

Cities Agency::StringToCity(const std::string &city_string) const {
    Cities result = Kharkiv;

    if (city_string == "Kyiv") result = Kiyv;
    else if (city_string == "London") result = London;
    else if (city_string == "Kharkiv") result = Kharkiv;
    else {
        std::cout << "Error in city from string" << std::endl;
    }

    return result;
}
