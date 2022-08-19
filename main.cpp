#include "nlohmann/json.hpp"
#include <iostream>
#include <stdexcept>


auto print_value_op(nlohmann::json const & json, char const * key)
{
    auto const val = json[key].get<std::string>();
    std::cout << val << '\n';
}

auto print_value_at(nlohmann::json const & json, char const * key)
{
    auto const val = json.at(key).get<std::string>();
    std::cout << val << '\n';
}

auto print_val(nlohmann::json const & json, char const * key)
{
    if (!json.contains(key))
    {
        std::cout << "Cannot find key '" << key << "'\n";
        return;
    }

    if (json[key].is_null())
    {
        std::cout << "The value for key '" << key << "' is null\n";
        return;
    }

    auto const val = json.at(key);
    auto const vala = val.at("subkey_a").get<std::string>();
    auto const valb = val.at("subkey_b").get<std::string>();
    std::cout << "Value: '" << vala << ", " << valb << "'\n";
}

auto check_null()
{
    auto json =
    R"(
    {
      "key_notnull": {
        "subkey_a": "vala",
        "subkey_b": "valb"
      },
      "key_null": null
    }
    )"_json;

    try
    {
        print_val(json, "key_notnull");
        print_val(json, "key_null");
    }
    catch (std::exception const & e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
}

int main()
{
    check_null();
    return 0;

    auto const json =
    R"(
    {
      "key": "value"
    }
    )"_json;

    try
    {
        print_value_at(json, "key");
        print_value_at(json, "missing");
    }
    catch (std::exception const & e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
