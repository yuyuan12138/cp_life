#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

std::string to_string(int v) {
    return std::to_string(v);
}

std::string to_string(long v) {
    return std::to_string(v);
}

std::string to_string(long long v) {
    return std::to_string(v);
}

std::string to_string(unsigned v) {
    return std::to_string(v);
}

std::string to_string(unsigned long v) {
    return std::to_string(v);
}

std::string to_string(unsigned long long v) {
    return std::to_string(v);
}

std::string to_string(float v) {
    return std::to_string(v);
}

std::string to_string(double v) {
    return std::to_string(v);
}

std::string to_string(long double v) {
    return std::to_string(v);
}

std::string to_string(char v) {
    return std::string(1, v);
}

template <typename A, typename B>
std::string to_string(std::pair<A, B> p);

template <typename A, typename B, typename C>
std::string to_string(std::tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
std::string to_string(std::tuple<A, B, C, D> p);

std::string to_string(const std::string& s) {
    return '"' + s + '"';
}

std::string to_string(const char* s) {
    return to_string((std::string)s);
}

std::string to_string(bool b) {
    return (b ? "true" : "false");
}

std::string to_string(std::vector<bool> v) {
    bool first = true;
    std::string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
std::string to_string(std::bitset<N> v) {
    std::string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
std::string to_string(A v) {
    bool first = true;
    std::string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
std::string to_string(std::pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
std::string to_string(std::tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
std::string to_string(std::tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +
        to_string(get<3>(p)) + ")";
}

void debug_out() {
    std::cerr << std::endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)