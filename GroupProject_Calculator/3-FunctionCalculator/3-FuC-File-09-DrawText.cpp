#include "3-FuC-File-01-Header.h"

void drawText(SDL_Renderer *renderer, TTF_Font *font, int x, int y, const string &text, int fontSize) //Отметки на осях
{
    SDL_Color color = {0, 0, 0, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    
    SDL_Rect dstrect = {x, y, texW, texH};

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
