#include <iostream>

#include "fancy.hpp"

using namespace std;
using fancy::Fancy;
using fancy::Attribute;
using fancy::endline;

int main() {

    Fancy f;

    cout << (f | Attribute::Red | Attribute::Bright) << "战 争 即 和 平" << endline;
    cout << (f | Attribute::Cyan | Attribute::Reverse) << "自 由 即 奴 役" << endline;
    cout << (f.reset() | Attribute::Yellow) << "无 知 即 力 量" << endline;

}
