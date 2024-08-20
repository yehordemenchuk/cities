#ifndef CITIES_H
#define CITIES_H

#include <string>
#include <vector>

using namespace std;

namespace cities
{
    enum city_validity
    {
        VALID,
        INVALID,
        ABSENT_CITY_FIRST_LETTER
    };

    enum game_result
    {
        USER_WON,
        USER_LOOSE
    };

    const short cities_list_length = 273;
    const short shift = 1;
    const short minimal_len = 1;
    const short absent_city_index = -1;
    const char cities_file_path[] = ":\\cities_to_generate\\naming_cities.txt";
    const char no_city[] = "";
}

void load_cities(vector<string> &cities_list);
void random_generator_init();
string generate_first_city(vector<string> &cities_list);
string process_city_name(string city_name);
int get_city_index(string finding_element, vector<string> cities_list);
string generate_city(string user_city, vector<string> &cities_list);
cities::city_validity validate_city(string user_city, string generated_city, vector<string> &cities_list);

#endif
