#ifndef _FANCY_H
#define _FANCY_H

#pragma once

#include <ostream>
#include <string>
#include <type_traits>

namespace fancy {

    using namespace std;

    enum class Color : unsigned int {
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

    enum class Style : unsigned int {
        Normal = 0,
        Bold = 1,
        Dim = 2,
        Underline = 4,
        Blink = 5,
        Inverse = 7,
        Hidden = 8
    };

    namespace detail {

        const string POSTFIX = "\033[0m";

        template <typename T>
        auto enum_value(T v) -> unsigned int {
            return static_cast<typename underlying_type<T>::type>(v);
        }

        template <typename T>
        string enum_str(T v) {
            return to_string(enum_value(v));
        }

        string prefix_str(const Color& color, const Style& style) {
            return "\033["
            + enum_str(style)
            + ";"
            + enum_str(color)
            + "m";
        }

        string fancy_str(const string& text, const Color& color, const Style& style) {
            return prefix_str(color, style) + text + POSTFIX;
        }

        template<typename Base, typename ...Rest>
        string stringer(const Base& base, const Rest& ...rest) {
            string result = base;
            if (sizeof...(rest) > 0) {
                const string padding = " ";
                using List = int[];
                (void) List { 0, ( result += padding, result += rest, 0 ) ... };
            }
            return result;
        }

    } // namespace fancy::detail

    const string ending = detail::POSTFIX;

    const string endline = detail::POSTFIX + "\n";

    class Fancy {

        Color color_;
        Style style_;

        public:
            Fancy() : color_(Color::Default), style_(Style::Normal) {};
            Fancy(const Color& color, const Style& style) : color_(color), style_(style) {};
            Fancy(const Color& color) : color_(color) {};
            Fancy(const Style& style) : style_(style) {};

            friend ostream& operator<< (ostream& os, const Fancy& f) {
                os << detail::prefix_str(f.color_, f.style_);
                return os;
            }

            template<typename ...Args>
            string operator() (const Args& ...args) {
                return detail::fancy_str(detail::stringer(args...), color_, style_);
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

    }; // class fancy::Fancy

} // namespace fancy

#endif // _FANCY_H
