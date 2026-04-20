#ifndef CAESAR_ENCRYPTOR_H
#define CAESAR_ENCRYPTOR_H

#include "encryptor.h"

/**
 * @file caesar_encryptor.h
 * @brief Caesar-féle karaktereltolás implementációja.
 */

/**
 * @class CaesarEncryptor
 * @brief Karaktereltoláson alapuló titkosítás.
 *
 * A karaktereket egy adott értékkel eltolja az ASCII tartományon belül.
 */
class CaesarEncryptor : public Encryptor {
private:
    int shift; /**< Eltolás mértéke */

public:

    /**
     * @brief Konstruktor.
     * @param shift Az eltolás mértéke.
     */
    explicit CaesarEncryptor(int shift);

    char encode(char c) const;
    char decode(char c) const;
    const char* name() const;
};

#endif
