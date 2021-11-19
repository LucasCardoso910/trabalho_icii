import matplotlib.pyplot as plt
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


if __name__ == "__main__":
    main()
