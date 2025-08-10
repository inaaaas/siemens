#include "gui.hpp"
int main() {
    GUI gui;
    gui.addComponent(std::make_unique<Button>("Login"));
    gui.addComponent(std::make_unique<CheckBox>());
    gui.addComponent(std::make_unique<TextsField>("Enter text"));

    std::cout << "Rendering GUI:\n";
    gui.render();
    std::cout << "\nClicks:\n";
    gui.click();

    return 0;
}