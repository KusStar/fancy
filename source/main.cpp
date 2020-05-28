#include <iostream>

#include "fancy.hpp"

using namespace std;
using fancy::Fancy;
using fancy::Color;
using fancy::Style;
using fancy::endline;

int main() {

    Fancy f;

    cout << (f | Color::Red | Style::Bold) << "战 争 即 和 平" << endline;
    cout << (f | Color::Cyan | Style::Inverse)("自 由 即 奴 役") << endline;
    cout << (f.reset() | Color::Yellow | Style::Underline) << "无 知 即 力 量" << endline;

}
