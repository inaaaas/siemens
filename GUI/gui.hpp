#ifndef GUI_HPP
#define GUI_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class UIComponent {
public:
    virtual void draw() const = 0;
    virtual void onClick() const = 0;

    virtual ~UIComponent() = default;
};

class Button : public UIComponent {
    std::string label;
public:
    Button(const std::string& text);
    void draw() const override;
    void onClick() const override;
};

class CheckBox : public UIComponent {
    bool checked;
public:
    CheckBox();
    void draw()const override;
    void onClick() const override;
};

class TextsField : public UIComponent {
    std::string text;
public:
    TextsField(const std::string& txt);
    void draw() const override;
    void onClick() const override;
};

class GUI {
    std::vector<std::unique_ptr<UIComponent>> components;
public:
    void addComponent(std::unique_ptr<UIComponent> component);
    void render() const;
    void click() const;
};

#endif