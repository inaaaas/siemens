#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>

struct Position {
    float m_x;
    float m_y;
    Position(float x = 0.0f, float y = 0.0f);
};
//5-i kanony 

class Sprite {
    int* pixelData;
    int m_size;
public:
    Sprite(int size = 5);
    ~Sprite();

    Sprite (const Sprite& other);

    Sprite& operator=(const Sprite& other);

    Sprite (Sprite&& other) noexcept;

    Sprite& operator=(Sprite&& other) noexcept;

    void draw() const;
};

class GameObject {
protected:
    int m_health;
    Position position;
    Sprite sprite;
public:
    GameObject(int health = 200, float x = 0.0f, float y = 0.0f, int spriteSize = 5);
    virtual ~GameObject() = default;
    GameObject(const GameObject& other);

    GameObject& operator=(const GameObject& other);

    GameObject(GameObject&& other) noexcept;

    GameObject& operator=(GameObject&& other) noexcept;

    virtual void update();
    virtual void render() const;
};

class Player : public GameObject {
public:
    Player(int health = 100, float x = 1.0f, float y = 1.0f);
    void update() override;
    void render() const override;
};

class Enemy : public GameObject {
public:
    Enemy(int health = 50, float x = 2.0f, float y = 2.0f);
    void update() override;
    void render() const override;
};

class NPC : public GameObject {
public:
    NPC(int health = 80, float x = 3.0f, float y = 3.0f);
    void update() override;
    void render() const override;
};

#endif