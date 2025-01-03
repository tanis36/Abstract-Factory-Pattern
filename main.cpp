#include <iostream>
#include <memory>

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

// Abstract Factory
class GUIFactory {
public:
    // Create the button
    virtual std::unique_ptr<Button> createButton() = 0;
    // Create the checkbox
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
    // Destructor
    virtual ~GUIFactory() = default;
};

// Concrete Factories
class AppleFactory : public GUIFactory {
public:
    // Create the Apple button
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<AppleButton>();
    }
    // Create the Apple checkbox
    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<AppleCheckbox>();
    }
};

class AndroidFactory : public GUIFactory {
public:
    // Create the Android button
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<AndroidButton>();
    }
    // Create the Android checkbox
    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<AndroidCheckbox>();
    }
};

// Render the user interface
void renderUI(GUIFactory& factory) {
    // Create the button
    auto button = factory.createButton();
    // Create the checkbox
    auto checkbox = factory.createCheckbox();
    // Render the button
    button->render();
    // Render the checkbox
    checkbox->render();
}

// Main
int main() {
    // Initialize an AppleFactory
    AppleFactory appleFactory;
    // Initialize an AndroidFactory
    AndroidFactory androidFactory;

    // Render the Apple UI
    std::cout << "Apple UI:" << std::endl;
    renderUI(appleFactory);

    // Render the Android UI
    std::cout << "Android UI:" << std::endl;
    renderUI(androidFactory);
}