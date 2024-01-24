#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include "SDL_image.h"
#include "Protagonist.h"
#include "ListaObiektow.h"
#include "iostream"
#include "ObiektMapy.h"
#include "Background.h"
#include "ButtonList.h"
#include "ObjectCombat.h"
#include "Bot.h"
#include "HealthBar.h"
class Engine {
public:
    Engine();
    ~Engine();
    void InitSDL();
};
#endif 