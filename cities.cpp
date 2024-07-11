#include <string>
#include <vector>
#include <fstream>
#include "cities.h"

void load_cities(vector<string> &cities_list) 
{
    ifstream cities_file { cities::cities_file_name };

    for (int i = 0; i != cities::cities_list_length; ++i)
        getline(cities_file, cities_list[i]);
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