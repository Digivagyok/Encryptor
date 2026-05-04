#ifndef XOR_ENCRYPTOR_H
#define XOR_ENCRYPTOR_H

#include "encryptor.h"
#include <iostream>

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
    explicit XorEncryptor(char key) : key(key) {

    }

    char encode(char c) const {
        return key ^ c;
    }

    char decode(char c) const {
        return key ^ c;
    }

    const char* name() const {
        return "XOR encryptor";
    }

    char getKey() const override {
        return key;
    }

    bool equals(const Encryptor& rhs) const override {
        if(name() != std::string(rhs.name())) {
            return false;
        }

        return getShift() == rhs.getShift() && getKey() == rhs.getKey();
    }
};

#endif
