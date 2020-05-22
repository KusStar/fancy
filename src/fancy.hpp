#ifndef _FANCY_H
#define _FANCY_H

/**
    @from https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
    \033[${style};${color}m${text}\033[0m
*/

namespace fancy {

    using namespace std;

    enum class Color {
        Default = 29,
        Black,
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

    namespace detail {

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

    } // namespace fancy::detail

    class Fancy {

        Color color_;
        Style style_;

        public:
            Fancy() : color_(Color::Default), style_(Style::Normal) {};

            string operator() (const string& text) {
                return detail::fancy_str(text, color_, style_);
            }

            Fancy& operator| (const Color& color) {
                color_ = color;
                return *this;
            }

            Fancy& operator| (const Style& style) {
                style_ = style;
                return *this;
            }

            Fancy& reset() {
                color_ = Color::Default;
                style_ = Style::Normal;
                return *this;
            }

    }; // class Fancy

} // namespace fancy

#endif // _FANCY_H
