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

int main() {

}