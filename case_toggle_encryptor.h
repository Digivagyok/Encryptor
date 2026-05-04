#ifndef CASE_TOGGLE_ENCRYPTOR_H
#define CASE_TOGGLE_ENCRYPTOR_H

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
class CaseToggleEncryptor : public Encryptor {
public:

    /**
     * @brief Konstruktor.
     * @param key A titkosítási kulcs.
     */
    explicit CaseToggleEncryptor() {

    }

    char encode(char c) const {
        if (!std::isalpha(c))
        {
            return c;
        }
        
        if (std::islower(c))
        {
            return std::toupper(c);
        }
    
        return std::tolower(c);
    }

    char decode(char c) const {
        return encode(c);
    }

    const char* name() const {
        return "Case toggle encryptor";
    }

    bool equals(const Encryptor& rhs) const override {
        if(name() != std::string(rhs.name())) {
            return false;
        }

        return true;
    }
};

#endif
