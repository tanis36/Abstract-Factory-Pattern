#include <iostream>

// Abstract Products
class Button {
public:
    // Render the button
    virtual void render() = 0;
    // Destructor
    virtual ~Button() = default;
};

class Checkbox {
public:
    // Render the checkbox
    virtual void render() = 0;
    // Destructor
    virtual ~Checkbox() = default;
};

// Concrete Products
class AppleButton : public Button {
public:
    // Render Apple button
    void render() override {
        std::cout << "Rendering Apple Button" << std::endl;
    }
};

class AndroidButton : public Button {
public:
    // Render Android button
    void render() override {
        std::cout << "Rendering Android Button" << std::endl;
    }
};

class AppleCheckbox : public Checkbox {
public:
    // Render Apple checkbox
    void render() override {
        std::cout << "Rendering Apple Checkbox" << std::endl;
    }
};

class AndroidCheckbox : public Checkbox {
public:
    // Render Android checkbox
    void render() override {
        std::cout << "Rendering Android Checkbox" << std::endl;
    }
};

int main() {

}