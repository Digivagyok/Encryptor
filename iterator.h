#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * @file iterator.h
 * @brief Iterátor deklaráció a titkosított stringhez.
 */

class EncryptedString;

/**
 * @class Iterator
 * @brief Iterátor az EncryptedString bejárásához.
 *
 * A dekódolt karaktereken iterál végig.
 */
class Iterator {
private:
    const EncryptedString& owner; /**< Tulajdonos string */
    unsigned int index;           /**< Aktuális pozíció */

public:

    /**
     * @brief Konstruktor.
     * @param owner A string, amin iterálunk.
     * @param index Kezdő index.
     */
    Iterator(const EncryptedString& owner, unsigned int index) : owner(owner), index(index) {}

    /**
     * @brief Dereferálás.
     * @return Az aktuális karakter (dekódolva).
     */
    char operator*() const;

    /**
     * @brief Prefix növelés.
     * @return Az iterátor referenciája.
     */
    Iterator& operator++() {
        index++;
        return *this;
    }

    /**
     * @brief Összehasonlítás.
     */
    bool operator!=(const Iterator& rhs) const;
};

#endif
