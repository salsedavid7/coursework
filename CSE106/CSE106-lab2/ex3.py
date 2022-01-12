#python3 ex3.py
import pandas as pd

weather_data = pd.read_csv("weather_data.txt")

#a.
maxPrecipitationDate = weather_data.loc[weather_data.actual_precipitation == weather_data.actual_precipitation.max(), "date"]
print("Highest actual precipitation date:", maxPrecipitationDate)
print("\n")
#b.
avgTemp = weather_data["actual_max_temp"].loc[0:30].mean()
print("Average temp for July 2014:", avgTemp)
print("\n")
#c.
actualMaxTemp = weather_data.loc[weather_data.actual_max_temp == weather_data.record_max_temp, "date"]
print("Max temp days: \n", actualMaxTemp)
print("\n")
#d.
total_precipitation_in_october = (weather_data['date'] >= '2014-10-01' ) & (weather_data['date'] <= '2014-10-31' )
print(f"Total precipitation in October 2014: {weather_data.loc[total_precipitation_in_october]}")
print("\n")
#e.
condition = weather_data[(weather_data.actual_min_temp < 60) & (weather_data.actual_max_temp > 90)]
print("Days below 60 and above 90 in the same day: ", condition)