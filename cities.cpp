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

    short first_city_index = rand() % (cities::cities_list_length - cities::shift);

    string first_city = cities_list[first_city_index];

    cities_list.erase(cities_list.begin() + first_city_index);

    return first_city;
}

string str_to_lower(string str)
{
    for (int i = 0, len = str.length(); i != len; ++i)
        str[i] = tolower(str[i]);

    return str;
}

int get_city_index(char letter, vector<string> cities_list)
{
    int max = cities_list.size() - cities::shift, min = 0, mid;

    while (min <= max)
    {
        mid = (max + min) / 2;

        char first_letter = cities_list[mid][0];

        if (first_letter == letter)
            return mid;

        else if (first_letter > letter)
            max = mid - cities::shift;

        else
            min = mid + cities::shift;
    }

    return cities::absent_city_index;
}

string generate_city(string user_city, vector<string> &cities_list) 
{
    int index = get_city_index(user_city[user_city.length() - cities::shift], cities_list);
    string generated_city = cities::no_city;

    if (index != cities::absent_city_index)
    {
        generated_city = cities_list[index];

        cities_list.erase(cities_list.begin() + index);
    }

    return generated_city;
}

cities::city_validity validate_city(string user_city, string generated_city, vector<string> &cities_list)
{
    if (user_city != cities::no_city && get_city_index(user_city[0], cities_list) == cities::absent_city_index)
        return cities::ABSENT_CITY_FIRST_LETTER;

    int max = cities_list.size() - cities::shift, min = 0, mid, len = generated_city.length();

    while (min <= max) 
    {
        mid = (max + min) / 2;

        string founded_city = cities_list[mid];

        if (founded_city == user_city && founded_city[0] == generated_city[len - cities::shift])
        {
            cities_list.erase(cities_list.begin() + mid);

            return cities::VALID;
        }
        
        else if (founded_city > user_city)
            max = mid - cities::shift;
        
        else
            min = mid + cities::shift;
    }

    return cities::INVALID;
}
