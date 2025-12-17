#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
    private:
        AMateria* _tpl[4];

        void clearAll();
        void copyFrom(MateriaSource const& other);

    public:
        MateriaSource();
        MateriaSource(MateriaSource const& other);
        MateriaSource& operator=(MateriaSource const& other);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif
