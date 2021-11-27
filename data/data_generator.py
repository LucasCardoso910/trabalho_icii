import matplotlib.pyplot as plt
from scipy.stats import linregress
import pandas as pd
import os

lines_in_file = {
    "mes_1": 100,
    "mes_2": 500,
    "mes_3": 1000,
    "mes_4": 5000,
    "mes_5": 10000,
}


def create_graph(x_axis, y_axis, model, name):
    fig = plt.figure()

    plt.ticklabel_format(axis="y", style="sci", scilimits=(0, 0))
    plt.ticklabel_format(axis="x", style="sci", scilimits=(0, 0))

    plt.scatter(x_axis, y_axis, color="blue")

    plt.title(model.title() + " por arquivo - " + name)
    plt.xlabel("Arquivo escolhido")
    plt.ylabel("Número de " + model)

    plt.grid()

    plt.savefig("graphs/" + name + "-" + model + ".png", format="png", dpi=fig.dpi)


def render_mpl_table(data):
    # #f1f1f2 is a light gray
    row_colors = ["#f1f1f2", "w"]
    _, ax = plt.subplots(figsize=(9, 3.75))
    # (9, 3.75) was defined as the best size experimentally
    ax.axis("off")  # We don't want the graph axis showing in the table

    mpl_table = ax.table(
        cellText=data.values,
        bbox=[0, 0, 1, 1],
        colLabels=data.columns,
        cellLoc="center",
    )

    # Set a constant font size to the table
    mpl_table.auto_set_font_size(False)
    mpl_table.set_fontsize(14)

    # Add colors to the table
    for coord, cell in mpl_table._cells.items():
        cell.set_edgecolor("w")
        if coord[0] == 0 or coord[1] < 0:
            cell.set_text_props(weight="bold", color="w")
            cell.set_facecolor("#40466e")
            # #40466e is a dark blue
        else:
            cell.set_facecolor(row_colors[coord[0] % len(row_colors)])

    return mpl_table


def create_table(csv_file):
    headers = ["Mês", "Comparações", "Movimentações"]
    csv_data = pd.read_csv(f"files/{csv_file}", names=headers)

    ax = render_mpl_table(csv_data)
    ax.get_figure().savefig(f"tables/{csv_file.split('.')[0]}.png")

    plt.close("all")


def main():
    csv_files = os.listdir("files")

    for nome_do_arquivo in csv_files:
        name, _ = nome_do_arquivo.split(".")

        with open("files/" + nome_do_arquivo) as f:
            arquivo = []
            comparacoes = []
            movimentos = []

            for line in f:
                line = line.rstrip()
                line = line.split(",")

                arquivo.append(lines_in_file[line[0]])
                comparacoes.append(int(line[1]))
                movimentos.append(int(line[2]))

        create_graph(arquivo, comparacoes, "comparações", name)
        create_graph(arquivo, movimentos, "movimentos", name)
        create_table(nome_do_arquivo)


if __name__ == "__main__":
    main()
