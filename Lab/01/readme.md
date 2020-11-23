<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>

Федеральное государственное автономное образовательное учреждение высшего образования<br>

"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>

ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>

Кафедра компьютерной инженерии и моделирования</p>

<br>

<h3 align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>

<br><br>

<p>студента 1 курса группы ПИ-б-о-202(2)<br>

Стрижиус Даниил Борисович<br>

направления подготовки 09.03.04 "Программная инженерия"</p>

<br><br>

<table>

<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>

<td>(оценка)</td>

<td>Чабанов В.В.</td>

</tr>

</table>

<br><br>

<p align="center">Симферополь, 2020</p>

<hr>

 Цель:
 

1. Закрепить навыки разработки многофайловыx приложений;
2.  Изучить способы работы с API web-сервиса;
3.  Изучить процесс сериализации/десериализации данных в/из json;
4.  Получить базовое представление о сетевом взаимодействии приложений;

## Ход Работы

### Задание 1
Захожу на сайт http://openweathermap.org/ и регестрируюсь. Перехожу в личный кабинет и генерирую API key, назову "main".
API: 9cb6636a704318008b6d6d02a3c22f84

Затем подставляю ключ в ссылку и получаю:
http://api.openweathermap.org/data/2.5/forecast?id=524901&appid=9cb6636a704318008b6d6d02a3c22f84

Далее необходимо получить прогноз погоды для Симферополя на русском языке с почасовым интервалом необходимо, поэтому отправляю запрос:
http://api.openweathermap.org/data/2.5/onecall?lat=44.9698623&lon=34.1329217&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=9cb6636a704318008b6d6d02a3c22f84
Получаю результат в виде JSON кода.

![Рис.1.1](./01/Pictures/1.7.png/)

<center> <i> Рисунок 1.1. Результат с сайта. </center>

Далее перехожу на сайт: http://http://worldtimeapi.org/ . Затем необходимо получить текущее время в Симферополе в виде JSON кода. Ввожу следуйщий запрос:
http://worldtimeapi.org/api/timezone/Europe/Simferopol

![Рис.1.2](./01/Pictures/z2.png)

<center> <i> Рисунок 1.2. Результат с сайта. </center>
  
  ### Задание 2 
  
  ### Полный исходный код сервера:
  
  ```c++
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
using namespace httplib;



json GWeather()
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

json CacheGenerator(ifstream& ReadCache)
{
    json RawCache;
    RawCache = GWeather();
    ofstream wc("cache.json");
    cout << "Generating cache..." << endl;
    wc << std::setw(2) << RawCache << std::endl;
    return RawCache;
}

json CacheReader(ifstream& rc)
{
    json RawCache;
    rc >> RawCache;
    cout << "Cache succesfully read" << endl;
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

    json WData;
    double tempd = cache["hourly"][curr_hour]["temp"];
    int tempi = round(tempd);
    string desk = cache["hourly"][curr_hour]["weather"][0]["description"];

    WData["temperature"] = tempi;
    WData["description"] = desk;
    res.set_content(WData.dump(), "text/json");
}

int main() {
    Server Strizh;
    Strizh.Get("/", gen_response);
    Strizh.Get("/raw", gen_response_raw);
    cout << "Start server... OK\n";
    Strizh.listen("localhost", 3000);
}
  ```

### Полный исходный код клиента:
 ```c++
 from tkinter import *
import json
import requests


def WeatherReload():
	r = requests.get('http://localhost:3000/raw').content.decode("UTF8")
	weather = json.loads(r)
	desc.config(text=str(weather["description"]))
	temp.config(text=str(weather["temperature"]) + "°C")


root = Tk()
root.title("Погода")
root.pack_propagate(0)

topF = Frame(root, bg="#ffcd57", height=40)
topF.pack(fill=X)

midF = Frame(root, bg="#ffffff")
midF.pack(expand=True, fill=X)

BotF = Frame(root, bg="#ffcd57", height=40)
BotF.pack(side=BOTTOM, fill=X)


city = Label(topF, font=("Times New Roman", 14), text="Симферополь", bg="#ffcd57")
desc = Label(topF, font=("Times New Roman", 14), bg="#ffcd57")
temp = Label(midF, font=("Times New Roman", 54), bg="white")

city.pack()
desc.pack()
temp.pack(expand=True)

WeatherReload()
root.mainloop()

  ```
  Скриншот графического интерфейса:
  
  ![Рис.2.1](./01/Pictures/tkinter.png)
  
  <center> <i> Рисунок 2.1. Графический интерфейс. </center>
	
  Скриншот браузера с виджетом.
 
 ![Рис. 2.2](./01/Pictures/vid.png)

<center> <i> Рисунок 1.3. Браузер с виджетом. </center>
  
  ## Вывод по работе. 

Цель работы достигнута. А также были закреплены навыки разработки многофайловых приложений, получены базовые представление о сетевом взаимодействии приложений.
Было выполнено:
- Создание сервера на языке С++ обращающегося к openweathermap.com и возвращающий виджет или описание и температуру в формате json
- Приложение с графическим интерфейсом, написанное на языке Python с использованием библиотеки Tkinter
