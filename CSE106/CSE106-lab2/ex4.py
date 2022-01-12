import pandas as pd
import matplotlib.pyplot as plt

weather_data = pd.read_csv("weather_data.txt")

l1 = weather_data.actual_min_temp
l2 = weather_data.actual_max_temp
fig, ax = plt.subplots()

#a.
ax.plot(l1, color = 'blue', label = 'line 1')
ax.plot(l2, color = 'red', label = 'line 2')

#b.
plt.figure()
weather_data["actual_precipitation"].plot(kind = 'hist', x = 'actual precipitation', title = "actual precipitation")
plt.show()

