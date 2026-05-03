#ifndef ENCRYPTED_STRING_H
#define ENCRYPTED_STRING_H

#include <cstddef>

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
    char* data = nullptr;              /**< Titkosított karakterek */
    size_t length = 0;     /**< Aktuális hossz */
    size_t capacity = 0;   /**< Kapacitás */
    const Encryptor& enc;    /**< Titkosítási algoritmus */

    void reserve(size_t newCap){
        capacity = newCap;

        char* newData = new char[capacity];

        for (size_t i = 0; i < capacity; i++)
        {
            newData[i] = 0;
        }

        for (size_t i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        
        delete[] data;

        data = newData;
    }

public:

    /**
     * @brief Konstruktor.
     */
    explicit EncryptedString(const Encryptor& enc) : enc(enc){

    }

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
    ~EncryptedString(){
        clear();
        delete[] data;
    }

    /**
     * @brief Értékadás operátor.
     */
    EncryptedString& operator=(const EncryptedString& other);

    /**
     * @brief Indexelés.
     */
    char operator[](size_t index) const {
        if(index < 0 || index >= length){
            throw "Index out of range";
        }

        return data[index];
    }

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
    bool operator==(const EncryptedString& rhs) const {
        if (length != rhs.length || capacity != rhs.capacity || enc != rhs.enc)
        {
            return false;
        }

        for (size_t i = 0; i < length; i++)
        {
            if(this->data[i] != rhs.data[i]) {
                return false;
            }
        }
        
        return true;
    }

    bool operator!=(const EncryptedString& rhs) const;

    /**
     * @brief Karakter hozzáadása.
     */
    void push_back(char c) {
        if (length >= capacity)
        {
            reserve(capacity * 2);
        }
        data[length] = enc.encode(c);

        length++;
    }

    /**
     * @brief Méret lekérdezése.
     */
    size_t size() const {
        return length;
    }

    /**
     * @brief String törlése.
     */
    void clear() {
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = 0;
        }
    }

    char decode_at(size_t index) const {
        return enc.decode(data[index]);
    }

    /**
     * @brief Iterátor kezdete.
     */
    Iterator begin() const {
        return Iterator(*this, 0);
    }

    /**
     * @brief Iterátor vége.
     */
    Iterator end() const {
        return Iterator(*this, length);
    }
};

#endif
