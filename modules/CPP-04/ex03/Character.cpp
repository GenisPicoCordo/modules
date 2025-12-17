#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const& name) : _name(name), _floor(0) {
    for (int i = 0; i < 4; ++i) _inv[i] = 0;
}

Character::Character(Character const& other) : _name(other._name), _floor(0) {
    for (int i = 0; i < 4; ++i) _inv[i] = 0;
    copyInventoryFrom(other);
    // floor not copied (design choice). Inventory deep-copied as required.
}

Character& Character::operator=(Character const& other) {
    if (this != &other) {
        _name = other._name;
        clearInventory();
        clearFloor();
        copyInventoryFrom(other);
    }
    return *this;
}

Character::~Character() {
    clearInventory();
    clearFloor();
}

void Character::clearInventory() {
    for (int i = 0; i < 4; ++i) {
        delete _inv[i];
        _inv[i] = 0;
    }
}

void Character::clearFloor() {
    while (_floor) {
        FloorNode* next = _floor->next;
        delete _floor->m;
        delete _floor;
        _floor = next;
    }
}

void Character::addToFloor(AMateria* m) {
    _floor = new FloorNode(m, _floor); // push front
}

void Character::copyInventoryFrom(Character const& other) {
    for (int i = 0; i < 4; ++i) {
        if (other._inv[i])
            _inv[i] = other._inv[i]->clone();
        else
            _inv[i] = 0;
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_inv[i] == 0) {
            _inv[i] = m;
            return;
        }
    }
    // Inventory full: "nothing should happen"
    // (Caller keeps ownership of m in this case.)
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    if (_inv[idx] == 0) return;

    // Must NOT delete. We store it to avoid leaks.
    addToFloor(_inv[idx]);
    _inv[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) return;
    if (_inv[idx] == 0) return;
    _inv[idx]->use(target);
}
