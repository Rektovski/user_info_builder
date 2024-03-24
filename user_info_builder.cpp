#include "user_info_builder.h"
#include <iostream>
#include "fstream"

using namespace std;

void test_name(string name){
    for(int c: name){
        if(!((c>='a' && c<='z') || (c>='A' && c<='Z'))){
            cerr<<"The name <<"<<name<<">> must contain only letters\n";
            break;
        }
    }
}
void test_surname(string surname){
    for(int c: surname){
        if(!((c>='a' && c<='z') || (c>='A' && c<='Z'))){
            cerr<<"The surname <<"<<surname<<">> must contain only letters\n";
            break;
        }
    }
}
void test_day(int day){
    if(day>31){
        cerr<<"A day <<"<<day<<">> can't be more then 31\n";
    }
}
void test_month(int month){
    if(month>12){
        cerr<<"A month <<"<<month<<">> can't be more then 12\n";
    }
}
void test_year(int year){
    if(!(year<2024 && year>=1900)){
        cerr<<"Thee year <<"<<year<<">> is not valid\n";
    }
}
void test_id(long long id){
    string idString = to_string(id);
    if(idString.length() != 11){
        cerr<<"Thee id <<"<<id<<">> id is not valid\n";
    }
}
void build_user_info(){
    string fileName = "user_info.txt";
    ofstream makeFile;
    makeFile.open(fileName);
    string name, surname;
    int day, month, year;
    long long id = 0;
    cin>>name;
    test_name(name);

    cin>>surname;
    test_surname(surname);

    cin>>day;
    test_day(day);

    cin>>month;
    test_month(month);

    cin>>year;
    test_year(year);

    cin>>id;
    test_id(id);

    makeFile<<"Firstname: "<<name<<endl;
    makeFile<<"Surname: "<<surname<<endl;
    makeFile << "Date: ";
    if (day<10) makeFile<<"0";
    makeFile<<day<<"/";
    if (month<10) makeFile<<"0";
    makeFile<<month <<"/"<<year<<endl;
    makeFile<<"ID: "<<id<<endl;
}