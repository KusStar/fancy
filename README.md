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
  VERSION 0.1.0
)
```
## Usage

```cpp
#include <iostream>

#include "fancy.hpp"

using namespace std;
using fancy::Fancy;
using fancy::Color;
using fancy::Style;
using fancy::ending;

int main() {

    Fancy f;

    cout << (f | Color::Red | Style::Bold) << "战 争 即 和 平" << ending;
    cout << (f | Color::Cyan | Style::Inverse)("自 由 即 奴 役") << ending;
    cout << (f.reset() | Color::Yellow | Style::Underline) << "无 知 即 力 量" << ending;

}

```

Or

```cpp
// ...

int main() {
    Fancy _fancy = Fancy(Color::Red, Style::Bold);

    cout << _fancy("战 争 即 和 平") << "\n";
    cout << (_fancy | Color::Cyan | Style::Inverse)("自 由 即 奴 役") << "\n";
    cout << (_fancy.reset() | Color::Yellow | Style::Underline)("无 知 即 力 量") << "\n";
}
```

## Thanks

- [CPM.cmake](https://github.com/TheLartians/CPM.cmake)

- [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter)

## License

- [MIT](LICENSE)
