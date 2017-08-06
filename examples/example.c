#include "whatlang.h"
#include <stdio.h>
#include <string.h>

uint8_t detect(char* text);

int main (void) {
  char* russian_text = "Это просто невероятно! Сколько я на это потратил времени. Уже хочу поскорее закончить это всё.";
  char* spanish_text = "¡Hola! ¿Que pasa muchacho? ¿Buscas problemas?";

  detect(russian_text);
  detect(spanish_text);

  return 0;
}

uint8_t detect(char* text) {
  struct whatlang_info info;
  char buf[30] = {0};

  printf("\nTEXT: %s\n", text);

  if (whatlang_detect(text, &info) != 0) {
      printf("Failed to detect a language.\n");
      return 1;
  }

  whatlang_script_name(info.script, buf);
  printf("Script: %s\n", buf);

  printf("Lang:\n");
  printf("  eng name: %s\n", buf);

  whatlang_lang_code(info.lang, buf);
  printf("  code: %s\n", buf);

  whatlang_lang_name(info.lang, buf);
  printf("  name: %s\n", buf);

  printf("Confidence: %.4f\n", info.confidence);

  return 0;
}
