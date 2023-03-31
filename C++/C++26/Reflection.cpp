#include <meta>

struct Account
{
    unsigned long long id;
};

int main()
{
    // Reflect over the type of Account::id
    constexpr std::meta::info id_type_reflection = std::meta::type_of(^^Account::id);

    // Splice the reflection token back to define a standard variable type
    [: id_type_reflection :] backup_id = 99999; 
    
    // The compiler reads the line above exactly as: 
    // unsigned long long backup_id = 99999;
}

struct Player
{
    int health;
    float speed;
    bool alive;
};

template<typename T> consteval void print_members()
{
    for constexpr (auto member : members_of(^T))
    {
        std::cout << name_of(member) << '\n';
    }
}

int main()
{
	print_members<Player>();
}

/*
Output:

health
speed
alive
*/

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <string_view>
#include <iostream>

enum class Color { Red, Green, Blue };

template <typename E> constexpr std::string_view enum_to_string(E value)
{
    std::string_view result = "<unknown>";

    // 1. Get the enumerators as a range of reflections
    // 2. Expand them into a loop at compile-time
    [: expand(std::meta::enumerators_of(^^E)) :] >> [&]<auto e>
	{
        // 3. Splice 'e' back into regular code using [:e:] to match the runtime value
        if (value == [:e:])
		{
            result = std::meta::identifier_of(e); // Get its string name
        }
    };
	
    return result;
}

int main()
{
    std::cout << enum_to_string(Color::Green) << '\n';
}

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <meta>
#include <string>
#include <format>
#include <iostream>

struct User
{
    std::string name;
    int age;
    bool is_admin;
};

template <typename T> std::string to_json(const T& obj)
{
    std::string json = "{";

    // Grab all non-static data members of the struct at compile time
    [: expand(std::meta::nonstatic_data_members_of(^^T)) :] >> [&]<auto m>
	{
        json += std::format("\"{}\":{},", 
							std::meta::identifier_of(m),  // The name of the field (e.g., "age")
							obj.[:m:]                      // Splicing 'm' to read the actual object's value
        );
    };

    if (json.back() == ',') json.back() = '}';
    else json += "}";
    return json;
}

int main()
{
    User alice{"Alice", 30, true};
    std::cout << to_json(alice) << '\n';
    // Output: {"name":Alice,"age":30,"is_admin":true}
}