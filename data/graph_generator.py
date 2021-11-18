import matplotlib.pyplot as plt
import os

''' 
mes_1, comparacoes, movimentos
mes_2, comparacoes, movimentos
mes_3, comparacoes, movimentos
mes_4, comparacoes, movimentos
mes_5, comparacoes, movimentos
'''

csv_files = os.listdir("files")

for nome_do_arquivo in csv_files:
    name, extension = nome_do_arquivo.split(".")

    with open("files/" + nome_do_arquivo) as f:
        arquivo = []
        comparacoes = []
        movimentos = []
        
        for line in f:
            line = line.rstrip()
            line = line.split(",")

            arquivo.append(line[0])
            comparacoes.append(line[1])
            movimentos.append(line[2])

        fig = plt.figure()
        plt.bar(arquivo, comparacoes)
        plt.title("Gráfico do número de comparações pelo arquivo - " + name)
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número de comparações")
        plt.grid()
        # plt.show()
        plt.savefig("graphs/" + name + "-comparacoes.png", format="png", dpi=fig.dpi)

        fig = plt.figure()
        plt.bar(arquivo, movimentos)
        plt.title("Gráfico do número de movimentações pelo arquivo - " + name)
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número de movimentações")
        plt.grid()
        # plt.show()
        plt.savefig("graphs/" + name + "-movimentacoes.png", format="png", dpi=fig.dpi)
