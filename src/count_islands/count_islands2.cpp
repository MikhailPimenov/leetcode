#include <iostream>
#include <vector>
#include <queue>


// 0000001
// 0001100
// 0011100
// 0000001
// -> 3

// 0000001110000011
// 0001100110010000
// 0011100111110111
// 0000001110010000
// -> 4


// 00000
// 01000
// 00111
// -> 2


// 0000
// 0000
// 0000
// -> 0


// 1001
// 0110
// 1001
// -> 5
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<int>>& field) {
    for (const auto& line: field) {
        for (int symbol: line) {
            std::cout << symbol << ' ';
        }
        std::cout << '\n';
    }
    return out;
}

// 00000
// 00011
// 00111
// 00000
// -> 1
using row_t     = std::size_t;
using column_t  = std::size_t;
struct Cell {
    row_t _row;
    column_t _column;
    int _value;

public:
    Cell(row_t row, column_t column, int value) 
        : _row(row), _column(column), _value(value) {}
};
using Queue_t   = std::queue<Cell>;
using Visited_t = std::vector<bool>;



void breadth_first_search(const Cell& start, const std::vector<std::vector<int>>& field, std::size_t columns, Visited_t& visited, int land_symbol) {
    const auto get_neighbours = [&field, columns] (const Cell& cell) -> std::vector<Cell> {
        std::vector<Cell> neighbours;
        neighbours.reserve(4ul);

        if (0ul < cell._row) 
            neighbours.push_back(Cell(cell._row - 1ul,  cell._column,       field[cell._row - 1ul][cell._column]));
        if (cell._column + 1ul < columns) 
            neighbours.push_back(Cell(cell._row,        cell._column + 1ul, field[cell._row][cell._column + 1ul]));
        if (cell._row + 1ul < field.size()) 
            neighbours.push_back(Cell(cell._row + 1ul,  cell._column,       field[cell._row + 1ul][cell._column]));
        if (0ul < cell._column) 
            neighbours.push_back(Cell(cell._row,        cell._column - 1ul, field[cell._row][cell._column - 1ul]));

        return neighbours;
    };
    
    Queue_t queue;
    queue.push(start);

    while (!queue.empty()) {
        const Cell current = queue.front();
        queue.pop();

        const std::size_t index = current._row * columns + current._column;
        if (!visited[index]) {
            visited[index] = true;

            for (const Cell& neighbour: get_neighbours(current)) {
                const std::size_t neighbour_index = neighbour._row * columns + neighbour._column;
                if (!visited[neighbour_index] && neighbour._value == land_symbol)
                    queue.push(neighbour);
            }
        }  
    }
}
int get_island_number(const std::vector<std::vector<int>>& field, int water_symbol, int land_symbol) {
    const std::size_t columns = field.at(0u).size();

    const std::size_t number_of_cells = [&field]() -> std::size_t {
        std::size_t number_of_cells{0ul};
        for (const auto& line: field)
            number_of_cells += line.size();
        return number_of_cells;
    }();    //  IILE  // Immediately Invoked Lambda Expression  

    if (number_of_cells < 1u) 
        return 0;

    int result = 0;

    Visited_t visited(number_of_cells);

    for (std::size_t index = 0ul; index < number_of_cells; ++index) {
        const Cell current(index / columns, index % columns, field[index / columns][index % columns]);
        if (!visited[current._row * columns + current._column] && current._value == land_symbol) {
            ++result;
            breadth_first_search(current, field, columns, visited, land_symbol);
        }
    }

    return result + 0 * water_symbol;
}

void test_case(int test_number, int* successful_test_number, int actual, int expected, const std::vector<std::vector<int>>& field) {
    std::cout << "test #:" << test_number << "\t\t";
    if (actual == expected) {
        std::cout << "ok\n";
        ++(*successful_test_number);
    } else {
        std::cout << "FAILED\n";
        std::cout << "input:\n" << field << '\n';
        std::cout << "expected:\t" << expected << '\n';
        std::cout << "actual:\t\t" << actual << '\n'; 
    }
}

void get_island_number_test(int (*algorithm)(const std::vector<std::vector<int>>&, int, int)) {
    int test_number = 0;
    int successful_test_number = 0;

    {
        const std::vector<std::vector<int>> field {
            {0,0,0,0,0},
            {0,0,0,1,1},
            {0,0,1,1,1},
            {0,0,0,0,0},
        };
        const int expected = 1;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;

    {
        const std::vector<std::vector<int>> field {
            {0,0,0,0,0,0,1},
            {0,0,0,1,1,0,0},
            {0,0,1,1,1,0,0},
            {0,0,0,0,0,0,1},
        };
        const int expected = 3;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;

    {
        const std::vector<std::vector<int>> field {
            {0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1},
            {0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0},
            {0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1},
            {0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0},
        };
        const int expected = 4;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;

    {
        const std::vector<std::vector<int>> field {
            {0,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,1,1},
        };
        const int expected = 2;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;

    {
        const std::vector<std::vector<int>> field {
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
        };
        const int expected = 0;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;

    {
        const std::vector<std::vector<int>> field {
            {1,0,0,1},
            {0,1,1,0},
            {1,0,0,1},
        };
        const int expected = 5;
        const int actual = algorithm(field, 0, 1);
        
        test_case(test_number, &successful_test_number, actual, expected, field);
    }
    ++test_number;


    std::cout << "SUMMARY:\t" << successful_test_number << " / " << test_number << " " 
              << 100.0f * static_cast<float>(successful_test_number) / static_cast<float>(test_number) << "%\n";  
}

int main() {
    get_island_number_test(get_island_number);
    return 0;
}