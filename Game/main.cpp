#include "game.hpp"
int main() {

    std::vector<GameObject*> entities;
    entities.push_back(new Player());
    entities.push_back(new Enemy());
    entities.push_back(new NPC());

    for (auto* obj : entities) {
        obj->update();
        obj->render();
    }

    Player p1;
    Player p2 = p1;
    Player p3 = std::move(p1);

    for (auto* obj : entities) {
        delete obj;
    }

    return 0;
}