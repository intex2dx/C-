import numpy as np
import matplotlib.pyplot as plt

files = [
    open("output1.txt"),
    open("output2.txt"),
    open("output4.txt"),
    open("output3.txt")
]

colors = ["darkblue", "red"] * 4

for i in range(4):
    ax_i = plt.subplot(1, 2, i // 2 + 1)
    array = files[i].readlines()
    N_i = []
    times_i = []
    for string in array:
        n, t = map(int, string.split())
        N_i.append(n)
        times_i.append(t)
    ax_i.plot(N_i, times_i, '.', ls="none", color=colors[i], markersize=4)
    ax_i.set_xlabel("N")
    ax_i.set_ylabel(r"$t, мс$")
    if i < 2:
        N_i = np.array(N_i)
        times_i = np.array(times_i)
        a, b = np.polyfit(N_i, times_i, 1)
        ax_i.plot(N_i, b + a * N_i, color="black", ls="--", linewidth=0.5, markersize=4,
                  label=rf"$t = {round(a, 2)} N$")
        ax_i.legend()
    elif i==3:
        N_s_full = np.linspace(1, 1000100, 100)
        ax_i.plot(N_s_full, 0.725*np.log(N_s_full), ls = '--',color="black", linewidth = 0.5, label=r"$t = 0.752 \cdot \ln{N}$")
        ax_i.legend()

plt.show()
