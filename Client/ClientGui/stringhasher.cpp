/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <stringhasher.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file declares the StringHasher class, which provides functionality for hashing passwords using a specified hashing algorithm.
 * ---------------------------------------------------------------------------------------------------
 */


#include "stringhasher.h"

std::string StringHasher::operator()(const std::string& input) const {
    std::hash<std::string> hasher;
    size_t hashValue = hasher(input); // using the stl hasher, used for unordered_map
    return std::to_string(hashValue);
}
