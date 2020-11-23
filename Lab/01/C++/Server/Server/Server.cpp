#include <iostream>
#include <iomanip>
#include <fstream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
using namespace httplib;



json GWeather(){
    string REQ, Adress, API, Data;
    Adress = "/data/2.5/onecall?id=524901&";
    Data = "lat=44.95719&lon=34.11079&exclude=current,minutely,daily,alerts&units=metric&lang=ru&";
    API = "appid=9cb6636a704318008b6d6d02a3c22f84";
    REQ = Adress + Data + API;

    Client Weather("http://api.openweathermap.org");
    auto res = Weather.Get(REQ.c_str());
    if (res) {
        if (res->status == 200){
            json result = res->body;
            return result;
        }
        else{
            cout << "Status code: " << res->status << endl;
        }
    }
    else{
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
}

string GTime() {
    Client Time("http://worldtimeapi.org");
    auto res = Time.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200){
            string result = res->body;
            return result;
        }
        else{
            cout << "Status code: " << res->status << endl;
        }
    }
    else{
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
}

json CacheGenerator(ifstream& ReadCache){
    json RawCache;
    RawCache = GWeather();
    ofstream wc("cache.json");
    cout << "Generating cache..." << endl;
    wc << std::setw(2) << RawCache << std::endl;
    return RawCache;
}

json CacheReader(ifstream& rc){
    json RawCache;
    rc >> RawCache;
    return RawCache;
}

int WhatHour(json cache)
{
    int curr_hour = 100;
    long unixtime;

    json curr_time_full = json::parse(GTime());
    unixtime = curr_time_full["unixtime"];
    for (int i = 0; i < 48; i++)
    {
        long w_unixtime = cache["hourly"][i]["dt"];
        if (unixtime < w_unixtime)
        {
            curr_hour = i;
            break;
        }
    }
    return curr_hour;
}

string StrR(string FindAndRemove, json cache, int curr_hour)
{
    string r1 = "{hourly[i].weather[0].description}";
    string r2 = "{hourly[i].weather[0].icon}";
    string r3 = "{hourly[i].temp}";

    double tempd = cache["hourly"][curr_hour]["temp"];
    string temps = std::to_string(int(round(tempd)));
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];
    string icon = cache["hourly"][curr_hour]["weather"][0]["icon"];

    FindAndRemove.replace(FindAndRemove.find(r1), r1.length(), desk);
    FindAndRemove.replace(FindAndRemove.find(r2), r2.length(), icon);
    FindAndRemove.replace(FindAndRemove.find(r3), r3.length(), temps);
    FindAndRemove.replace(FindAndRemove.find(r3), r3.length(), temps);
    return FindAndRemove;
}

void gen_response(const Request& req, Response& res)
{
    ifstream rc("cache.json");
    json RawCache = CacheReader(rc);
    string temp = RawCache;
    json cache = json::parse(temp);
    int curr_hour = WhatHour(cache);

    if (curr_hour == 100)
    {
        RawCache = CacheGenerator(rc);
        temp = RawCache;
        cache = json::parse(temp);
    }

    string widget;
    ifstream rw("template.html");
    if (rw.is_open())
    {
        getline(rw, widget, '\0');
    }
    else
        cout << "Can`t open template";

    string output = StrR(widget, cache, curr_hour);
    res.set_content(output, "text/html");
}

void gen_response_raw(const Request& req, Response& res)
{
    ifstream rc("cache.json");
    json RawCache = CacheReader(rc);
    string temp = RawCache;
    json cache = json::parse(temp);
    int curr_hour = WhatHour(cache);

    if (curr_hour == 100)
    {
        RawCache = CacheGenerator(rc);
        temp = RawCache;
        cache = json::parse(temp);
    }

    json WeatherData;
    double tempd = cache["hourly"][curr_hour]["temp"];
    int tempi = round(tempd);
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];

    WeatherData["temperature"] = tempi;
    WeatherData["description"] = desk;
    res.set_content(WeatherData.dump(), "text/json");
}

int main() {
    Server Strizh;
    Strizh.Get("/", gen_response);
    Strizh.Get("/raw", gen_response_raw);
    cout << "Start server... OK\n";
    Strizh.listen("localhost", 3000);
}