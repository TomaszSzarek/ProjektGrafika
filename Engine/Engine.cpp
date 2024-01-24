#include "engine.h"

Engine::Engine() {}
Engine::~Engine() {}
enum State
{
    playerTurn,
    enemyTurn
};
void Engine::InitSDL()
{
    const int targetFPS = 60;
    const int delayPerFrame = 1000 / targetFPS;  // Czas oczekiwania na jedn¹ klatkê w milisekundach
    int frameCounter = 0;
    State state;
    Uint32 frameStart, frameTime;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    Protagonist* protagonist = nullptr;
    Background* background = nullptr;
    ListaObiektow* listaObiektow = nullptr;
    ButtonList* buttonList = nullptr;
    Bot* bot = nullptr;
    HealthBar* healthBarPlayer = nullptr;
    HealthBar* healthBarEnemy = nullptr;
    ObjectCombat* player = nullptr;
    ObjectCombat* enemy = nullptr;
    ObjectCombat* objectCombat1 = nullptr;
    ObjectCombat* objectCombat2 = nullptr;
    ObjectCombat* objectCombat3 = nullptr;
    ObjectCombat* objectCombat4 = nullptr;
    ObjectCombat* objectCombat5 = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "B³¹d inicjalizacji SDL: " << SDL_GetError() << std::endl;
        return;
    }
    else
    {
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            std::cerr << "B³¹d inicjalizacji SDL_Image: " << IMG_GetError() << std::endl;
            SDL_Quit(); // Zamknij SDL przed zakoñczeniem funkcji
            return;
        }
        else
        {
            window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1290, 720, SDL_WINDOW_SHOWN);
            if (window == nullptr)
            {
                std::cerr << "B³¹d tworzenia okna SDL: " << SDL_GetError() << std::endl;
                IMG_Quit(); // Zamknij SDL_Image przed zakoñczeniem funkcji
                SDL_Quit(); // Zamknij SDL przed zakoñczeniem funkcji
                return;
            }
            else
            {
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer == nullptr)
                {
                    std::cerr << "B³¹d tworzenia renderera SDL: " << SDL_GetError() << std::endl;
                    SDL_DestroyWindow(window); // Zniszcz okno przed zakoñczeniem funkcji
                    IMG_Quit(); // Zamknij SDL_Image przed zakoñczeniem funkcji
                    SDL_Quit(); // Zamknij SDL przed zakoñczeniem funkcji
                    return;
                }
                else
                {
                    std::srand(static_cast<unsigned int>(std::time(nullptr)));
                    listaObiektow = new ListaObiektow();
                    listaObiektow->creatList(renderer);
                    listaObiektow->randObjectMap();
                    buttonList = new ButtonList();
                    buttonList->createList(renderer);
                    protagonist = new Protagonist(renderer, "../image/basic.png", 600, 600);
                    background = new Background(renderer, "../image/background.jpg", 0, 0);
                    bot = new Bot(renderer, "../image/bot.png", 0, 486);
                    healthBarPlayer = new HealthBar(renderer, 285, 60, 133, 27);
                    healthBarEnemy = new HealthBar(renderer, 1120, 60, 133, 27);
                    player = new ObjectCombat(1000, 1000, 20, 20, 5, 5);
                    player->skills.createList();
                    objectCombat1 = new ObjectCombat(100, 100, 20, 20, 5, 5);
                    objectCombat1->skills.createList();
                    objectCombat2 = new ObjectCombat(100, 100, 20, 20, 5, 5);
                    objectCombat2->skills.createList();
                    objectCombat3 = new ObjectCombat(100, 100, 20, 20, 5, 5);
                    objectCombat3->skills.createList();
                    objectCombat4 = new ObjectCombat(100, 100, 20, 20, 5, 5);
                    objectCombat4->skills.createList();
                    objectCombat5 = new ObjectCombat(100, 100, 20, 20, 5, 5);
                    objectCombat5->skills.createList();
                    SDL_Event event;
                    SDL_Event batleEvent;
                    bool batleQuit;
                    bool quit = false;
                    auto it = buttonList->buttonList.begin();
                    int skillId = 0;
                    int randomSkill;
                    frameStart = SDL_GetTicks();  // Pobierz czas pocz¹tkowy klatki
                    while (!quit)
                    {
                        while (SDL_PollEvent(&event) != 0)
                        {
                            if (event.type == SDL_QUIT)
                            {
                                quit = true;
                            }
                            else
                            {
                                if (event.type == SDL_KEYDOWN)
                                {
                                    frameCounter = 0;
                                    protagonist->setCenter();
                                    protagonist->kolizja(listaObiektow->objectList);
                                    if (event.key.keysym.sym == SDLK_SPACE && (protagonist->getKolizjaW() > 0
                                        || protagonist->getKolizjaS() > 0
                                        || protagonist->getKolizjaA() > 0
                                        || protagonist->getKolizjaD() > 0))
                                    {
                                        batleQuit = true;
                                        switch (protagonist->getIdObiektKolidujacego())
                                        {
                                        case 0:
                                            background->setBackground(renderer, "../image/Orbana.png");
                                            enemy = objectCombat1;
                                            break;
                                        case 1:
                                            background->setBackground(renderer, "../image/Joli.png");
                                            enemy = objectCombat2;
                                            break;
                                        case 2:
                                            background->setBackground(renderer, "../image/Turtlanta.png");
                                            enemy = objectCombat3;
                                            break;
                                        case 3:
                                            background->setBackground(renderer, "../image/Hupig.png");
                                            enemy = objectCombat4;
                                            break;
                                        case 4:
                                            background->setBackground(renderer, "../image/Huczi.png");
                                            enemy = objectCombat5;
                                            break;
                                        }
                                        background->render(renderer);
                                        bot->render(renderer);
                                        buttonList->printList(renderer);
                                        state = playerTurn;
                                        //Petla Walki
                                        while (batleQuit)
                                        {
                                            SDL_Event battleEvent;
                                            while (SDL_PollEvent(&battleEvent) != 0)
                                            {
                                                if (state == playerTurn)
                                                {
                                                    if (battleEvent.type == SDL_QUIT)
                                                    {
                                                        SDL_RenderPresent(renderer);
                                                        background->setBackground(renderer, "../image/background.jpg");
                                                        batleQuit = false;
                                                    }
                                                    else
                                                    {
                                                        healthBarPlayer->Render(player->getCurrentHp(), player->getMaxHp());
                                                        healthBarEnemy->Render(enemy->getCurrentHp(), enemy->getMaxHp());
                                                        if (battleEvent.type == SDL_KEYDOWN)
                                                        {
                                                            if (battleEvent.key.keysym.sym == SDLK_d)
                                                            {
                                                                if ((it + 1) != buttonList->buttonList.end())
                                                                {
                                                                    it->setActive(false);
                                                                    it++;
                                                                    it->setActive(true);
                                                                    buttonList->checkActive(renderer);
                                                                    buttonList->printList(renderer);
                                                                    skillId++;
                                                                }
                                                            }
                                                            if (battleEvent.key.keysym.sym == SDLK_a)
                                                            {
                                                                if ((it) != buttonList->buttonList.begin())
                                                                {
                                                                    it->setActive(false);
                                                                    it--;
                                                                    it->setActive(true);
                                                                    buttonList->checkActive(renderer);
                                                                    buttonList->printList(renderer);
                                                                    skillId--;
                                                                }
                                                            }
                                                            if (battleEvent.key.keysym.sym == SDLK_SPACE)
                                                            {
                                                                if (skillId <= 2)
                                                                {
                                                                    enemy->getDamage(player->getPhysicalDmg(), player->getMagicDmg(), player->skills.skillList[skillId]);
                                                                    state = enemyTurn;
                                                                }
                                                                else if (skillId == 3 || skillId == 4)
                                                                {
                                                                    if (player->skills.skillList[skillId].getName() == "obronaFizyczna")
                                                                    {
                                                                        player->getDefenseUp(0, player->skills.skillList[skillId]);
                                                                        state = enemyTurn;
                                                                    }
                                                                    else
                                                                    {
                                                                        player->getDefenseUp(1, player->skills.skillList[skillId]);
                                                                        state = enemyTurn;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    player->getHeal(player->skills.skillList[skillId]);
                                                                    state = enemyTurn;
                                                                }
                                                                if (enemy->getCurrentHp() <= 0)
                                                                {
                                                                    enemy->setCurrentHp(enemy->getMaxHp());
                                                                    background->setBackground(renderer, "../image/background.jpg");
                                                                    protagonist->setKillEnemy(protagonist->getKillEnemy() + 1);
                                                                    listaObiektow->objectList[protagonist->getIdObiektKolidujacego()].setX(-1000);
                                                                    listaObiektow->objectList[protagonist->getIdObiektKolidujacego()].setCenter();
                                                                    batleQuit = false;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    randomSkill = 1; //std::rand() % 6;
                                                    switch (randomSkill)
                                                    {
                                                    case 1:
                                                        player->getDamage(enemy->getPhysicalDmg(), enemy->getMagicDmg(), enemy->skills.skillList[0]);
                                                        break;
                                                    case 2:
                                                        player->getDamage(enemy->getPhysicalDmg(), enemy->getMagicDmg(), enemy->skills.skillList[1]);
                                                        break;
                                                    case 3:
                                                        player->getDamage(enemy->getPhysicalDmg(), enemy->getMagicDmg(), enemy->skills.skillList[3]);
                                                        break;
                                                    case 4:
                                                        player->getDefenseUp(0, player->skills.skillList[4]);
                                                        break;
                                                    case 5:
                                                        player->getDefenseUp(0, player->skills.skillList[5]);
                                                        break;
                                                    case 6:
                                                        player->getHeal(player->skills.skillList[6]);
                                                        break;
                                                    }
                                                    state = playerTurn;
                                                }
                                            }
                                            SDL_RenderPresent(renderer);
                                        }
                                    }
                                    player->setCurrentMagicDefense(player->getMagicDefense());
                                    player->setCurrentPhysicalDefense(player->getPhysicalDefense());

                                    if (event.key.keysym.sym == SDLK_w)
                                    {
                                        protagonist->setKierunek(1);
                                        if (protagonist->getKolizjaW() == 0)
                                        {
                                            if (protagonist->getY() > 0)
                                            {
                                                protagonist->setY(protagonist->getY() - protagonist->getSpeed());
                                            }

                                        }
                                    }
                                    else if (event.key.keysym.sym == SDLK_s)
                                    {
                                        protagonist->setKierunek(2);
                                        if (protagonist->getKolizjaS() == 0)
                                        {
                                            if (protagonist->getY() + protagonist->getHeight() < background->getHeight())
                                            {
                                                protagonist->setY(protagonist->getY() + protagonist->getSpeed());
                                            }
                                        }
                                    }
                                    else if (event.key.keysym.sym == SDLK_a)
                                    {
                                        protagonist->setKierunek(3);
                                        if (protagonist->getKolizjaA() == 0)
                                        {
                                            if (protagonist->getX() > 0)
                                            {
                                                protagonist->setX(protagonist->getX() - protagonist->getSpeed());
                                            }
                                        }
                                    }
                                    else if (event.key.keysym.sym == SDLK_d)
                                    {
                                        protagonist->setKierunek(4);
                                        if (protagonist->getKolizjaD() == 0)
                                        {
                                            if (protagonist->getX() + protagonist->getWidth() < background->getWidth())
                                            {
                                                protagonist->setX(protagonist->getX() + protagonist->getSpeed());
                                            }
                                        }
                                    }
                                    if (event.key.keysym.sym == SDLK_z)
                                    {
                                        std::cout << "AmountRandObject " << listaObiektow->getAmountRandObjectMap() << std::endl;
                                        std::cout << "KILLENEMY " << protagonist->getKillEnemy() << std::endl;
                                        std::cout << "kolizjaNextLevel " << protagonist->getKolizjaNextLevel() << std::endl;
                                    }
                                    if (listaObiektow->getAmountRandObjectMap() == protagonist->getKillEnemy() && protagonist->getKolizjaNextLevel() == 1 && event.key.keysym.sym == SDLK_SPACE)
                                    {
                                        protagonist->setX(1280);
                                        protagonist->setY(0);
                                        listaObiektow->randObjectMap();
                                        protagonist->setKillEnemy(0);
                                    }
                                }
                                frameCounter++;
                                if (frameCounter >= 3)
                                {
                                    protagonist->setKierunek(0);
                                }
                            }
                        }

                        SDL_RenderClear(renderer);

                        background->render(renderer);
                        listaObiektow->printList(renderer);
                        switch (protagonist->getKierunek())
                        {
                        case 1:
                            protagonist->setObraz(renderer, "../image/front.png");
                            protagonist->render(renderer);
                            break;
                        case 2:
                            protagonist->setObraz(renderer, "../image/back.png");
                            protagonist->render(renderer);
                            break;
                        case 3:
                            protagonist->setObraz(renderer, "../image/left.png");
                            protagonist->render(renderer);
                            break;
                        case 4:
                            protagonist->setObraz(renderer, "../image/right.png");
                            protagonist->render(renderer);
                            break;
                        default:
                            protagonist->setObraz(renderer, "../image/basic.png");
                            protagonist->render(renderer);
                            break;
                        }
                        SDL_RenderPresent(renderer);
                        frameTime = SDL_GetTicks() - frameStart;  // Czas trwania klatki

                        // Oczekiwanie, jeœli czas trwania klatki jest krótszy ni¿ docelowy czas oczekiwania
                        if (frameTime < delayPerFrame)
                        {
                            SDL_Delay(delayPerFrame - frameTime);
                        }
                    }
                    // Zwolnienie pamiêci obiektu protagonisty
                    delete protagonist;
                    protagonist = nullptr;
                }
                // Zniszczenie okna i renderera
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
            }
            // Zamkniêcie SDL_Image
            IMG_Quit();
        }
        // Zamkniêcie SDL
        SDL_Quit();
    }
}