#include <stdio.h>
#include <ctype.h>

#define LINHAS 9
#define COLUNAS 11

char labirinto[LINHAS][COLUNAS + 1] = {
    "###########",
    "#         #",
    "# ####### #",
    "#       # #",
    "####### # #",
    "#       # #",
    "# ####### #",
    "#        X#",
    "###########"
};

void mostrarLabirinto(int jogadorLinha, int jogadorColuna)
{
    int i;
    int j;

    printf("\n===============================\n");
    printf("      LABIRINTO RECURSIVO\n");
    printf("===============================\n\n");

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (i == jogadorLinha && j == jogadorColuna)
            {
                printf("P");
            }
            else
            {
                printf("%c", labirinto[i][j]);
            }
        }

        printf("\n");
    }
}

int encontrarSaida(
    int linha,
    int coluna,
    int visitado[LINHAS][COLUNAS]
)
{
    if (linha < 0 || linha >= LINHAS ||
        coluna < 0 || coluna >= COLUNAS)
    {
        return 0;
    }

    if (labirinto[linha][coluna] == '#')
    {
        return 0;
    }

    if (visitado[linha][coluna] == 1)
    {
        return 0;
    }

    if (labirinto[linha][coluna] == 'X')
    {
        return 1;
    }

    visitado[linha][coluna] = 1;

    if (encontrarSaida(linha - 1, coluna, visitado))
    {
        return 1;
    }

    if (encontrarSaida(linha + 1, coluna, visitado))
    {
        return 1;
    }

    if (encontrarSaida(linha, coluna - 1, visitado))
    {
        return 1;
    }

    if (encontrarSaida(linha, coluna + 1, visitado))
    {
        return 1;
    }

    return 0;
}

void verificarCaminho(int jogadorLinha, int jogadorColuna)
{
    int visitado[LINHAS][COLUNAS] = {0};

    printf("\nProcurando um caminho ate a saida...\n");

    if (encontrarSaida(
        jogadorLinha,
        jogadorColuna,
        visitado
    ))
    {
        printf("DICA: Existe um caminho ate a saida!\n");
    }
    else
    {
        printf("DICA: Nao existe um caminho ate a saida.\n");
    }
}

void mostrarInstrucoes(void)
{
    printf("\nCONTROLES:\n");
    printf("C - mover para cima\n");
    printf("B - mover para baixo\n");
    printf("D - mover para direita\n");
    printf("E - mover para esquerda\n");
    printf("H - verificar se existe caminho ate a saida\n");
    printf("Q - sair do jogo\n");
}

int main(void)
{
    int jogadorLinha = 1;
    int jogadorColuna = 1;

    int novaLinha;
    int novaColuna;

    int movimentos = 0;

    char comando;

    printf("=================================\n");
    printf("       LABIRINTO RECURSIVO\n");
    printf("=================================\n");

    printf("\nSeu objetivo e encontrar a saida do labirinto.\n");
    printf("A saida e representada pela letra X.\n");

    mostrarInstrucoes();

    while (1)
    {
        mostrarLabirinto(
            jogadorLinha,
            jogadorColuna
        );

        if (labirinto[jogadorLinha][jogadorColuna] == 'X')
        {
            printf("\n=================================\n");
            printf("           PARABENS!\n");
            printf("=================================\n");

            printf("\nVoce encontrou a saida!\n");
            printf("Movimentos realizados: %d\n", movimentos);

            break;
        }

        printf("\nDigite seu comando: ");
        scanf(" %c", &comando);

        comando = toupper(comando);

        if (comando == 'Q')
        {
            printf("\nJogo encerrado.\n");
            break;
        }

        if (comando == 'H')
        {
            verificarCaminho(
                jogadorLinha,
                jogadorColuna
            );

            continue;
        }

        novaLinha = jogadorLinha;
        novaColuna = jogadorColuna;

        switch (comando)
        {
            case 'C':
                novaLinha--;
                break;

            case 'B':
                novaLinha++;
                break;

            case 'D':
                novaColuna++;
                break;

            case 'E':
                novaColuna--;
                break;

            default:
                printf("\nComando invalido!\n");
                continue;
        }

        if (labirinto[novaLinha][novaColuna] == '#')
        {
            printf("\nVoce bateu em uma parede!\n");
            continue;
        }

        jogadorLinha = novaLinha;
        jogadorColuna = novaColuna;

        movimentos++;
    }

    printf("\nObrigado por jogar!\n");

    return 0;
}
