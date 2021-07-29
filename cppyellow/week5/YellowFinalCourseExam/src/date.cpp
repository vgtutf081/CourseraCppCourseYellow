#include "date.h"

Date::Date(int newYear, int newMonth, int newDay) {
    year = newYear;
    if (newMonth > 12 || newMonth < 1) {
        throw logic_error("Month value is invalid: " + to_string(newMonth));
    }
    month = newMonth;
    if (newDay > 31 || newDay < 1) {
        throw logic_error("Day value is invalid: " + to_string(newDay));
    }
    day = newDay;
}

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
        "-" << setw(2) << setfill('0') << date.GetMonth() <<
        "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

Date ParseDate(string& date) {
    istringstream date_stream(date);
    return ParseDate(date_stream);
}

Date ParseDate(istream& dateStream) {
    bool ok = true;

    int year;
    ok = ok && (dateStream >> year);
    ok = ok && (dateStream.peek() == '-');
    dateStream.ignore(1);

    int month;
    ok = ok && (dateStream >> month);
    ok = ok && (dateStream.peek() == '-');
    dateStream.ignore(1);

    int day;
    ok = ok && (dateStream >> day);

    if (!ok) {
        throw logic_error("Wrong date format");
    }
    return Date(year, month, day);
}
