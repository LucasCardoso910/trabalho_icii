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
            comparacoes.append(int(line[1]))
            movimentos.append(int(line[2]))

        #fig = plt.figure()
        fig, ab = plt.subplots()
        ab.ticklabel_format(style='plain') # para não ficar em notação científica
        ax = plt.gca()
        plt.bar(arquivo, comparacoes)
        ax.set_ylim(0,1.01 * max(comparacoes)) # para definir o limite no eixo y
        plt.title("Gráfico do número de comparações pelo arquivo - " + name)
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número de comparações")
        plt.grid()
        # plt.show()
        plt.savefig("graphs/" + name + "-comparacoes.png", format="png", dpi=fig.dpi)

        #fig = plt.figure()
        fig, ab = plt.subplots()
        ab.ticklabel_format(style='plain')
        ax = plt.gca()
        plt.bar(arquivo, movimentos)
        ax.set_ylim(0,1.01 * max(movimentos))
        plt.title("Gráfico do número de movimentações pelo arquivo - " + name)
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número de movimentações")
        plt.grid()
        # plt.show()
        plt.savefig("graphs/" + name + "-movimentacoes.png", format="png", dpi=fig.dpi)
