#include <SDL.h>
#include <map>
#include <iostream>
#include <fstream>
#include "primitive.h"


class Engine {
private:
    PrimitiveRenderer* primitiveRenderer;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    int bufferingMode; // 1 dla pojedynczego, 2 dla podwójnego

    //rozdzielczoœæ okna 3 zmienne
    int screenWidth;
    int screenHeight;
    bool fullscreenMode;

    //fps oraz w³¹czanie i wy³¹czanie klawiatury/myszki
    Uint32 maxFPS;
    bool enableMouse;
    bool enableKeyboard;

    std::map<SDL_Scancode, bool> keyStates;   // Kontener do przechowywania stanu klawiszy
    SDL_Point mousePosition;                 // Struktura przechowuj¹ca pozycjê myszy
    bool mouseButtonStates[3];               // Tablica przechowuj¹ca stan przycisków myszy (LPM, ŒPM, PPM)

    // Zmienna do przechowywania nazwy pliku do logowania b³êdów
    std::string logFileName;


public:
    Engine() :
        window(nullptr),
        renderer(nullptr),
        isRunning(false),
        screenWidth(800),    // domyœlna szerokoœæ
        screenHeight(600),   // domyœlna wysokoœæ
        fullscreenMode(false), // domyœlny tryb pe³noekranowy
        maxFPS(60),         // domyœlna wartoœæ to 60 FPS
        enableMouse(true),  // domyœlnie w³¹czona obs³uga myszy
        enableKeyboard(true), // domyœlnie w³¹czona obs³uga klawiatury
        mousePosition({ 0, 0 }),  // inicjalizacja pozycji myszy na (0,0)
        mouseButtonStates{ false, false, false },  // inicjalizacja stanów przycisków myszy na false
        logFileName("error_log.txt"),  // domyœlna nazwa pliku logów
        bufferingMode(2),
        primitiveRenderer(nullptr)
    {}

    // Inicjacja biblioteki graficznej
    bool init(const char* title, int width, int height, bool fullscreen) {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            showError("Nie uda³o siê zainicjowaæ SDL: " + std::string(SDL_GetError()));
            return false;
        }

        int flags = SDL_WINDOW_SHOWN;
        if (fullscreen) {
            flags |= SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (!window) {
            showError("Nie uda³o siê utworzyæ okna: " + std::string(SDL_GetError()));
            return false;
        }

        // Jeœli u¿ywamy trybu OpenGL (czyli podwójne buforowanie), to tworzymy renderer z flag¹ SDL_RENDERER_ACCELERATED
        if (bufferingMode == 2) {
            flags |= SDL_WINDOW_OPENGL;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, 0);
        }

        if (!renderer) {
            showError("Nie uda³o siê utworzyæ renderera: " + std::string(SDL_GetError()));
            return false;
        }

        // Utwórz instancjê PrimitiveRenderer po utworzeniu renderer
        primitiveRenderer = new PrimitiveRenderer(renderer);

