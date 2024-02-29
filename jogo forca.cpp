#include <stdio.h>
#include <string.h>

int main() {
    // Palavra a ser adivinhada
    char palavra[20] = "julia";

    // M�ximo de tentativas permitidas
    int maxTentativas = 12;

    // Inicializa��o de vari�veis
    char letra;
    int tentativas = 0;
    int acertos = 0;

    // Mascara para exibir letras acertadas e '_' para letras n�o acertadas
    char mascara[20];

    // Inicializar a m�scara com '_' para cada letra da palavra
    for (int i = 0; i < strlen(palavra); i++) {
        mascara[i] = '_';
    }

    // Loop principal do jogo
    while (tentativas < maxTentativas && acertos < strlen(palavra)) {
        // Exibir estado atual da palavra
        printf("Palavra: ");
        for (int i = 0; i < strlen(palavra); i++) {
            printf("%c ", mascara[i]);
        }

        // Solicitar uma letra ao usu�rio
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        // Verificar se a letra est� na palavra
        int encontrou = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra) {
                encontrou = 1;
                // Atualizar a m�scara com a letra correta
                mascara[i] = letra;
                acertos++;
            }
        }

        // Se a letra n�o estiver na palavra, incrementar as tentativas
        if (!encontrou) {
            tentativas++;
            printf("Letra incorreta. Tentativas restantes: %d\n", maxTentativas - tentativas);
        } else {
            printf("Letra correta!\n");
        }

        // Pular uma linha para melhorar a legibilidade
        printf("\n");
    }

    // Verificar se o jogador venceu ou perdeu
    if (acertos == strlen(palavra)) {
        printf("Parab�ns! Voc� adivinhou a palavra: %s\n", palavra);
    } else {
        printf("Voc� foi enforcado! A palavra correta era: %s\n", palavra);
    }

    return 0;
}


