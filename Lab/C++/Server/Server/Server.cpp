#include <iostream>
#include <iomanip>
#include <fstream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
using namespace httplib;


void response_raw(const Request& req, Response& res){
    
}
void response(const Request& req, Response& res) {
    
}

int main() {
	Server Strizh;                   
	Strizh.Get("/", response);    
	Strizh.Get("/raw", response_raw);
	Strizh.listen("localhost", 3000); 
}

int GWeather()
{
    string REQ, Adress, API, Data;
    Adress = "/data/2.5/onecall?id=524901&";
    Data = "lat=44.95719&lon=34.11079&exclude=current,minutely,daily,alerts&units=metric&lang=ru&";
    API = "appid=9cb6636a704318008b6d6d02a3c22f84";
    REQ = Adress + Data + API;

    Client Weather("http://api.openweathermap.org");
    auto res = Weather.Get(REQ.c_str());
    if (res) {
        if (res->status == 200)
        {
            json result = res->body;
            return result;
        }
        else
        {
            cout << "Status code: " << res->status << endl;
        }
    }
    else
    {
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
}

string GTime() {
    Client Time("http://worldtimeapi.org");
    auto res = Time.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200)
        {
            string result = res->body;
            return result;
        }
        else
        {
            cout << "Status code: " << res->status << endl;
        }
    }
    else
    {
        auto err = res.error();
        cout << "Error code: " << err << endl;
    }
}



