#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) _tpl[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const& other) {
    for (int i = 0; i < 4; ++i) _tpl[i] = 0;
    copyFrom(other);
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
    if (this != &other) {
        clearAll();
        copyFrom(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearAll();
}

void MateriaSource::clearAll() {
    for (int i = 0; i < 4; ++i) {
        delete _tpl[i];
        _tpl[i] = 0;
    }
}

void MateriaSource::copyFrom(MateriaSource const& other) {
    for (int i = 0; i < 4; ++i) {
        if (other._tpl[i])
            _tpl[i] = other._tpl[i]->clone();
        else
            _tpl[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;

    for (int i = 0; i < 4; ++i) {
        if (_tpl[i] == 0) {
            _tpl[i] = m->clone();
            delete m; // prevent leak from learnMateria(new Ice())
            return;
        }
    }
    // full: "nothing should happen", but we still must avoid leaks
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_tpl[i] && _tpl[i]->getType() == type)
            return _tpl[i]->clone();
    }
    return 0;
}
