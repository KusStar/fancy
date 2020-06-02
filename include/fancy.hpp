#ifndef _FANCY_H
#define _FANCY_H

#pragma once

#include <ostream>
#include <string>

namespace fancy {

    using namespace std;

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

    namespace detail {
        using uint = unsigned int;
        const string CSI = "\x1B[";
        const string RESET = CSI + "0m";

        uint enum_value(Attribute attr) { return static_cast<uint>(attr); }

        string enum_str(Attribute attr) { return to_string(enum_value(attr)); }

        string prefix_str(const Attribute& style, const Attribute& color) {
            return CSI + enum_str(style) + ";" + enum_str(color) + "m";
        }

        string fancy_str(const string& text, const Attribute& style,
                         const Attribute& color) {
            return prefix_str(style, color) + text + RESET;
        }

        template <typename Base, typename... Rest>
        string stringer(const Base& base, const Rest&... rest) {
            string result = base;
            if (sizeof...(rest) > 0) {
                using List = int[];
                const string padding = " ";
                (void)List{0, (result += padding, result += rest, 0)...};
            }
            return result;
        }

    }  // namespace detail

    const string ending = detail::RESET;

    const string endline = detail::RESET + "\n";

    class Fancy {
        Attribute style_;
        Attribute color_;

    public:
        friend ostream& operator<<(ostream& os, const Fancy& f) {
            os << detail::prefix_str(f.style_, f.color_);
            return os;
        }

        template <typename... Args>
        string operator()(const Args&... args) {
            return detail::fancy_str(detail::stringer(args...), style_, color_);
        }

        Fancy& operator|(const Attribute& attr) {
            auto value = detail::enum_value(attr);
            if (value == 0) {
                reset();
            } else if (value < 10) {
                style_ = attr;
            } else {
                color_ = attr;
            }
            return *this;
        }

        Fancy& reset() {
            style_ = Attribute::Reset;
            color_ = Attribute::Reset;
            return *this;
        }

    };  // class fancy::Fancy

}  // namespace fancy

#endif  // _FANCY_H
