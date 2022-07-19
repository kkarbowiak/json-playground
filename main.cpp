#include "nlohmann/json.hpp"
#include <iostream>
#include <stdexcept>


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
        auto const val = json["key"].get<std::string>();
        std::cout << val << '\n';
    }
    catch (std::exception const & e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
