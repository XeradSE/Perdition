#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "./../include/Map.hpp"

using namespace ftxui;

int main() {

    Map map(20, 30);

    map.generate(5, 5, 10);

    return 0;
}