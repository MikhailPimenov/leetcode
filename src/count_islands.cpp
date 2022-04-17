#include <queue>
#include <iostream>
#include <vector>


// 1 1 1 1 0
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 0 0

// -> 1

// 1 1 0 0 0
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 1 1

// -> 3

// 1 1 0 0 1
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 1 1

// -> 4

// 1 1 0 0 1 0 1
// 1 1 0 1 0 0 0
// 1 1 0 0 0 1 0
// 0 0 0 1 1 1 0
// 1 1 0 1 1 1 0

// -> 6

using Grid_t    = std::vector<std::vector<int>>;
using Visited_t = std::vector<std::vector<bool>>;
using Queue_t   = std::queue<std::pair<int,int>>;


bool is_earth(const Grid_t& grid, int row, int column) {
    return grid[row][column] == 1;
}

void add_not_visited_neighbours(
    const Grid_t& grid,
    int row,
    int column,
    Visited_t& not_visited,
    Queue_t& queue
) {
    if (row - 1 >= 0 && is_earth(grid, row - 1, column) && not_visited[row - 1][column])
        queue.push(std::make_pair(row - 1, column));
        
    if (row + 1 < static_cast<signed>(grid.size()) && is_earth(grid, row + 1, column) && not_visited[row + 1][column])
        queue.push(std::make_pair(row + 1, column));

    if (column - 1 >= 0 && is_earth(grid, row, column - 1) && not_visited[row][column - 1])
        queue.push(std::make_pair(row, column - 1));
        
    if (column + 1 < static_cast<signed>(grid.at(row).size()) && is_earth(grid, row, column + 1) && not_visited[row][column + 1])
        queue.push(std::make_pair(row, column + 1));
}


void trace_island(
    const Grid_t& grid,
    int row,
    int column,
    Visited_t& not_visited) 
{
    Queue_t queue;
    queue.push(std::make_pair(row, column));
    
    while (! queue.empty()) {
        const std::pair<int, int> current_cell = queue.front();
        queue.pop();

        not_visited[current_cell.first][current_cell.second] = false;
        add_not_visited_neighbours(grid, current_cell.first, current_cell.second, not_visited, queue);
    }
}
int count_islands(const Grid_t& grid) {
    const int rows    = grid.size();
    const int columns = grid.at(0).size();
    
    Visited_t not_visited;
    not_visited.resize(rows);
    for (auto &line: not_visited)
        line.resize(columns, true);

        
    int island_counter = 0;

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (is_earth(grid, row, column) && not_visited[row][column]) {
                trace_island(grid, row, column, not_visited);
                ++island_counter;
            }
        }
    }
    
    
    return island_counter;
}
void count_islands_test(int (*algorithm)(const Grid_t& grid)) {
    Grid_t grid1 {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,0,0,1,1},
    };
    const int result1 = algorithm(grid1);
    std::cout << "Test #1: ";
    if (result1 == 2) {
        std::cout << "ok\n";    
    } else {
        std::cout << "FAILED\n";
        std::cout << "expected: " << 2 << '\n';
        std::cout << "actual:   " << result1 << '\n';
    }
    
    
    
    Grid_t grid2 {
        {1,1,0,0,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {1,1,0,0,0},
        {1,0,0,1,1},
    };
    const int result2 = algorithm(grid2);
    std::cout << "Test #2: ";
    if (result2 == 3) {
        std::cout << "ok\n";    
    } else {
        std::cout << "FAILED\n";
        std::cout << "expected: " << 3 << '\n';
        std::cout << "actual:   " << result2 << '\n';
    }
    
    
    
    Grid_t grid3 {
        {1,1,0,0,0},
        {1,1,0,1,0},
        {1,1,0,0,1},
        {1,1,0,0,0},
        {1,0,0,1,1},
    };
    const int result3 = algorithm(grid3);
    std::cout << "Test #3: ";
    if (result3 == 4) {
        std::cout << "ok\n";    
    } else {
        std::cout << "FAILED\n";
        std::cout << "expected: " << 4 << '\n';
        std::cout << "actual:   " << result3 << '\n';
    }
    
    
    
    Grid_t grid4 {
        {1,1,0,1,1,0,1,0},
        {1,1,0,0,1,0,0,1},
        {1,1,0,0,0,1,0,0},
        {1,1,0,1,0,0,0,0},
        {1,1,0,1,0,1,1,0},
        {1,1,0,0,0,1,1,0},
        {1,1,0,1,1,0,0,1},
        {1,1,0,1,0,1,0,0},
        {1,1,0,1,1,1,0,1},
        
        
    };
    const int result4 = algorithm(grid4);
    std::cout << "Test #4: ";
    if (result4 == 10) {
        std::cout << "ok\n";    
    } else {
        std::cout << "FAILED\n";
        std::cout << "expected: " << 4 << '\n';
        std::cout << "actual:   " << result4 << '\n';
    }
}

int main() {
    count_islands_test(count_islands);
    
    return 0;
}