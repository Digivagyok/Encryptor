#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

/**
 * @file encryptor.h
 * @brief Absztrakt interfész a titkosítási algoritmusok számára.
 */

/**
 * @class Encryptor
 * @brief Absztrakt ősosztály a karakterenként működő titkosítási algoritmusokhoz.
 *
 * Az osztály egységes interfészt biztosít különböző titkosítási
 * algoritmusok számára. A konkrét algoritmusok ebből az osztályból származnak.
 */
class Encryptor {
public:

    /**
     * @brief Egy karakter titkosítása.
     * @param c A titkosítandó karakter.
     * @return A titkosított karakter.
     */
    virtual char encode(char c) const = 0;

    /**
     * @brief Egy karakter visszafejtése.
     * @param c A visszafejtendő karakter.
     * @return A dekódolt karakter.
     */
    virtual char decode(char c) const = 0;

    /**
     * @brief Az algoritmus nevének lekérdezése.
     * @return Az algoritmus neve.
     */
    virtual const char* name() const = 0;

    /**
     * @brief Virtuális destruktor.
     */
    virtual ~Encryptor() {}

    bool operator==(const Encryptor& rhs) const {
        if (name() == rhs.name())
        {
            return true;
        }

        return false;
    }

    bool operator!=(const Encryptor& rhs) const {
        return !(operator==(rhs));
    }
};

#endif
