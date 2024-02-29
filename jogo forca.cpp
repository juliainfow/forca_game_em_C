#include <stdio.h>
#include <string.h>

int main() {
    // Palavra a ser adivinhada
    char palavra[20] = "julia";

    // Máximo de tentativas permitidas
    int maxTentativas = 12;

    // Inicialização de variáveis
    char letra;
    int tentativas = 0;
    int acertos = 0;

    // Mascara para exibir letras acertadas e '_' para letras não acertadas
    char mascara[20];

    // Inicializar a máscara com '_' para cada letra da palavra
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

        // Solicitar uma letra ao usuário
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        // Verificar se a letra está na palavra
        int encontrou = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra) {
                encontrou = 1;
                // Atualizar a máscara com a letra correta
                mascara[i] = letra;
                acertos++;
            }
        }

        // Se a letra não estiver na palavra, incrementar as tentativas
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
        printf("Parabéns! Você adivinhou a palavra: %s\n", palavra);
    } else {
        printf("Você foi enforcado! A palavra correta era: %s\n", palavra);
    }

    return 0;
}


