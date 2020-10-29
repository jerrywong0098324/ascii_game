/* Basically like a char** map
   But instead of using char**, we use TextBox** to store the char in each position
   Additional data can tell you which type this current TextBox hold
*/
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "MemoryLeak.h"
#include "TbxID.h"

class TextBox
{
public:
    TextBox() : c((char)0), id(TbxID::INVALID) {};
    ~TextBox() {};

    // Getters
    char GetCharacter() const { return c; };
    // Get id of this object
    TbxID GetID() const { return id; };
    // Get id based on char
    static TbxID GetID(const char& c)
    {
        switch (c)
        {
            default:
            {
                return TbxID::INVALID;
            }
        }
    }

    // Setters
    void SetCharacter(const char& c) { this->c = c; };
    // Set id based on TbxID
    void SetID(const TbxID& id) { this->id = id; };
    // Set id based on char
    void SetID(const char& c)
    {
        switch (c)
        {
            default:
            {
                id = TbxID::INVALID;
                break;
            }
        }
    }

private:
    char c;
    TbxID id;
};

#endif