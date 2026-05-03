#ifndef CAESAR_ENCRYPTOR_H
#define CAESAR_ENCRYPTOR_H

#include "encryptor.h"
#include <iostream>

//for future proofing, in case I want to add other alphabets
#define ALPHABET_LENGTH 26

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
class CaesarEncryptor : public Encryptor
{
private:
    int shift; /**< Eltolás mértéke */

public:
    /**
     * @brief Konstruktor.
     * @param shift Az eltolás mértéke.
     */
    explicit CaesarEncryptor(int shift)
    {
        shift = shift % ALPHABET_LENGTH;
        if (shift < 0)
        {
            shift += ALPHABET_LENGTH;
        }
        this->shift = shift;
    }

    char encode(char c) const
    {
        if (c == ' ')
        {
            return ' ';
        }
        
        bool lower = std::islower(c);
        c = std::tolower(c);

        if (std::isalpha(c))
        {
            int distFromA = (int)c - (int)'a';
            int totalShift = (distFromA + shift) % ALPHABET_LENGTH;
            
            char ch = (char)((int)'a' + totalShift);

            if (lower)
            {
                return ch;
            }
            
            return (char)std::toupper(ch);
            
        }

        return c;
    };

    char decode(char c) const {
        if (c == ' ')
        {
            return ' ';
        }
        
        bool lower = std::islower(c);
        c = std::tolower(c);

        if (std::isalpha(c))
        {
            int distFromA = (int)c - (int)'a';
            int totalShift = (distFromA - shift) % ALPHABET_LENGTH;

            if (totalShift < 0)
            {
                totalShift += ALPHABET_LENGTH;
            }
            
            
            char ch = (char)((int)'a' + totalShift);

            if (lower)
            {
                return ch;
            }
            
            return (char)std::toupper(ch);
            
        }

        return c;
    }
    const char *name() const {
        return "CaesarEncryptor";
    };
};

#endif
