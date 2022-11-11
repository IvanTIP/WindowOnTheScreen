#include <iostream>
class Window {
private:
    int coordX;
    int coordY;
    int width;
    int height;
public:
    void setX (int in_x) {
        coordX = in_x;
    }
    void setY (int in_y) {
        coordY = in_y;
    }
    void setWidth (int in_width) {
        width = in_width;
    }
    void setHeight (int in_height) {
        height = in_height;
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
    Window *window;
    char monitorField[80][50];
public:
    Monitor () {
        for (int i = 0;i < 50;i++) {
            for (int j = 0;j < 80;j++) {
                monitorField[j][i] = '0';
            }
        }
        window = new Window;
        window->setX(39);
        window->setY(24);
        window->setWidth(10);
        window->setHeight(10);
    }

    void show () {
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
                    j--;
                } else if (j == X && i > Y && i <= Y + height) {
                    for (int k = 0;k < width && j < 80;k++) {
                        std::cout << '1';
                        j++;
                    }
                    j--;
                } else {
                    std::cout << monitorField[j][i];
                }
            }
            std::cout << std::endl;
        }
    }

    void move () {
        int x, y;
        std::cout << "Enter coordinate X = ";
        std::cin >> x;
        while (x < 0 || x > 79) {
            std::cout << "Wrong coordinate! Try again" << std::endl;
            std::cout << "Enter coordinate X = ";
            std::cin >> x;
        }
        window->setX(x);

        std::cout << "Enter coordinate Y = ";
        std::cin >> y;
        while (y < 0 || y > 49) {
            std::cout << "Wrong coordinate! Try again" << std::endl;
            std::cout << "Enter coordinate Y = ";
            std::cin >> y;
        }
        window->setY(y);

        std::cout << "New coordinates of window:" << std::endl;
        std::cout << "X = " << window->getX() << std::endl;
        std::cout << "Y = " << window->getY() << std::endl;
    }

    void resize () {
        int width, height;
        std::cout << "Enter new size of width of window: ";
        std::cin >> width;
        while (width < 0 || width >79) {
            std::cout << "Input error! Try again" << std::endl;
            std::cout << "Enter new size of width of window: ";
            std::cin >> width;
        }
        window->setWidth(width);

        std::cout << "Enter new size of height of window: ";
        std::cin >> height;
        while (height < 0 || height > 49) {
            std::cout << "Input error! Try again" << std::endl;
            std::cout << "Enter new size of height of window: ";
            std::cin >> height;
        }
        window->setHeight(height);

        std::cout << "New window sizes:" << std::endl;
        std::cout << "Width: " << window->getWidth() << std::endl;
        std::cout << "Height: " << window->getHeight() << std::endl;
    }

    void clearWindow () {
        delete window;
    }
};

int main() {
    Monitor* monitor = new Monitor;
    while (true) {
        std::string command;
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "move") {
            monitor->move();
        } else if (command == "resize") {
            monitor->resize();
        } else if (command == "display") {
            monitor->show();
        } else if (command == "close") {
            monitor->clearWindow();
            delete monitor;
            return 0;
        }
    }
}