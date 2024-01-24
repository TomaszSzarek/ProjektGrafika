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

    int bufferingMode; // 1 dla pojedynczego, 2 dla podw�jnego

    //rozdzielczo�� okna 3 zmienne
    int screenWidth;
    int screenHeight;
    bool fullscreenMode;

    //fps oraz w��czanie i wy��czanie klawiatury/myszki
    Uint32 maxFPS;
    bool enableMouse;
    bool enableKeyboard;

    std::map<SDL_Scancode, bool> keyStates;   // Kontener do przechowywania stanu klawiszy
    SDL_Point mousePosition;                 // Struktura przechowuj�ca pozycj� myszy
    bool mouseButtonStates[3];               // Tablica przechowuj�ca stan przycisk�w myszy (LPM, �PM, PPM)

    // Zmienna do przechowywania nazwy pliku do logowania b��d�w
    std::string logFileName;


public:
    Engine() :
        window(nullptr),
        renderer(nullptr),
        isRunning(false),
        screenWidth(800),    // domy�lna szeroko��
        screenHeight(600),   // domy�lna wysoko��
        fullscreenMode(false), // domy�lny tryb pe�noekranowy
        maxFPS(60),         // domy�lna warto�� to 60 FPS
        enableMouse(true),  // domy�lnie w��czona obs�uga myszy
        enableKeyboard(true), // domy�lnie w��czona obs�uga klawiatury
        mousePosition({ 0, 0 }),  // inicjalizacja pozycji myszy na (0,0)
        mouseButtonStates{ false, false, false },  // inicjalizacja stan�w przycisk�w myszy na false
        logFileName("error_log.txt"),  // domy�lna nazwa pliku log�w
        bufferingMode(2),
        primitiveRenderer(nullptr)
    {}

    // Inicjacja biblioteki graficznej
    bool init(const char* title, int width, int height, bool fullscreen) {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            showError("Nie uda�o si� zainicjowa� SDL: " + std::string(SDL_GetError()));
            return false;
        }

        int flags = SDL_WINDOW_SHOWN;
        if (fullscreen) {
            flags |= SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (!window) {
            showError("Nie uda�o si� utworzy� okna: " + std::string(SDL_GetError()));
            return false;
        }

        // Je�li u�ywamy trybu OpenGL (czyli podw�jne buforowanie), to tworzymy renderer z flag� SDL_RENDERER_ACCELERATED
        if (bufferingMode == 2) {
            flags |= SDL_WINDOW_OPENGL;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, 0);
        }

        if (!renderer) {
            showError("Nie uda�o si� utworzy� renderera: " + std::string(SDL_GetError()));
            return false;
        }

        // Utw�rz instancj� PrimitiveRenderer po utworzeniu renderer
        primitiveRenderer = new PrimitiveRenderer(renderer);

        isRunning = true;
        return true;
    }


    // Funkcja do wy�wietlania komunikat�w b��d�w
    void showError(const std::string& message) {
        std::cerr << "Error: " << message << std::endl;
        logError(message);
    }

    // Funkcja do zapisywania komunikat�w b��d�w do pliku
    void logError(const std::string& message) {
        std::ofstream logFile(logFileName, std::ios::app);  // Otwarcie pliku w trybie do��czania (append)
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

    // Pobiera szeroko�� ekranu
    int getScreenWidth() const {
        return screenWidth;
    }

    // Pobiera wysoko�� ekranu
    int getScreenHeight() const {
        return screenHeight;
    }

    // Pobiera stan trybu pe�noekranowego
    bool isFullscreen() const {
        return fullscreenMode;
    }

    // Ustawia maksymaln� liczb� klatek na sekund�
    void setMaxFPS(int fps) {
        maxFPS = fps;
    }

    int getMaxFPS() const {
        return maxFPS;
    }

    // W��cza/wy��cza obs�ug� myszy
    void setMouseEnabled(bool enabled) {
        enableMouse = enabled;
        SDL_ShowCursor(enabled ? SDL_ENABLE : SDL_DISABLE);
    }

    bool isMouseEnabled() const {
        return enableMouse;
    }

    // W��cza/wy��cza obs�ug� klawiatury
    void setKeyboardEnabled(bool enabled) {
        enableKeyboard = enabled;
        // Tu mo�na doda� dodatkowy kod, je�li chcesz zmienia� zachowanie gry podczas wy��czania klawiatury
    }

    bool isKeyboardEnabled() const {
        return enableKeyboard;
    }

    // G��wna p�tla gry
    void run() {
        Uint32 previousTicks = SDL_GetTicks();  // Czas pocz�tkowy dla deltaTime
        Uint32 currentTicks;
        float deltaTime;

        Uint32 frameStart, frameTime;
        while (isRunning) {
            frameStart = SDL_GetTicks();

            currentTicks = SDL_GetTicks();  // Pobranie aktualnego czasu
            deltaTime = (currentTicks - previousTicks) / 1000.0f;  // Obliczenie r�nicy czasu w sekundach

            if (bufferingMode == 2) {
                SDL_GL_SwapWindow(window); // Dla podw�jnego buforowania w trybie OpenGL
            }
            else {
                SDL_RenderPresent(renderer); // Dla pojedynczego buforowania
            }

            handleEvents();
            update(deltaTime);  // Aktualizacja logiki gry z wykorzystaniem deltaTime
            render();
            SDL_RenderPresent(renderer); // Wy�wietla zaktualizowan� zawarto�� ekranu.

            previousTicks = currentTicks;  // Aktualizacja czasu dla nast�pnej klatki w kontek�cie deltaTime

            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < 1000 / maxFPS) {
                SDL_Delay((1000 / maxFPS) - frameTime);
            }
        }
    }

    // Obs�uga klawiatury i myszy
    void handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:  // Obs�uga naci�ni�cia klawisza
                keyStates[event.key.keysym.scancode] = true;
                switch (event.key.keysym.sym) {
                case SDLK_1:  // Je�li naci�ni�to klawisz '1'
                    setGraphicsMode(800, 600, false);
                    break;
                case SDLK_2:  // Je�li naci�ni�to klawisz '2'
                    setGraphicsMode(1024, 768, false);
                    break;
                case SDLK_f:  // Je�li naci�ni�to klawisz 'F'
                    setGraphicsMode(screenWidth, screenHeight, !fullscreenMode);  // Prze��cz tryb pe�noekranowy
                    break;
                }
                break;

            case SDL_KEYUP:    // Obs�uga puszczenia klawisza
                keyStates[event.key.keysym.scancode] = false; // Uaktualnienie stanu klawisza w std::map
                break;

            case SDL_MOUSEMOTION:  // Obs�uga ruchu myszy
                mousePosition.x = event.motion.x;
                mousePosition.y = event.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:  // Obs�uga naci�ni�cia przycisku myszy
                mouseButtonStates[event.button.button - 1] = true;
                break;
            case SDL_MOUSEBUTTONUP:    // Obs�uga puszczenia przycisku myszy
                mouseButtonStates[event.button.button - 1] = false;
                break;
            }
        }
    }

    void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a); // Ustawia kolor czyszczenia
        SDL_RenderClear(renderer);                   // Czy�ci ekran do zadanego koloru
    }

    // Aktualizacja logiki gry
    void update(float deltaTime) {
        // Aktualizuj stan gry tutaj
    }

    // Rysowanie na ekranie
    void render() {
        clearScreen(255, 255, 255, 255); // Czy�ci ekran do bia�ego koloru.
        SDL_Color color = { 255, 0, 0, 255 }; // Kolor czerwony
        //primitiveRenderer->drawIncrementalLine(10, 10, 200, 200, color);  //To jest zadanie nr 2? kolejene 4 linie to wywo�anie pod zadanie 4 i 5
        Point2D p1(100, 100);
        Point2D p2(300, 300);
        LineSegment line(p1, p2);
        line.draw(*primitiveRenderer, { 255, 0, 0, 255 });
        //Rysuj obiekty gry tutaj

        SDL_RenderPresent(renderer);
    }

    // Zamkni�cie gry
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
        std::cerr << "B��d podczas inicjacji gry." << std::endl;
        return 1;
    }
    gameEngine.run();
    gameEngine.close();
    return 0;
}