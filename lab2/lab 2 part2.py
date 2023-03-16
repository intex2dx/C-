import numpy as np
import matplotlib.pyplot as plt

files = [
    open("part 2 output.txt"),
    open("part 2 swaps.txt")
]

titles = ['asimptotic'] + ["swaps"]

colors = ["darkblue"]*2

for i in range(2):
    ax_i = plt.subplot(1,2,i+1)
    array = files[i].readlines()
    N_i = []
    times_i = []
    for string in array:
        n, t = map(int, string.split())
        N_i.append(n)
        times_i.append(t)
    ax_i.plot(N_i, times_i, '.', ls="none", color=colors[i], markersize=6)
    # N_i = np.array(N_i)
    # times_i = np.array(times_i)
    # a, b = np.polyfit(N_i, times_i, 1)
    # print(a, b)
    # ax_i.plot(N_i, b + a * N_i, color="black", ls="--", linewidth=1, markersize=4, label=rf"$t = {round(a, 2)} N$")
    # ax_i.title.set_text(titles[i])
    ax_i.set_xlabel("N")
    ax_i.set_ylabel(r"$t, мс$")
    ax_i.grid(True)
    ax_i.legend()

plt.show()