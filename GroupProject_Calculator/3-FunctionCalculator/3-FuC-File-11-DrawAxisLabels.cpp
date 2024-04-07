#include <windows.h>

#include "3-FuC-File-01-Header.h"

void drawAxisLabels(SDL_Renderer *renderer, TTF_Font *font, int fontSize,
    double scaleX, double scaleY, double offsetX, double offsetY) //Отметки на графкие
{
    bool zeroLabelDrawnX = false;

    for (int x = -100; x <= 100; x++) // Цикл для проставления чисел по иксу
    {
        
        int xPos = WIDTH / 2 + x * scaleX + offsetX;
        int yPos = HEIGHT / 2 + offsetY;
        string label = to_string(x);

        if (x == 0 && !zeroLabelDrawnX) // Цикл для проставления чисел по игрику
        {
            drawText(renderer, font, xPos - fontSize / 2, yPos + 5, label, fontSize);
            zeroLabelDrawnX = true;
        } else if (x != 0)
            drawText(renderer, font, xPos - fontSize / 2, yPos + 5, label, fontSize);

        SDL_RenderDrawLine(renderer, xPos, HEIGHT / 2 - 2 + offsetY, xPos, HEIGHT / 2 + 2 + offsetY); //Рисочки
    }

    for (int y = -100; y <= 100; y++) // Цикл для проставления чисел по игрику
    {
        int xPos = WIDTH / 2 + offsetX;
        int yPos = HEIGHT / 2 - y * scaleY + offsetY;
        string label = to_string(y);

        if (y == 0)
            continue;
        drawText(renderer, font, xPos - 20, yPos - fontSize / 2, label, fontSize);

        SDL_RenderDrawLine(renderer, xPos - 2, yPos, xPos + 2, yPos); // Рисочки
    }
}
