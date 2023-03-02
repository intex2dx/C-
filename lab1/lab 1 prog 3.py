import numpy as np
import matplotlib.pyplot as plt

files = [
    open("out01.txt", "r"),
    open("out02.txt", "r"),
    open("outA1.txt", "r"),
    open("outA2.txt", "r"),
    open("outB1.txt", "r"),
    open("outB2.txt", "r"),
    open("outC1.txt", "r"),
    open("outC2.txt", "r")
]

titles = ['default strategy'] * 2 + ['strategy A'] * 2 + ['strategy B'] * 2 + ['strategy C'] * 2

colors = ["darkblue", "red"] * 4

for i in range(8):
    ax_i = plt.subplot(2, 2, i // 2 + 1)
    array = files[i].readlines()
    N_i = []
    times_i = []
    for string in array:
        n, t = map(int, string.split())
        N_i.append(n)
        times_i.append(t)
    ax_i.plot(N_i, times_i, '.', ls="none", color=colors[i], markersize=4)
    N_i = np.array(N_i)
    times_i = np.array(times_i)
    a, b = np.polyfit(N_i, times_i, 1)
    print(a, b)
    ax_i.plot(N_i, b + a * N_i, color="black", ls="--", linewidth=0.5, markersize=4, label=rf"$t = {round(a, 2)} N$")
    ax_i.title.set_text(titles[i])
    ax_i.set_xlabel("N")
    ax_i.set_ylabel(r"$t, мс$")
    ax_i.legend()

plt.show()
