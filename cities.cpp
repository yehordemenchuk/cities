#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <QCoreApplication>
#include <QMessageBox>
#include "cities.h"

void load_cities(vector<string> &cities_list) 
{
    ifstream cities_file { cities::cities_file_name };

    if (!cities_file)
    {
        qCritical() << "Error. Game file \"naming_cities.txt\" was corrupted or lost.";

        QMessageBox::critical(nullptr, "Error", "Game file \"naming_cities.txt\" was corrupted or lost.");

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i != cities::cities_list_length; ++i)
        getline(cities_file, cities_list[i]);
}

void random_generator_init()
{
    srand(time(nullptr));
}

string generate_first_city(vector<string> &cities_list)
{
    random_generator_init();

    short first_city_index(rand() % (cities::cities_list_length - cities::shift));

    string first_city { cities_list[first_city_index] };

    cities_list.erase(cities_list.begin() + first_city_index);

    return first_city;
}

string process_city_name(string city_name)
{
    for (int i = 0, len = city_name.length(); i != len; ++i)
        city_name[i] = tolower(city_name[i]);

    return city_name;
}

int get_city_index(string finding_element, vector<string> cities_list)
{
    int max(cities_list.size() - cities::shift), min { 0 }, mid, finding_element_len(finding_element.length());

    while (min <= max)
    {
        mid = (max + min) / 2;

        string founded_element { cities_list[mid] };

        if (finding_element_len == cities::minimal_len)
            founded_element = founded_element[0];

        if (founded_element == finding_element)
            return mid;

        else if (founded_element > finding_element)
            max = mid - cities::shift;

        else
            min = mid + cities::shift;
    }

    return cities::absent_city_index;
}

string generate_city(string user_city, vector<string> &cities_list) 
{
    int index { get_city_index(string(1, user_city[user_city.length() - cities::shift]), cities_list) };
    string generated_city { cities::no_city };

    if (index != cities::absent_city_index)
    {
        generated_city = cities_list[index];

        cities_list.erase(cities_list.begin() + index);
    }

    return generated_city;
}

cities::city_validity validate_city(string user_city, string generated_city, vector<string> &cities_list)
{
    char user_city_first_letter { user_city[0] };

    if (user_city != cities::no_city && get_city_index(string(1, user_city_first_letter), cities_list) == cities::absent_city_index)
        return cities::ABSENT_CITY_FIRST_LETTER;

    int validating_city_index { get_city_index(user_city, cities_list) };

    if (validating_city_index == cities::absent_city_index ||
        user_city_first_letter != generated_city[generated_city.length() - cities::shift])
        return cities::INVALID;

    cities_list.erase(cities_list.begin() + validating_city_index);

    return cities::VALID;
}
