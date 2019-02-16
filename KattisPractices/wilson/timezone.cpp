#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>
#include <iomanip>

#define MAX 2147483640

using namespace std;

int clockConvert (string input, bool am) {
    if (input == "noon") {
        return 12*60;
    } else if (input == "midnight") {
        return 0;
    }
    
    if (am) {
        istringstream iss (input);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ':')) {
            tokens.push_back(token);
        }
        
        if (tokens[0] == "12") {
            return 0 + stoi(tokens[1]);
        }
        return stoi(tokens[0])*60 + stoi(tokens[1]);
    } else {
        istringstream iss (input);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ':')) {
            tokens.push_back(token);
        }
        
        if (tokens[0] == "12") {
            return 12*60 + stoi(tokens[1]);
        }
        return (stoi(tokens[0])+12)*60 + stoi(tokens[1]);
    }
}

string minutesToClock(int minutes) {
    minutes %= (24*60);
    if (minutes == 12*60) {
        return "noon";
    } else if (minutes == 0) {
        return "midnight";
    }
    
    int hours = minutes/60;
    int minutes_ = minutes%60;
    if (hours >= 12) {
        if (hours != 12)
            hours -= 12;
        string output = to_string(hours);
        output += ":";
        if (minutes_ < 10) {
            output += '0';
        }
        output += to_string(minutes_);

        output += " p.m.";
        return output;
    } else {
        string output = to_string(hours);
        if (hours == 0) {
            output = to_string(12);
        }
        output += ":";
        if (minutes_ < 10) {
            output += '0';
        }
        output += to_string(minutes_);
        
        output += " a.m.";
        return output;
    }
}

int main () {
    unordered_map<string, double> m;
    m = {
        {"UTC", 0},
        {"GMT", 0},
        {"BST", 1},
        {"IST", 1},
        {"WET", 0},
        {"WEST", 1},
        {"CET", 1},
        {"CEST", 2},
        {"EET", 2},
        {"EEST", 3},
        {"MSK", 3},
        {"MSD", 4},
        {"AST", -4},
        {"ADT", -3},
        {"NST", -3.5},
        {"NDT", -2.5},
        {"EST", -5},
        {"EDT", -4},
        {"CST", -6},
        {"CDT", -5},
        {"MST", -7},
        {"MDT", -6},
        {"PST", -8},
        {"PDT", -7},
        {"HST", -10},
        {"AKST", -9},
        {"AKDT", -8},
        {"AEST", 10},
        {"AEDT", 11},
        {"ACST", 9.5},
        {"ACDT", 10.5},
        {"AWST", 8}
    };
    
    int TC; cin >> TC;
    while (TC--) {
        string time; cin >> time;
        if (time == "noon" || time == "midnight") {
            string timezone; cin >> timezone;
            string timezone2; cin >> timezone2;
            int minutes = clockConvert(time, false);
            minutes -= m[timezone]*60.0;
            minutes += m[timezone2]*60.0;
            if (minutes < 0) {
                minutes += 24*60;
            }
            cout << minutesToClock(minutes) << endl;
        } else {
            string am; cin >> am;
            string timezone; cin >> timezone;
            string timezone2; cin >> timezone2;
            int minutes;
            if (am == "a.m.") {
                minutes = clockConvert(time, true);
            } else {
                minutes = clockConvert(time, false);
            }
            minutes -= m[timezone]*60.0;
            minutes += m[timezone2]*60.0;
            if (minutes < 0) {
                minutes += 24*60;
            }
            cout << minutesToClock(minutes) << endl;
        }
    }
    
}

