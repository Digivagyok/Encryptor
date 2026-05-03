#include "encrypted_string.h"
#include "caesar_encryptor.h"
#include "iterator.h"

#include "stdio.h"


int main() {
    CaesarEncryptor ROT13 = CaesarEncryptor(13);

    EncryptedString encstr = EncryptedString(ROT13);

    encstr.push_back('f');
    encstr.push_back('l');
    encstr.push_back('a');
    encstr.push_back('k');
    encstr.push_back('o');
    encstr.push_back('n');

    for (Iterator i = encstr.begin(); i != encstr.end(); ++i)
    {
        std::cout << *i;
    }

    std::cout << std::endl;
    

    return 0;
}