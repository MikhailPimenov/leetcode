#include <iostream>
#include <unordered_map>

void add_to_storage(const std::string &input1, std::unordered_map<char, int> &storage1) {
    for (char symbol: input1) {
        if (storage1.find(symbol) == storage1.cend())
            storage1.insert(std::make_pair(symbol, 0));
        else 
            storage1.at(symbol) += 1;
    }
}

bool is_anagram(const std::string& input1, const std::string& input2) {
    if (input1.size() != input2.size())
        return false;
    
    std::unordered_map<char, int> storage1;
    storage1.reserve(input1.size());
    std::unordered_map<char, int> storage2;
    storage2.reserve(input2.size());

    add_to_storage(input1, storage1);
    add_to_storage(input2, storage2);

    return storage1 == storage2;
}

void test_case(int test_number, const std::string &input1, const std::string& input2, bool expected, bool actual) {
    std::cout << "Test #" << test_number << ":\t";
    if (actual == expected) {
        std::cout << "ok\n";
    } else {
        std::cout << "FAILED\n";
        std::cout << "input1:\t\t" << input1 << '\n';
        std::cout << "input2:\t\t" << input2 << '\n';
        std::cout << "expected:\t" << expected << '\n';
        std::cout << "actual:\t\t" << actual << '\n';
    }
}

void is_anagram_test(bool (*algorithm)(const std::string&, const std::string&)) {
    std::cout << "is_anagram\n";
    
    {
        const std::string input1("1231");
        const std::string input2("3121");
        const bool expected = true;
        const bool actual = algorithm(input1, input2);
        test_case(1, input1, input2, expected, actual);
    }
    
    {
        const std::string input1("12310");
        const std::string input2("3121");
        const bool expected = false;
        const bool actual = algorithm(input1, input2);
        test_case(2, input1, input2, expected, actual);
    }
    
    {
        const std::string input1("1231ab");
        const std::string input2("a31b21");
        const bool expected = true;
        const bool actual = algorithm(input1, input2);
        test_case(3, input1, input2, expected, actual);
    }
    
    {
        const std::string input1("Mike");
        const std::string input2("ikMe");
        const bool expected = true;
        const bool actual = algorithm(input1, input2);
        test_case(4, input1, input2, expected, actual);
    }
    
    {
        const std::string input1("Mike1");
        const std::string input2("2ikMe");
        const bool expected = false;
        const bool actual = algorithm(input1, input2);
        test_case(5, input1, input2, expected, actual);
    }
    
    {
        const std::string input1;
        const std::string input2("2ikMe");
        const bool expected = false;
        const bool actual = algorithm(input1, input2);
        test_case(6, input1, input2, expected, actual);
    }
    
    {
        const std::string input1("2ikMe");
        const std::string input2;
        const bool expected = false;
        const bool actual = algorithm(input1, input2);
        test_case(7, input1, input2, expected, actual);
    }
    
    {
        const std::string input1;
        const std::string input2;
        const bool expected = true;
        const bool actual = algorithm(input1, input2);
        test_case(8, input1, input2, expected, actual);
    }
}

int main() {
    is_anagram_test(is_anagram);

    return 0;
}