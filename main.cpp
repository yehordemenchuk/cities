#include <iostream>
#include <string>
#include <vector>
#include "cities.h"

int main() {
    vector<string> cities_list(cities::cities_list_length);

    load_cities(cities_list);

    cout << generate_city("I", cities_list) << endl;

    return 0;
}