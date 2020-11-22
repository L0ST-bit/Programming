from tkinter import *

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

root.mainloop()