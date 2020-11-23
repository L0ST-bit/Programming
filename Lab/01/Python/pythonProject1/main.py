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
