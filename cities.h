#ifndef CITIES_H
#define CITIES_H

#include <string>
#include <vector>

using namespace std;

namespace cities
{
    const short cities_list_length = 274;
    const short shift = 1;
    const char cities_file_name[] = "naming_cities.txt";
    const char no_city[] = "";
}

void load_cities(vector<string> &cities_list);
string generate_city(string user_city, vector<string> &cities_list);
bool validate_city(string user_city, vector<string> cities_list);

#endif