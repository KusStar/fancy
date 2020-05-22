#include <iostream>

#include "fancy.hpp"

using namespace std;
using fancy::Fancy;
using fancy::Color;
using fancy::Style;

int main() {
    Fancy _fancy;

    cout << (_fancy | Color::Magenta | Style::Inverse)("Hello")
         << ", "
         << (_fancy.reset() | Style::Bold)("World")
         << (_fancy | Color::Green)("!")
         << "\n";
}
