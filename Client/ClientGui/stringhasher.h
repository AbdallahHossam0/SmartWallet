/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <stringhasher.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file declares the StringHasher class, which provides functionality for hashing passwords using a specified hashing algorithm.
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef STRINGHASHER_H
#define STRINGHASHER_H

#include <string>
#include <functional>

// function object to hash the password
class StringHasher {
  public:
    std::string operator()(const std::string& input) const;
};

#endif // STRINGHASHER_H
