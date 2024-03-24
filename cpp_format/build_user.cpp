#include <iostream>
#include "../h_format/build_user.h"
#include "../h_format/build_user_helper.h"
#include "fstream"

using namespace std;

// errors
string name_error = "Name contains specific letter that is not allowed! Letter: \"";
string surname_error = "Surname contains specific letter that is not allowed! Letter: \"";
string day_error = "Day contains specific letter that is not allowed! Letter: \"";
string day_range_error = "Number of day is not available into the 1 to 31 range. Number: \"";
string month_error = "Month contains specific letter that is not allowed! Letter: \"";
string month_range_error = "Number of month is not available into the 1 to 12 range. Number: \"";
string year_error = "Year contains specific letter that is not allowed! Letter: \"";
string year_range_error = "Number of Year is not available into the 1990 to 2024 range. Number: \"";
string ID_size_error = "ID must contain only 11 characters! Your ID was: \"";
string ID_error = "ID contains specific letter that is not allowed! Letter: \"";

ofstream f;
string tab = "    ";
string name, surname, day, month, year, ID;

void test_name() {
    cin >> name;
    for (char c: name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            throw runtime_error(name_error + c + "\"");
        }
    }
    if(name[0]>='a' && name[0]<='z')name[0]-=32;
    f << "{\n" + tab + R"("firstname": ")" + name + "\",\n" + tab + R"("surname": ")";
}

void test_surname() {
    cin >> surname;
    for (char c: surname) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            throw runtime_error(surname_error + c + "\"");
        }
    }
    if(surname[0]>='a' && surname[0]<='z')surname[0]-=32;
    f << surname + "\",\n" + tab + R"("date": ")";
}

void test_day() {
    cin >> day;
    pair<bool, char> check = check_if_there_is_only_digits(day);
    if (!check.first) {
        throw runtime_error(day_error + check.second + "\"");
    }
    long long day_integer = string_To_Integer(day);
    if (!(day_integer >= 1 && day_integer <= 31)) {
        throw runtime_error(day_range_error + day + "\"");
    }
    day_integer < 10 ? f << 0 << day_integer << "/" : f << day_integer << "/";
}

void test_month() {
    cin >> month;
    pair<bool, char> check = check_if_there_is_only_digits(month);
    if (!check.first) {
        throw runtime_error(month_error + check.second + "\"");
    }
    long long month_integer = string_To_Integer(month);
    if (!(month_integer >= 1 && month_integer <= 12)) {
        throw runtime_error(month_range_error + month + "\"");
    }
    month_integer < 10 ? f << 0 << month_integer << "/" : f << month_integer << "/";
}

void test_year() {
    cin >> year;
    pair<bool, char> check = check_if_there_is_only_digits(year);
    if (!check.first) {
        throw runtime_error(year_error + check.second + "\"");
    }
    long long year_integer = string_To_Integer(year);
    if (!(year_integer >= 1990 && year_integer <= 2024)) {
        throw runtime_error(year_range_error + year + "\"");
    }
    f << year_integer << "\",\n" + tab + R"("id": ")";
}

void test_ID() {
    cin >> ID;
    if (ID.size() != 11) {
        throw runtime_error(ID_size_error + ID + "\"");
    }
    pair<bool, char> check = check_if_there_is_only_digits(ID);
    if(!check.first) {
        throw runtime_error(ID_error + check.second + "\"");
    }
    f<<ID+"\"\n}";
}

void test_info() {
    test_name();
    test_surname();
    test_day();
    test_month();
    test_year();
    test_ID();
}

void build_info() {
    f.open("user_info.json");
    test_info();
    f.close();
}