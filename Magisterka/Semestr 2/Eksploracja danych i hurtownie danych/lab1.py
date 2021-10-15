# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 09:58:24 2021

@author: Mariusz Jędrzejewski
@lab: 1
"""

import pandas as pan
import random

# Zadanie 1
zarobki_file = pan.read_csv("zarobki200.csv")
pan.set_option("display.max_columns", None)

print(zarobki_file.describe())

print()
print(zarobki_file[["plec","rasa","kraj"]].head(12))

print()
zarobki_file.to_html("zarobki200.html")
print(zarobki_file.loc[80:100, ["zatrudnienie","zawod"]])
print()
print(zarobki_file.loc[80:100, "zatrudnienie":"zawod"])
print()
print(zarobki_file.iloc[80:100, 1:5])
print()

input("Press Enter to continue")

# Zadanie 2
print()
print(zarobki_file[zarobki_file["kraj"] == 'Mexico'])
print()
print("Ilosc wierszy: " + str(len(zarobki_file[zarobki_file["kraj"] == 'Mexico'])))
print()
print(zarobki_file[["rasa","plec","kraj"]].tail(20).replace("Female", "K").replace("Male", "M").rename(columns={"plec": "K/M"}))
zarobki_file[zarobki_file["zarobki"] > ">50"].to_json("zarobki200.json", orient='records')
print()

zarobki_dict = pan.read_csv("zarobki200.csv").to_dict()

print(zarobki_dict.groupby(["wiek"].mean()))
print()
print(zarobki_dict.groupby(by=["zawod"]).size())
