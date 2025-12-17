#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
    private:
        struct FloorNode {
            AMateria*   m;
            FloorNode*  next;
            FloorNode(AMateria* materia, FloorNode* n) : m(materia), next(n) {}
        };

        std::string _name;
        AMateria*   _inv[4];
        FloorNode*  _floor; // linked list of unequipped materias

        void clearInventory();
        void clearFloor();
        void addToFloor(AMateria* m);
        void copyInventoryFrom(Character const& other);

    public:
        Character(std::string const& name);
        Character(Character const& other);
        Character& operator=(Character const& other);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
