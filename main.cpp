#include <iostream>
class Window {
private:
    int coordX = 39;
    int coordY = 24;
    int width = 10;
    int height = 10;
public:
    static void move (Window* window) {
        std::cout << "Enter coordinate X = ";
        std::cin >> window->coordX;
        while (window->coordX < 0 || window->coordX > 79) {
            std::cout << "Wrong coordinate! Try again" << std::endl;
            std::cout << "Enter coordinate X = ";
            std::cin >> window->coordX;
        }
        std::cout << "Enter coordinate Y = ";
        std::cin >> window->coordY;
        while (window->coordY < 0 || window->coordY > 49) {
            std::cout << "Wrong coordinate! Try again" << std::endl;
            std::cout << "Enter coordinate Y = ";
            std::cin >> window->coordY;
        }
        std::cout << "New coordinates of window:" << std::endl;
        std::cout << "X = " << window->coordX << std::endl;
        std::cout << "Y = " << window->coordY << std::endl;
    }
    static void resize (Window* window) {
        std::cout << "Enter new size of width of window: ";
        std::cin >> window->width;
        while (window->width < 0 || window->width >79) {
            std::cout << "Input error! Try again" << std::endl;
            std::cout << "Enter new size of width of window: ";
            std::cin >> window->width;
        }
        std::cout << "Enter new size of height of window: ";
        std::cin >> window->height;
        while (window->height < 0 || window->height > 49) {
            std::cout << "Input error! Try again" << std::endl;
            std::cout << "Enter new size of height of window: ";
            std::cin >> window->height;
        }
        std::cout << "New window sizes:" << std::endl;
        std::cout << "Width: " << window->width << std::endl;
        std::cout << "Height: " << window->height << std::endl;
    }
    int getX () {
        return coordX;
    }
    int getY () {
        return coordY;
    }
    int getWidth () {
        return width;
    }
    int getHeight () {
        return height;
    }
};
class Monitor {
  private:
    char monitorField[80][50];
  public:
    static void fieldInit (Monitor* monitor) {
        for (int i = 0;i < 50;i++) {
            for (int j = 0;j < 80;j++) {
                monitor->monitorField[j][i] = '0';
            }
        }
    }
    static void show (Monitor* monitor, class Window* window) {
        int X = window->getX();
        int Y = window->getY();
        int width = window->getWidth();
        int height = window->getHeight();
        for (int i = 0;i < 50;i++) {
            for (int j = 0;j < 80;j++) {
                if (j == X && i == Y) {
                    for (int k = 0;k < width && j < 80;k++) {
                        std::cout << '1';
                        j++;
                    }
                } else if (j == X && i > Y && i <= Y + height) {
                    for (int k = 0;k < width && j < 80;k++) {
                        std::cout << '1';
                        j++;
                    }
                } else {
                    std::cout << monitor->monitorField[j][i];
                }
            }
            std::cout << std::endl;
        }
    }
    friend class Window;
};

int main() {
    Monitor* monitor = new Monitor;
    Window* window = new Window;
    while (true) {
        std::string command;
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "move") {
            Window::move(window);
        } else if (command == "resize") {
            Window::resize(window);
        } else if (command == "display") {
            Monitor::fieldInit(monitor);
            Monitor::show(monitor, window);
        } else if (command == "close") {
            delete window;
            delete monitor;
            return 0;
        }
    }
}
