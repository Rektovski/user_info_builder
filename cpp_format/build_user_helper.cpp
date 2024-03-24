#include "../h_format/build_user_helper.h"
#include <iostream>
#include "sstream"
using namespace std;

pair<bool, char> check_if_there_is_only_digits(const string &test_case) {
    pair<bool, char> Result;
    Result.first = true;
    Result.second = ' ';
    for (char c: test_case) {
        if (!(c >= '0' && c <= '9')) {
            Result.first = false;
            Result.second = c;
            break;
        }
    }
    return Result;
}

long long string_To_Integer(const string &test_case) {
    long long result;
    stringstream SS;
    SS << test_case, SS >> result;
    return result;
}