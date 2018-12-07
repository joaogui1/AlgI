import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline, BSpline

line = ''
COLORS = ['g', 'r', 'b', 'k', 'y', 'm']
DS_VALUES = list()
N_SIZES = [100, 1000, 10000, 100000]
with open("saida.txt", "r") as inp:
    for _ in range(1):
        while True:
            line = inp.readline()
            GRAPH_TITLE = line.replace("Tabela", "Gráfico")
            line = inp.readline()
            for i in range(6):
                DS_VALUES = list(inp.readline().split())
                DS_VALUES[1:] = [float(x) for x in DS_VALUES[1:]]
                plt.plot(N_SIZES, DS_VALUES[1:], label=DS_VALUES[0], color=COLORS[i])

            inp.readline()
            plt.xscale("log")
            plt.yscale("log")
            plt.title(GRAPH_TITLE)
            plt.legend()
            plt.show()
            break
