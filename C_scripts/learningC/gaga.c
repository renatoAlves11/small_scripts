#include <stdio.h>
#include <string.h>

// Função para encontrar a maior subsequência comum entre duas strings
int LCS(char* seq1, char* seq2, int len1, int len2, char* lcs_subseq) {
    int dp[len1 + 1][len2 + 1];
    
    // Inicializar matriz com zeros
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }

    // Preencher a matriz com os valores da subsequência comum máxima
    int max_length = 0, end_idx_seq1 = 0;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                    end_idx_seq1 = i;
                }
            }
        }
    }

    // Construir a subsequência comum a partir da matriz dp
    if (max_length > 0) {
        strncpy(lcs_subseq, &seq1[end_idx_seq1 - max_length], max_length);
        lcs_subseq[max_length] = '\0';
    }

    return max_length;
}

// Função para reverter uma string
void reverse(char* str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    // Definir o tamanho máximo das sequências de DNA
    char seq1[100], seq2[100];
    
    // Entrada das sequências de DNA pelo usuário
    printf("Digite a primeira sequência de DNA: ");
    scanf("%s", seq1);
    
    printf("Digite a segunda sequência de DNA: ");
    scanf("%s", seq2);
    
    // Obter o tamanho das sequências
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    // Arrays para armazenar as subsequências comuns
    char lcs_subseq[100];
    char lcs_rev_subseq[100];

    // Encontrar a maior subsequência comum normal
    int lcs_len = LCS(seq1, seq2, len1, len2, lcs_subseq);
    
    // Inverter a segunda sequência para buscar subsequência reversa
    reverse(seq2, len2);

    // Encontrar a maior subsequência comum com a sequência reversa
    int lcs_rev_len = LCS(seq1, seq2, len1, len2, lcs_rev_subseq);

    // Exibir o resultado com a maior subsequência encontrada
    if (lcs_len >= lcs_rev_len) {
        printf("Maior subsequência comum: %s\n", lcs_subseq);
        printf("Tamanho: %d\n", lcs_len);
    } else {
        printf("Maior subsequência comum reversa: %s\n", lcs_rev_subseq);
        printf("Tamanho: %d\n", lcs_rev_len);
    }

    return 0;
}
