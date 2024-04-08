#include "3-FuC-File-01-Header.h"

void renderGraph(SDL_Renderer *renderer, function<double(double)> ChosenFunc, TTF_Font *font, int fontSize,
    double scaleX, double scaleY, double offsetX, double offsetY)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderDrawLine(renderer, 0, HEIGHT / 2 + offsetY, WIDTH, HEIGHT / 2 + offsetY);
    SDL_RenderDrawLine(renderer, WIDTH / 2 + offsetX, 0, WIDTH / 2 + offsetX, HEIGHT);

    drawAxisLabels(renderer, font, fontSize, scaleX, scaleY, offsetX, offsetY);

    if (scaleX > 0 && scaleY > 0)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (int x = 0; x < WIDTH - 1; x++) // Рисуем график
        {
            double xValue = (x - WIDTH / 2 - offsetX) / scaleX;
            double xNextValue = ((x + 1) - WIDTH / 2 - offsetX) / scaleX;

            if ((xValue <= 0 && xNextValue >= 0) || (xValue >= 0 && xNextValue <= 0)) // Скипаем ось
            {
                continue;
            }
            
            double y1 = ChosenFunc((x - WIDTH / 2 - offsetX) / scaleX) * scaleY - offsetY;
            double y2 = ChosenFunc((x + 1 - WIDTH / 2 - offsetX) / scaleX) * scaleY - offsetY;
            drawLine(renderer, x, y1 + HEIGHT / 2, x + 1, y2 + HEIGHT / 2);
        }
    }

    SDL_RenderPresent(renderer); // Отображаем
}
