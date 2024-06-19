#include <iostream>
#include <algorithm>
#include <string>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    // Создаем копии строк для сортировки
    std::string sortedStr1 = str1;
    std::string sortedStr2 = str2;

    // Сортируем обе строки
    std::sort(sortedStr1.begin(), sortedStr1.end());
    std::sort(sortedStr2.begin(), sortedStr2.end());

    // Сравниваем отсортированные строки
    return sortedStr1 == sortedStr2;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter first string: ";
    std::cin >> str1;
    std::cout << "Enter second string: ";
    std::cin >> str2;

    if (areAnagrams(str1, str2)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
