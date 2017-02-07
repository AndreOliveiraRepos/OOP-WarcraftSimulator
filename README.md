Warcraft Simulator
===================

Configuração
------------

>**mkgame < linhas> < colunas>** Começar um novo jogo, ex: "mkgame 20 20"
**pop < nome>** Cria a população < nome> sem edifícios nem unidades.
**setf < oque> < linha> < coluna>** Coloca uma fonte de recursos na posição linha e coluna, oque = "min", "ped","flo" , minas, pedra e floresta
**sete < nome> < oque> < linha> < coluna>** Coloca um edifício novo na posição linha e coluna, e pertencendo à população indicada em nome. oque = "quar" -> quartel, "est" -> estábulo, "quin" -> quinta
**setu < nome> < oque> < linha> < coluna>** Acrescenta uma unidade na posição linha e coluna, pertencendo à população indicada em nome. oque = "camp" -> campones, "sold" -> soldado, "cav" -> cavaleiro, "cav" -> campones a cavalo
**load < filename>** Lê comandos do ficheiro designado por filename
**mostra < nome>** Mostra, na zona de informação do ecrã, uma listagem de todos os elementos da população identificada pelo nome.
sair

#Interacção

>**sel < id>** Selecciona o edifício ou unidade com nome id.
**scroll** muda para o modo “scroll”
**next** Avança um instante na simulação.
**next < n>** Simula a passagem de <n> instantes de tempo

Comandos para as unidades e edifícios:
--------------------------------------

>**go < id> < delta_linha> < delta_coluna>**
**goto < id> < linha> < coluna>**
**mina < id> < idfonte>** Ordena à unidade id que vá obter recursos na fonte idfonte
**ataca < id> < idvitima>** Ordena à unidade id que vá atacar a unidade ou edifício idvitima.
**conserta < id> < ide>** Ordena à unidade com identificador id que conserte o edifício com identificador ide.
**deambula < id>** Ordena à unidade com identificador id que deambule.
**mke < id> < oque> < linha> < coluna>** Ordena à unidade id que faça um novo edifício na posição linha e coluna, de acordo com oque: cas → castelo, quar → quartel, est → estábulo, quin → quinta.
**mku < oque>** Manda fazer uma nova unidade, de acordo com oque: camp → camponês, sold → soldado, cav → cavaleiro, cv → camponês a cavalo.
#Comandos para os recursos:
>**ouro < nome> < n>** A população nome recebe n unidades de ouro.
**pedra < nome> < n>** A população nome recebe n unidades de pedra.
**madeira < nome> < n>** A população nome recebe n unidades de madeira.
