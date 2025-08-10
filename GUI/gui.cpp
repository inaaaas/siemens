#include "gui.hpp"
Button::Button(const std::string& text) : label(text) {}
 
void Button::draw() const {
    std::cout << "Drawing button" << label << std::endl;
}

void Button::onClick() const {
    std::cout<< "Button " << label << "clicked" << std::endl;
}

CheckBox::CheckBox() : checked(false) {}

void CheckBox::draw() const {
    std::cout << "Drawing checkbox " << (checked ? "checked" : "unchecked" )<< std::endl;
}

void CheckBox::onClick() const {
    std::cout << "checkbox switched" << std::endl;
}


TextsField::TextsField(const std::string& txt) : text(txt) {}

void TextsField::draw() const {
    std::cout << "Drawing Textfield with text: " << text << std::endl;
}

void TextsField::onClick() const {
    std::cout << "textfield selected" << std::endl;
}

void GUI::addComponent(std::unique_ptr<UIComponent> component) {
    components.push_back(std::move(component));
}
    
void GUI::render() const {
    for (const auto& component : components) {
        component->draw();
    }
}
    
void GUI::click() const {
    for (const auto& component : components) {
        component->onClick();
    }
}