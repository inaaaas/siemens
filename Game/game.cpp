#include "game.hpp"

Position::Position(float x, float y) : m_x(x), m_y(y) {}

Sprite::Sprite(int size) : m_size(size), pixelData(new int[size]) {
    for (int i = 0; i < size; ++i) {
        pixelData[i] = i;
    }
    std::cout << "Sprite created" << std::endl;
}

Sprite::~Sprite() {
    delete[] pixelData;
    std::cout << "Sprite destroyed" << std::endl;
}


Sprite::Sprite (const Sprite& other) : m_size(other.m_size), pixelData(new int[other.m_size]) {
    for (int i = 0; i < other.m_size; ++i) {
        pixelData[i] = other.pixelData[i];
    }
    std::cout << "Sprite copied" << std::endl;
}

Sprite& Sprite::operator=(const Sprite& other) {
    if (this == &other) return *this;
    delete[] pixelData;
    m_size = other.m_size;
    pixelData = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        pixelData[i] = other.pixelData[i];
    }
    return *this;
}

Sprite::Sprite (Sprite&& other) noexcept : m_size(other.m_size), pixelData(other.pixelData) {
    other.pixelData = nullptr;
    other.m_size = 0;
    std::cout << "Sprite moved" << std::endl;
}

Sprite& Sprite::operator=(Sprite&& other) noexcept {
    if (this == &other) return *this;
    delete[] pixelData;
    m_size = other.m_size;
    other.m_size = 0;
    pixelData = other.pixelData;
    other.pixelData = nullptr;
    return *this;    
}

void Sprite::draw() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << pixelData[i] << " ";
    }
    std::cout << std::endl;
}

GameObject::GameObject(int health, float x, float y, int size)
                : m_health(health), position(x, y), sprite(size) {}
   
    
GameObject::GameObject(const GameObject& other)
                : m_health(other.m_health), position(other.position), sprite(other.sprite) {}

GameObject& GameObject::operator=(const GameObject& other){
    if (this == &other) {
        return *this;
    }
    m_health = other.m_health;
    sprite = other.sprite;
    position = other.position;
    return *this;
}

GameObject::GameObject(GameObject&& other) noexcept 
                : m_health(other.m_health), position(other.position), sprite(std::move(other.sprite)) {  
    other.m_health = 0;
}

GameObject& GameObject::operator=(GameObject&& other) noexcept{
    if (this == &other) {
        return *this;
    }
    m_health = other.m_health;
    other.m_health = 0;
    sprite = std::move(other.sprite);
    position = other.position;
    return *this;
}

void GameObject::update() {
    std::cout << "Game object is updated in this positions ( " << position.m_x << " , " << position.m_y << " )";
}
    
void GameObject::render() const{
    std::cout << "health of rendering game object : " << m_health << " - ";
    sprite.draw();
}


Player::Player(int health, float x, float y) : GameObject(health, x, y, 10) {}

void Player::update() {
    position.m_x += 0.5f;
    std::cout << "Positions update : ( " << position.m_x << " , " << position.m_y << " )" << std::endl;
}

void Player::render() const {
    std::cout << "health of rendering PLayer : " << m_health << " - "<< std::endl;
    sprite.draw();
}

Enemy::Enemy(int health, float x, float y) : GameObject(health, x, y, 8) {}

void Enemy::update() {
    m_health -= 1;
    std::cout << "Enemy health updated : " << m_health << std::endl;
}
    
void Enemy::render() const {
    std::cout << "health of rendering Enemy : " << m_health << " - "<< std::endl;
    sprite.draw();
}


 NPC::NPC(int health, float x, float y) : GameObject(health, x, y, 5) {}
    
void NPC::update() {    
    std::cout << "NPC updated in positions " << position.m_x << " , " << position.m_y << " )" << std::endl;
}
    
void NPC::render() const {
    std::cout << "health of rendering NPC : " << m_health << " - "<< std::endl;
    sprite.draw();
}