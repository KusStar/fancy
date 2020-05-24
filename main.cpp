#include <iostream>

#include "fancy.hpp"

using namespace std;
using fancy::Fancy;
using fancy::Color;
using fancy::Style;

int main() {
    Fancy _fancy = Fancy(Color::Red, Style::Bold);

    cout << _fancy("战 争 即 和 平") << "\n";
    cout << (_fancy | Color::Cyan | Style::Inverse)("自 由 即 奴 役") << "\n";
    cout << (_fancy.reset() | Color::Yellow | Style::Underline)("无 知 即 力 量") << "\n";
}
