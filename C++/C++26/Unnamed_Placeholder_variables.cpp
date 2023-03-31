#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> student_records =
	{
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    // We only care about the names (the map values), not the IDs (the keys)
    // We can use '_' to safely ignore the key.
    for (const auto& [_, name] : student_records)
        std::cout << "Student: " << name << '\n';
}

////////////////////////////////////////////////////////////////////////////////////////////////////


#include <tuple>
#include <string>

std::tuple<int, std::string, double, char> get_sensor_data()
{
    return { 42, "Telemetry_A", 98.6, 'X' };
}

int main()
{
    // We only want the double value (index 2). 
    // We reuse '_' for index 0, 1, and 3 simultaneously.
    auto [_, _, target_value, _] = get_sensor_data();
}