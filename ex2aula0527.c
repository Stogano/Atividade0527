#include <stdio.h>

int main(void) {
  FILE *pArquivo = NULL;

  pArquivo = fopen("quadrado.svg", "w");

  if( pArquivo == NULL ) {
    printf("Erro ao abrir o arquivo!");
    return 1;

  } else {
    fprintf(pArquivo,"<svg version=\"1.1\"");
    fprintf(pArquivo, " width=\"300\" height=\"200\"");
    fprintf(pArquivo, " xmlns=\"http://www.w3.org/2000/svg\">");
    fprintf(pArquivo, "<rect x=\"20\" y=\"30\" width=\"100\" height=\"100\" fill=\"red\" />");
    fprintf(pArquivo, "</svg>");
     
  }
  fclose(pArquivo);
  return 0;
}