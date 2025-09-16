#include "screens.hpp"
#include <stack>
#include <memory>

class ScreenManager
{
private:
    std::stack<std::unique_ptr<BaseScreen>> _screens;

public:
    ScreenManager() = default;

    /*
     * @brief Pushes a screen to the top of the stack, used when you can go back to the previous screen
     */
    void pushScreen(std::unique_ptr<BaseScreen> newScreen);
    /*
     * @brief Pops the screen at the top. Used to go back to the previous screen
     */
    void popScreen();
    /*
     * @brief Clears the stack and this screens becomes the only one
     */
    void changeScreen(std::unique_ptr<BaseScreen> newScreen);
    /*
     * @brief Clears the entire stack and leaves it empty
     */
    void clearAllScreens();
    /*
     * @brief Gets a pointer to the current top screen
     */
    BaseScreen *getScreen() const;
    /*
     * @brief Checks if the stack is empty
     */
    bool isEmpty() const;
    /*
     * @brief The current screen handles the input needed
     */
    void handleInput();
    /*
     * @brief Updates the current screen logic, sometimes it won't be needed
     */
    void update();
    /*
     * @brief Draws everything in the screen
     */
    void render();
};
