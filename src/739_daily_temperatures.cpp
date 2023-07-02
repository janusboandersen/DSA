/**
 * @file src/739_daily_temperatures.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 739
 * @version 1.0
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <739/daily_temperatures.hpp>

namespace p739 {

struct Observation {
    std::size_t day;
    int value;
};

Solution::ReturnValueType Solution::dailyTemperatures(Solution::InputValueType& temperatures)
{
    std::vector<int> result(temperatures.size(), 0);
    std::stack<Observation> prev_observations;

    for (auto today = 0UL; today < temperatures.size(); ++today) {

        // Clearing stack for observation values smaller than today's temperature, and storing the difference in days
        while (prev_observations.size() > 0 && temperatures[today] > prev_observations.top().value) {
            result[prev_observations.top().day] = today - prev_observations.top().day;
            prev_observations.pop();
        }

        // Putting today's observation on the monotonically decreasing stack (temp[today] < temp[today-1] or stack empty)
        prev_observations.push({today, temperatures[today]});
    }

    return result;
}


Solution::ReturnValueType Solution::dailyTemperatures_bf(Solution::InputValueType& temperatures)
{
    std::vector<int> result(temperatures.size(), 0);

    for (auto it = temperatures.begin(); it != temperatures.end(); ++it) {
        auto next_day = std::find_if(it+1, temperatures.end(), [min=*it](const int& temp){ return (temp > min); });
        result[std::distance(temperatures.begin(), it)] = (next_day == temperatures.end() ? 0 : std::distance(it, next_day));
    }

    return result;
}

} // namespace