        isRunning = true;
        return true;
    }


    // Funkcja do wyœwietlania komunikatów b³êdów
    void showError(const std::string& message) {
        std::cerr << "Error: " << message << std::endl;
        logError(message);
    }

    // Funkcja do zapisywania komunikatów b³êdów do pliku
    void logError(const std::string& message) {
        std::ofstream logFile(logFileName, std::ios::app);  // Otwarcie pliku w trybie do³¹czania (append)
        if (logFile.is_open()) {
            logFile << "[ERROR] " << message << std::endl;
            logFile.close();
        }
    }

    // Ustawia parametry trybu graficznego
    void setGraphicsMode(int width, int height, bool fullscreen) {
        screenWidth = width;
        screenHeight = height;
        fullscreenMode = fullscreen;

        if (window) {
            SDL_SetWindowSize(window, screenWidth, screenHeight);
            if (fullscreenMode) {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            }
            else {
                SDL_SetWindowFullscreen(window, 0);
            }
        }
    }

    // Pobiera szerokoœæ ekranu
    int getScreenWidth() const {
        return screenWidth;
    }

    // Pobiera wysokoœæ ekranu
    int getScreenHeight() const {
        return screenHeight;
    }

    // Pobiera stan trybu pe³noekranowego
    bool isFullscreen() const {
        return fullscreenMode;
    }

    // Ustawia maksymaln¹ liczbê klatek na sekundê
    void setMaxFPS(int fps) {
        maxFPS = fps;
    }

    int getMaxFPS() const {
        return maxFPS;
    }

    // W³¹cza/wy³¹cza obs³ugê myszy
    void setMouseEnabled(bool enabled) {
        enableMouse = enabled;
        SDL_ShowCursor(enabled ? SDL_ENABLE : SDL_DISABLE);
    }

    bool isMouseEnabled() const {
        return enableMouse;
    }

    // W³¹cza/wy³¹cza obs³ugê klawiatury
    void setKeyboardEnabled(bool enabled) {
        enableKeyboard = enabled;
        // Tu mo¿na dodaæ dodatkowy kod, jeœli chcesz zmieniaæ zachowanie gry podczas wy³¹czania klawiatury
    }

    bool isKeyboardEnabled() const {
        return enableKeyboard;
    }

    // G³ówna pêtla gry
    void run() {
        Uint32 previousTicks = SDL_GetTicks();  // Czas pocz¹tkowy dla deltaTime
        Uint32 currentTicks;
        float deltaTime;

        Uint32 frameStart, frameTime;
        while (isRunning) {
            frameStart = SDL_GetTicks();

            currentTicks = SDL_GetTicks();  // Pobranie aktualnego czasu
            deltaTime = (currentTicks - previousTicks) / 1000.0f;  // Obliczenie ró¿nicy czasu w sekundach

            if (bufferingMode == 2) {
                SDL_GL_SwapWindow(window); // Dla podwójnego buforowania w trybie OpenGL
            }
            else {
                SDL_RenderPresent(renderer); // Dla pojedynczego buforowania
            }

            handleEvents();
            update(deltaTime);  // Aktualizacja logiki gry z wykorzystaniem deltaTime
            render();
            SDL_RenderPresent(renderer); // Wyœwietla zaktualizowan¹ zawartoœæ ekranu.

            previousTicks = currentTicks;  // Aktualizacja czasu dla nastêpnej klatki w kontekœcie deltaTime

            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < 1000 / maxFPS) {
                SDL_Delay((1000 / maxFPS) - frameTime);
            }
        }
    }

    // Obs³uga klawiatury i myszy
    void handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:  // Obs³uga naciœniêcia klawisza
                keyStates[event.key.keysym.scancode] = true;
                switch (event.key.keysym.sym) {
                case SDLK_1:  // Jeœli naciœniêto klawisz '1'
                    setGraphicsMode(800, 600, false);
                    break;
                case SDLK_2:  // Jeœli naciœniêto klawisz '2'
                    setGraphicsMode(1024, 768, false);
                    break;
                case SDLK_f:  // Jeœli naciœniêto klawisz 'F'
                    setGraphicsMode(screenWidth, screenHeight, !fullscreenMode);  // Prze³¹cz tryb pe³noekranowy
                    break;
                }
                break;

            case SDL_KEYUP:    // Obs³uga puszczenia klawisza
                keyStates[event.key.keysym.scancode] = false; // Uaktualnienie stanu klawisza w std::map
                break;

            case SDL_MOUSEMOTION:  // Obs³uga ruchu myszy
                mousePosition.x = event.motion.x;
                mousePosition.y = event.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:  // Obs³uga naciœniêcia przycisku myszy
                mouseButtonStates[event.button.button - 1] = true;
                break;
            case SDL_MOUSEBUTTONUP:    // Obs³uga puszczenia przycisku myszy
                mouseButtonStates[event.button.button - 1] = false;
                break;
            }
        }
    }

    void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a); // Ustawia kolor czyszczenia
        SDL_RenderClear(renderer);                   // Czyœci ekran do zadanego koloru
    }

    // Aktualizacja logiki gry
    void update(float deltaTime) {
        // Aktualizuj stan gry tutaj
    }

    // Rysowanie na ekranie
    void render() {
        clearScreen(255, 255, 255, 255); // Czyœci ekran do bia³ego koloru.
        SDL_Color color = { 255, 0, 0, 255 }; // Kolor czerwony
        //primitiveRenderer->drawIncrementalLine(10, 10, 200, 200, color);  //To jest zadanie nr 2? kolejene 4 linie to wywo³anie pod zadanie 4 i 5
        Point2D p1(100, 100);
        Point2D p2(300, 300);
        LineSegment line(p1, p2);
        line.draw(*primitiveRenderer, { 255, 0, 0, 255 });
        //Rysuj obiekty gry tutaj

        SDL_RenderPresent(renderer);
    }

    // Zamkniêcie gry
    void close() {
        delete primitiveRenderer;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};


int main(int argc, char* argv[]) {
    Engine gameEngine;
    if (!gameEngine.init("Tytul okna", 800, 600, false)) {
        std::cerr << "B³¹d podczas inicjacji gry." << std::endl;
        return 1;
    }
    gameEngine.run();
    gameEngine.close();
    return 0;
}