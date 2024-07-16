#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "cities.h"

void load_cities(vector<string> &cities_list) 
{
    ifstream cities_file { cities::cities_file_name };

    if (!cities_file)
        cout << "Error" << endl;

    for (int i = 0; i != cities::cities_list_length; ++i)
    {
        getline(cities_file, cities_list[i]);
    }
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

string generate_city(string user_city, vector<string> &cities_list) 
{
    char first_letter = user_city[user_city.length() - cities::shift];
    int max = cities::cities_list_length - cities::shift;
    int min = 0;

    while (min <= max) 
    {
        int mid = (max + min) / 2;

        string generated_city = cities_list[mid];

        if (generated_city[0] == first_letter) 
        {
            cities_list.erase(cities_list.begin() + mid);

            return generated_city;
        }
        
        else if (generated_city[0] > first_letter)
            max = mid - cities::shift;
        
        else
            min = mid + cities::shift;
    }

    return string(cities::no_city); 
}

bool validate_city(string user_city, vector<string> cities_list) 
{
    int max = cities::cities_list_length - cities::shift;
    int min = 0;

    while (min <= max) 
    {
        int mid = (max + min) / 2;

        string founded_city = cities_list[mid];

        if (founded_city == user_city)
            return true;
        
        else if (founded_city > user_city)
            max = mid - cities::shift;
        
        else
            min = mid + cities::shift;
    }

    return false; 
}
