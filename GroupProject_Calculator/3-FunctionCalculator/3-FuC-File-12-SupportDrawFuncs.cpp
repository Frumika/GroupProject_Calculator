#include "3-FuC-File-01-Header.h"

void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) // Рисование линии по кордам 2-ух точек
{
    SDL_RenderDrawLine(renderer, x1, HEIGHT - y1, x2, HEIGHT - y2);
}

int calculateFontSize(double scaleX) // Функция чтобы считать размер шрифта для отметок на графике
{
    int calculatedFontSize = 10 * scaleX;
    return calculatedFontSize > MAX_FONT_SIZE ? MAX_FONT_SIZE : calculatedFontSize;
}