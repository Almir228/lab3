from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,45000 ,60000 ,75000 ,95000 ,]
time = [8 ,1 ,1 ,7 ,6 ,16 ,22 ,32 ,46 ,71 ,91 ,111 ,278 ,266 ,328 ,611 ,636 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('graphics/task2.2.pdf')
plt.show()