#include "encrypted_string.h"
#include "caesar_encryptor.h"
#include "xor_encryptor.h"
#include "iterator.h"

#include "stdio.h"

int main()
{
    CaesarEncryptor ROT13 = CaesarEncryptor(13);

    EncryptedString encstr = EncryptedString(ROT13);

    encstr.push_back('f');
    encstr.push_back('l');
    encstr.push_back('a');
    encstr.push_back('k');
    encstr.push_back('o');
    encstr.push_back('n');

    // iterátoron keresztül normálisan olvasható
    for (Iterator i = encstr.begin(); i != encstr.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;

    // indexelve viszont rejtjelezve van
    for (size_t i = 0; i < encstr.size(); i++)
    {
        std::cout << encstr[i];
    }

    std::cout << std::endl;

    CaesarEncryptor ROT5(5);
    EncryptedString enc2(ROT5);

    std::cout << (ROT13 == ROT5) << std::endl;

    enc2.push_back('a');
    enc2.push_back('b');
    enc2.push_back('c');

    for (Iterator i = enc2.begin(); i != enc2.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;

    EncryptedString enc3 = encstr + enc2;

    for (Iterator i = enc3.begin(); i != enc3.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;

    for (size_t i = 0; i < enc3.size(); i++)
    {
        std::cout << enc3[i];
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "XOR ENC" << std::endl;

    XorEncryptor xorenc(111);

    EncryptedString enc4(xorenc);
    enc4.push_back('f');
    enc4.push_back('l');
    enc4.push_back('a');
    enc4.push_back('k');
    enc4.push_back('o');
    enc4.push_back('n');

    for (Iterator i = enc4.begin(); i != enc4.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;

    for (size_t i = 0; i < enc4.size(); i++)
    {
        std::cout << (int)enc4[i] << " ";
        //std::cout << (char)(int)enc4[i] << "\n";
    }

    std::cout << std::endl;

    enc4 += enc3;

    for (Iterator i = enc4.begin(); i != enc4.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;
    return 0;
}