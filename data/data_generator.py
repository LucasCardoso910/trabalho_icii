import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import six
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


def render_mpl_table(
    data,
    col_width=3.0,
    row_height=0.625,
    font_size=14,
    header_color="#40466e",
    row_colors=["#f1f1f2", "w"],
    edge_color="w",
    bbox=[0, 0, 1, 1],
    header_columns=0,
    ax=None,
):
    if ax is None:
        size = (np.array(data.shape[::-1]) + np.array([0, 1])) * np.array(
            [col_width, row_height]
        )
        _, ax = plt.subplots(figsize=size)
        ax.axis("off")

    mpl_table = ax.table(
        cellText=data.values,
        bbox=bbox,
        colLabels=data.columns,
        cellLoc="center",
    )

    mpl_table.auto_set_font_size(False)
    mpl_table.set_fontsize(font_size)

    for k, cell in six.iteritems(mpl_table._cells):
        cell.set_edgecolor(edge_color)
        if k[0] == 0 or k[1] < header_columns:
            cell.set_text_props(weight="bold", color="w")
            cell.set_facecolor(header_color)
        else:
            cell.set_facecolor(row_colors[k[0] % len(row_colors)])

    return mpl_table


def create_table(csv_file):
    headers = ["Mês", "Comparações", "Movimentações"]
    csv_data = pd.read_csv(f"files/{csv_file}", names=headers)

    ax = render_mpl_table(csv_data, header_columns=0)
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
