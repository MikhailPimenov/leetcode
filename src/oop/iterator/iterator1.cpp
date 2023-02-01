#include <iostream>

class enumerate;

class Item {
    friend class enumerate;

private:
    double* _data;
    int _length;
public:
    Item(double* data, int length) : _data{data}, _length{length} {}

    const double* begin() const {
        return _data + 0;
    }
    const double* end() const {
        return _data + _length;
    }
};

class enumerate {
private:
    Item* _owner;
    int _index;
public:
    explicit enumerate(Item& item) : _owner{&item}, _index{0} {}

    std::pair<int, double> begin() {
        _index = 0;
        return std::make_pair(0, *(_owner->_data)); 
    }

    std::pair<int, double> end() {
        return std::make_pair(_owner->_length, *(_owner->_data + _owner->_length)); 
    }

    // void operator++() {
    //     ++_index;
    // }

    // std::pair<int, double> operator*() {
    //     return std::make_pair(_index, *(_owner->_data + _index));
    // }

    struct Pair {
        int index;
        double value;
    } _pair;

    friend void operator++(std::pair<int, double>& pair);
};

void operator++(std::pair<int, double>& pair) {
    ++(pair.first);
}
std::pair<int, double> operator*(const std::pair<int, double>& pair) {
    return pair;
}

int main() {
    double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const int length = sizeof(array) / sizeof(array[0]);

    Item item(array, length);

    // for (double element : item) 
        // std::cout << element << '\n';

    
    for (const auto& [index, element] : enumerate(item)) 
        std::cout << index << ' '<< element << '\n';

}