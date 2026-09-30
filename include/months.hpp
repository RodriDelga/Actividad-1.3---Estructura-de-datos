#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <cctype>

struct Month {
    int index;
    std::string name;
    std::string shortName;
    int days;

    int getDays(bool isLeapYear = false) const {
        if (index == 2 && isLeapYear) return 29;
        return days;
    }
    std::string getMonth() const {
        return name;
    }
};

class MonthRegistry {
public:
    // PUBLIC CONSTRUCTOR: Anyone can create an instance now
    MonthRegistry() {
        months_ = {
            {1,  "January", "Jan",  31}, {2,  "February", "Feb", 28}, {3,  "March",  "Mar",   31},
            {4,  "April",  "Apr",   30}, {5,  "May",    "May",   31}, {6,  "June",   "Jun",   30},
            {7,  "July",   "Jul",   31}, {8,  "August",   "Aug", 31}, {9,  "September", "Sep", 30},
            {10, "October",  "Oct", 31}, {11, "November", "Nov", 30}, {12, "December", "Dec", 31}
        };

        for (const auto& m : months_) {
            std::string lower = m.name;
            std::transform(lower.begin(), lower.end(), lower.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            name_map_[lower] = &m;

            std::string lower_abbrev = m.shortName;
            std::transform(lower_abbrev.begin(), lower_abbrev.end(), lower_abbrev.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            name_map_[lower_abbrev] = &m;

        }
    }

    const Month& get(int index) const {
        if (index < 1 || index > 12) throw std::out_of_range("Invalid index.");
        return months_[index - 1];
    }

    const Month& get(std::string name) const {
        std::transform(name.begin(), name.end(), name.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        auto it = name_map_.find(name);
        if (it == name_map_.end()) throw std::invalid_argument("Invalid name: " + name);
        return *it->second;
    }

    const std::vector<Month>& all() const { return months_; }

    const int  getMonthAbr(std::string name) {
        return get(name).index;
    }
private:
    std::vector<Month> months_;
    std::unordered_map<std::string, const Month*> name_map_;
};