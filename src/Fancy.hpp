#ifndef _FANCY_H
#define _FANCY_H

/**
    @from https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
    \033[${style};${color}m${text}\033[0m
*/

namespace Fancy {

    using namespace std;

    enum class Color {
        Black = 30,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White
    };
    enum class Style {
        Normal = 0,
        Bold = 1,
        Underline = 4,
        Inverse = 7,
    };

    template <typename T>
    string enum_str(T v) {
        return to_string((unsigned int) v);
    }

    string fancy_str(const string& text, const Color& color, const Style& style) {
        return "\033["
        + enum_str(style)
        + ";"
        + enum_str(color)
        + "m"
        + text
        + "\033[0m";
    }

    // default
    string fancy_str(const string& text, const Color& color) {
        return fancy_str(text, color, Style::Normal);
    }

    string cyan(const string& text, const Style& style) {
        return fancy_str(text, Color::Cyan, style);
    }

    // default cyan
    string cyan(const string& text) {
        return fancy_str(text, Color::Cyan);
    }

}

#endif
