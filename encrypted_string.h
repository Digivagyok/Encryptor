#ifndef ENCRYPTED_STRING_H
#define ENCRYPTED_STRING_H

#include "encryptor.h"
#include "iterator.h"

/**
 * @file encrypted_string.h
 * @brief Titkosított string osztály deklarációja.
 */

/**
 * @class EncryptedString
 * @brief Titkosított formában tárolt szöveg.
 *
 * A karaktereket titkosítva tárolja, de a felhasználó
 * számára dekódolt formában biztosítja az elérést.
 */
class EncryptedString {
private:
    char* data;              /**< Titkosított karakterek */
    unsigned int length;     /**< Aktuális hossz */
    unsigned int capacity;   /**< Kapacitás */
    const Encryptor* enc;    /**< Titkosítási algoritmus */

    void reserve(unsigned int newCap);

public:

    /**
     * @brief Konstruktor.
     */
    explicit EncryptedString(const Encryptor& enc);

    /**
     * @brief Konstruktor C-stringből.
     */
    EncryptedString(const char* text, const Encryptor& enc);

    /**
     * @brief Másoló konstruktor.
     */
    EncryptedString(const EncryptedString& other);

    /**
     * @brief Destruktor.
     */
    ~EncryptedString();

    /**
     * @brief Értékadás operátor.
     */
    EncryptedString& operator=(const EncryptedString& other);

    /**
     * @brief Indexelés.
     */
    char operator[](unsigned int index) const;

    /**
     * @brief Összefűzés.
     */
    EncryptedString operator+(const EncryptedString& rhs) const;

    /**
     * @brief Összefűzés és értékadás.
     */
    EncryptedString& operator+=(const EncryptedString& rhs);

    /**
     * @brief Összehasonlítás.
     */
    bool operator==(const EncryptedString& rhs) const;

    bool operator!=(const EncryptedString& rhs) const;

    /**
     * @brief Karakter hozzáadása.
     */
    void push_back(char c);

    /**
     * @brief Méret lekérdezése.
     */
    unsigned int size() const;

    /**
     * @brief String törlése.
     */
    void clear();

    /**
     * @brief Iterátor kezdete.
     */
    Iterator begin() const;

    /**
     * @brief Iterátor vége.
     */
    Iterator end() const;
};

#endif
