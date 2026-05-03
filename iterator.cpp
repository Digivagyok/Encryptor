#include "iterator.h"
#include "encrypted_string.h"

char Iterator::operator*() const
{
    return owner.decode_at(index);
}

bool Iterator::operator!=(const Iterator &rhs) const
{
    if (&owner == &rhs.owner && index == rhs.index)
    {
        return false;
    }
    return true;
}