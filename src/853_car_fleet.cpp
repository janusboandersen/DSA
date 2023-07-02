/**
 * @file src/853_car_fleet.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 853
 * @version 1.0
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <853/car_fleet.hpp>

namespace p853 {

template <typename T>
void print_vector(const std::vector<T>& v)
{
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& elem : v) {
        std::cout << elem << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}


struct Car {
    std::size_t number;
    int position;
    int speed;
    Car(std::size_t number, int starting_position, int initial_speed) : number{number}, position{starting_position}, speed{initial_speed} {}
    void move() {
        position += speed;
    }
};

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "<Car " << car.number << " at pos " << car.position << " going " << car.speed << " unit/time.>";
    return os;
}


int Solution::carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
{
    // Having only 1 car results in a fleet of 1 car.
    if (position.size() <= 1)
        return position.size();

    std::vector<Car> cars;
    for (auto i = 0UL; i < position.size(); ++i) {
        cars.push_back({i, position[i], speed[i]});
    }

    print_vector(cars);

    std::cout << target << std::endl;
    print_vector(position);
    print_vector(speed);
    return 0;
}

} // namespace