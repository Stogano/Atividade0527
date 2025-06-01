#include <stdio.h>
#include <string.h>

int abertura(FILE *arquivo) {
    int retorno = fprintf(arquivo, "<svg version=\"1.1\" ");
    if (retorno < 0) return 0;

    retorno = fprintf(arquivo, "width=\"300\" height=\"200\" ");
    if (retorno < 0) return 0;

    retorno = fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">");
    if (retorno < 0) return 0;

    return 1;
}

int fechamento(FILE *arquivo) {
    int retorno = fprintf(arquivo, "</svg>");
    if (retorno < 0) return 0;

    return 1;
}

void retangulo(FILE *arquivo, int x, int y, int largura, int altura, const char *cor) {
    fprintf(arquivo, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" />\n",
            x, y, largura, altura, cor);
}

void circulo(FILE *arquivo, int cx, int cy, int r, const char *cor) {
    fprintf(arquivo, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n",
            cx, cy, r, cor);
}

void linha(FILE *arquivo, int x1, int y1, int x2, int y2, const char *cor) {
    fprintf(arquivo, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" />\n",
            x1, y1, x2, y2, cor);
}

void texto(FILE *arquivo, int x, int y, const char *cor, const char *conteudo) {
    fprintf(arquivo, "<text x=\"%d\" y=\"%d\" fill=\"%s\">%s</text>\n",
            x, y, cor, conteudo);
}

int main() {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo SVG (ex: desenho.svg): ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

 
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;


    if (strstr(nomeArquivo, ".svg") == NULL) {
        strcat(nomeArquivo, ".svg");
    }

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    if (!abertura(arquivo)) {
        printf("Erro ao escrever abertura do SVG.\n");
        fclose(arquivo);
        return 1;
    }

    char comando[20];
    while (1) {
        printf("Digite comando (r para retangulo, c para circulo, l para linha, t para texto ou F para finalizar): ");
        scanf("%s", comando);

        if (strcmp(comando, "F") == 0) break;

        if (strcmp(comando, "r") == 0) {
            int x, y, largura, altura;
            char cor[20];
            printf("Digite o x do arquivo\n");
            printf("Digite o y do arquivo\n");
            printf("Digite a largura\n");
            printf("Digite altura do arquivo\n");
            printf("Digite Cor do arquivo\n");

            scanf("%d %d %d %d %s", &x, &y, &largura, &altura, cor);
            retangulo(arquivo, x, y, largura, altura, cor);
        } else if (strcmp(comando, "c") == 0) {
            int cx, cy, r;
            char cor[20];
            printf("Digite o centro x do arquivo\n");
            printf("Digite o centro y do arquivo\n");  
            printf("Digite a raio\n");       
            printf("Digite a cor\n");
            scanf("%d %d %d %s", &cx, &cy, &r, cor);
            circulo(arquivo, cx, cy, r, cor);
        } else if (strcmp(comando, "l") == 0) {
            int x1, y1, x2, y2;
            char cor[20];
            printf("Digite o x1 do arquivo\n");
            printf("Digite o y1 do arquivo\n");  
            printf("Digite o x2 do arquivo\n");
            printf("Digite o y2 do arquivo\n");      
            printf("Digite a cor\n");
            scanf("%d %d %d %d %s", &x1, &y1, &x2, &y2, cor);
            linha(arquivo, x1, y1, x2, y2, cor);
        } else if (strcmp(comando, "t") == 0) {
            int x, y;
            char cor[20], conteudo[100];
            printf("Digite o x do arquivo\n");
            printf("Digite o y do arquivo\n");      
            printf("Digite a cor\n");
            printf("Digite o conteudo\n");
            scanf("%d %d %s", &x, &y, cor);
            getchar(); 
            fgets(conteudo, 100, stdin); 
            conteudo[strcspn(conteudo, "\n")] = 0;
            texto(arquivo, x, y, cor, conteudo);
        } else {
            printf("Comando inválido!\n");
        }
    }

    if (!fechamento(arquivo)) {
        printf("Erro ao fechar SVG.\n");
    }

    fclose(arquivo);
    printf("Arquivo '%s' gerado com sucesso!\n", nomeArquivo);
    return 0;
}
