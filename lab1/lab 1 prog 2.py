import numpy as np
import matplotlib.pyplot as plt

files = [
    open("otpt2.txt"),
    open("otpt1.txt")
]

colors = ["darkblue", "red"]

for i in range(2):
    ax_i = plt.subplot(1, 2, i+1)
    array = files[i].readlines()
    N_i = []
    times_i = []
    for string in array:
        n, t = map(int, string.split())
        N_i.append(n)
        times_i.append(t)
    ax_i.plot(N_i, times_i, '.', ls="none", color=colors[i], markersize=6)
    ax_i.set_xlabel("N")
    ax_i.set_ylabel(r"$t, мс$")
    if i < 1:
        N_i = np.array(N_i)
        times_i = np.array(times_i)
        a, b = np.polyfit(N_i, times_i, 1)
        ax_i.plot(N_i, b + a * N_i, color="black", ls="--", linewidth=1, markersize=4,
                  label=rf"$t = {round(a, 2)} N$")
        ax_i.legend()
    else:
        N_s_full = np.linspace(1, 5000, 100)
        ax_i.plot(N_s_full, 0.08*N_s_full**2, ls = '--',color="black", linewidth = 1, label=r"$t = 0.08 \cdot N^2$")
        ax_i.legend()


plt.show()
