#include "3-FuC-File-01-Header.h"

double scaleX = 75.0; //Масштаб по x
double scaleY = 75.0; //Масштаб по y
double offsetX = 0.0; // Смещение по оси X
double offsetY = 0.0; // Смещение по оси Y
bool isDragging = false; // Двигается ли мышь
int lastMouseX, lastMouseY; // Предыдущие коорды мыши

void DrawFunc(function<double (double)> ChosenFunc)
{
    SDL_Window *window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;
    TTF_Font *font = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) // Инициализация SDL
    {
        cout << "Ошибка инициализации SDL: \n" << SDL_GetError();
        
        SDL_Quit();
        return;
    }

    if (TTF_Init() != 0) //Инициализация SDLttf
    {
        cout << "Ошибка инициализации SDL_ttf: \n" << TTF_GetError();
        
        TTF_Quit();
        return;
    }

    font = TTF_OpenFont("D:/Project/GroupProject_Calculator/x64/Debug/arial.ttf", MAX_FONT_SIZE);

    if (!font)
    {
        cout << "Ошибка инициализации SDL_ttf: \n" << TTF_GetError();
        
        TTF_Quit();
        SDL_Quit();
        return;
    }

    window = SDL_CreateWindow("Function Graph", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        cout << "Ошибка при создании окна: \n" << SDL_GetError();
        
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_DestroyWindow(window);
        
        cout << "Ошибка при создании рендера: \n" << SDL_GetError();
        
        TTF_CloseFont(font);
        
        TTF_Quit();
        SDL_Quit();
        return;
    }

    renderGraph(renderer, ChosenFunc, font, calculateFontSize(scaleX), scaleX, scaleY, offsetX, offsetY);

    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                {
                    quit = true;
                    break;
                }
            case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                    else if (event.key.keysym.sym == SDLK_RIGHT)
                        offsetX -= 10.0;
                    else if (event.key.keysym.sym == SDLK_LEFT)
                        offsetX += 10.0;
                    else if (event.key.keysym.sym == SDLK_UP) 
                        offsetY += 10.0;
                    else if (event.key.keysym.sym == SDLK_DOWN) 
                        offsetY -= 10.0;
                    
                    renderGraph(renderer, ChosenFunc, font, calculateFontSize(scaleX), scaleX, scaleY, offsetX, offsetY);
                    
                    break;
                }
            case SDL_MOUSEWHEEL:
                {
                    if (event.wheel.y > 0 && scaleX >= 40)
                    {
                        scaleX += 5;
                        scaleY += 5;
                    }
                    else if (event.wheel.y < 0 && scaleX >= 40)
                    {
                        scaleX -= 5;
                        scaleY -= 5;
                    }
                    else if (event.wheel.y > 0 || event.wheel.y < 0)
                    {
                        scaleX = 75;
                        scaleY = 75;
                    }
                    
                    renderGraph(renderer, ChosenFunc, font, calculateFontSize(scaleX), scaleX, scaleY, offsetX, offsetY);
                    
                    break;
                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        isDragging = true;
                        SDL_GetMouseState(&lastMouseX, &lastMouseY);
                    }
                    
                    break;
                }
            case SDL_MOUSEBUTTONUP:
                {
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        isDragging = false;
                    }
                    
                    break;
                }
            case SDL_MOUSEMOTION:
                {
                    if (isDragging)
                    {
                        int mouseX, mouseY;
                        
                        SDL_GetMouseState(&mouseX, &mouseY);
                        
                        offsetX += (mouseX - lastMouseX);
                        offsetY += (mouseY - lastMouseY);
                        lastMouseX = mouseX;
                        lastMouseY = mouseY;
                        
                        renderGraph(renderer, ChosenFunc, font, calculateFontSize(scaleX), scaleX, scaleY, offsetX, offsetY);
                    }
                    break;
                }
            default: break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);

    TTF_Quit();
    SDL_Quit();

    bool ans;

    cout << "Окно было закрыто!";
    
    cout << "\nПродолжить работу с текущей функцией (0/1)? ";

    do
    {
        cin >> ans;
        if (ans != 0 || ans != 1) cout << "Ошибка ввода";
    }
    while (ans != 0 && ans != 1);
    
    if (ans == 1)
    {
        system("cls");
        runSecondFuncMenu(ChosenFunc);
    }
    else
    {
        system("cls");
        runFunctionCalculator();
    }
}