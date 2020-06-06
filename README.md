# fancy

> A fancy terminal string styling header-only cpp library [Rubbish wheel]

## Integration

With [CPM.make](https://github.com/TheLartians/CPM.cmake)

```cmake
# CMakeLists.txt

include(cmake/CPM.cmake)

CPMAddPackage(
  NAME fancy
  GITHUB_REPOSITORY KusStar/fancy
  VERSION 0.2.1
)
```
## Usage

```cpp
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
```

Or

```cpp
// ...

int main() {
    Fancy _fancy = Fancy(Attribute::Red, Attribute::Bright);

    cout << _fancy("战 争 即 和 平") << "\n";
    cout << (_fancy | Attribute::BG_Cyan | Attribute::Reverse)("自 由 即 奴 役") << "\n";
    cout << (_fancy.reset() | Attribute::Yellow | Attribute::Underscore)("无 知 即 力 量") << "\n";
}
```

**Attribute**

```cpp
enum class Attribute : unsigned int {
    Reset = 0,
    // Style
    Bright = 1,
    Dim = 2,
    Underscore = 4,
    Blink = 5,
    Reverse = 7,
    Hidden = 8,
    // Foreground
    Black = 30,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    // Background
    BG_Black = 40,
    BG_Red,
    BG_Green,
    BG_Yellow,
    BG_Blue,
    BG_Magenta,
    BG_Cyan,
    BG_White,
};
```
**Other**

```cpp
using fancy::Attribute;
using fancy::detail;
using fancy::ending;
using fancy::endline;
using fancy::Fancy;
```

## Thanks

- [CPM.cmake](https://github.com/TheLartians/CPM.cmake)

- [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter)

## License

- [MIT](LICENSE)
