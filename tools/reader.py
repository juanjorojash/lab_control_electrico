import pandas as pd
from matplotlib import pyplot as plt

data = pd.read_csv("test1.csv",names=['time','d1','a1','d2','a2','r1','r2','r3','r4','r5'],index_col=False)

data = data[data.time < 20]

print(data.head())

plt.figure()
plt.plot(data.time,data.a1)
plt.plot(data.time,data.d1)
plt.show()

plt.figure()
plt.plot(data.time,data.a2)
plt.plot(data.time,data.d2)
plt.show()

plt.figure()
plt.plot(data.time,data.d1)
plt.plot(data.time,data.d2 + 2 )
plt.plot(data.time,data.r1 + 4)
plt.show()