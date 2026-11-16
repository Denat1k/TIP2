// Задача 2: уникальные слова без учёта регистра и знаков препинания
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <cwctype>

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");                       // включаем поддержку русских букв
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;  // перевод текста в буквы и обратно
    std::vector<std::wstring> words;
    std::string s;
    while (std::cin >> s) {                       // читаем слово (до пробела)
        std::wstring word;
        for (wchar_t c : conv.from_bytes(s))
            if (iswalnum(c) || c == L'-')         // оставляем буквы, цифры и дефис
                word += towlower(c);              // в нижний регистр
        if (!word.empty() && std::find(words.begin(), words.end(), word) == words.end())
            words.push_back(word);                // запоминаем, если слово новое
    }
    for (auto& w : words) std::cout << conv.to_bytes(w) << '\n';
}

//clang++ -std=c++17 -Wno-deprecated-declarations task2.cpp -o task2 && ./task2

