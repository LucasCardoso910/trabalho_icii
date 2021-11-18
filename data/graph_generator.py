import matplotlib.pyplot as plt

''' 
mes_1, comparacoes, movimentos
mes_2, comparacoes, movimentos
mes_3, comparacoes, movimentos
mes_4, comparacoes, movimentos
mes_5, comparacoes, movimentos
'''
for i in range(0,5):
    nome_do_arquivo = 

    with open(nome_do_arquivo) as f:
        arquivo = []
        comparacoes = []
        movimentos = []
        
        for line in f:
            line = line.rstrip()
            line = line.split(",")

            arquivo.append(line[0])
            comparacoes.append(line[1])
            movimentacoes(line[2])


        plt.bar(arquivo,comparacoes)
        plt.title("Gráfico do número de comparações pelo arquivo")
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número dd comparações")
        plt.grid()
        plt.show()

        plt.bar(arquivo,movimentos)
        plt.title("Gráfico do número de movimentações pelo arquivo")
        plt.xlabel("Arquivo escolhido")
        plt.ylabel("Número dd movimentações")
        plt.grid()
        plt.show()
