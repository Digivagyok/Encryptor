#ifndef XOR_ENCRYPTOR_H
#define XOR_ENCRYPTOR_H

#include "encryptor.h"

/**
 * @file xor_encryptor.h
 * @brief XOR alapú titkosítás implementációja.
 */

/**
 * @class XorEncryptor
 * @brief XOR műveleten alapuló titkosítási algoritmus.
 *
 * Minden karaktert egy kulccsal XOR-ol.
 * A művelet szimmetrikus, tehát encode és decode azonos.
 */
class XorEncryptor : public Encryptor {
private:
    char key; /**< Titkosítási kulcs */

public:

    /**
     * @brief Konstruktor.
     * @param key A titkosítási kulcs.
     */
    explicit XorEncryptor(char key);

    char encode(char c) const;
    char decode(char c) const;
    const char* name() const;
};

#endif
