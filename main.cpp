#include "nlohmann/json.hpp"
#include <iostream>
#include <stdexcept>


auto print_value_op(nlohmann::json const & json, char const * key)
{
    auto const val = json[key].get<std::string>();
    std::cout << val << '\n';
}

int main()
{
    auto const json =
    R"(
    {
      "key": "value"
    }
    )"_json;

    try
    {
        print_value_op(json, "key");
        print_value_op(json, "missing");
    }
    catch (std::exception const & e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
