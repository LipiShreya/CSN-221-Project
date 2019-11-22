import os
import sys

import matplotlib.pyplot as plt
import seaborn

ROOT = os.path.realpath(os.path.join(os.path.dirname(__file__), "../"))
sys.path.append(ROOT)

from utils import benchmark

data1 = [
    ("Prefetch", [0, 1]),
    ("Distance", [1, 5]),
    ("Hint", [3])
]

data2 = [
    ("Prefetch", [1]),
    ("Distance", [1, 5]),
    ("Hint", [0, 1])
]

frame1 = benchmark(data1, pin_to_cpu=True, repeat=2)
frame2 = benchmark(data2, pin_to_cpu=True, repeat=2)

plt.subplot(211)
seaborn.lineplot(x="Distance", y="Time", hue="Prefetch", data=frame1)

plt.subplot(212)
seaborn.lineplot(x="Distance", y="Time", hue="Hint", data=frame2)

plt.show()