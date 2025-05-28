#include <stdio.h>

int main(void) {
    char nArquivo[100];
    int x,y,largura,altura;

    printf("Digite o nome do arquivo");
    scanf("%s",nArquivo);
    printf("Digite o x do arquivo ");
    scanf("%d",&x);
    printf("Digite o y do arquivo");
    scanf("%d",&y);
    printf("Digite a largura");
    scanf("%d",&largura);
    printf("Digite altura do arquivo");
    scanf("%d",&altura);

  FILE *pArquivo = NULL;

  pArquivo = fopen(nArquivo, "w");

  if( pArquivo == NULL ) {
    printf("Erro ao abrir o arquivo!");
    return 1;

  } else {
    fprintf(pArquivo,"<svg version=\"1.1\"");
    fprintf(pArquivo, " width=\"%d\" height=\"%d\"", largura+x, altura+y);
    fprintf(pArquivo, " xmlns=\"http://www.w3.org/2000/svg\">");
    fprintf(pArquivo, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"blue\" />", x, y, largura, altura);
    fprintf(pArquivo, "</svg>");
     
  }
  fclose(pArquivo);
  return 0;
}