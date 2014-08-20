#ifndef ENCRYPTED_MESSAGE_H
#define ENCRYPTED_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include "lookupTable.h"

using namespace std;

namespace Crypt
{
  class EncryptedMessage
  {
  protected:
    vector<char> _encryptedText;
    vector<char> _decryptedText;
    
    bool _encryptedTextLoaded;
    
    LookupTable _lookupTable;
    
    void _updateDecryptedText();
    bool _isLetter(char c);
  public:
    EncryptedMessage();
    EncryptedMessage(string filename);
    virtual ~EncryptedMessage();
    
    void setEncryptedMessage(string encryptedMessage);
    string getDecryptedMessage();
    string getEncryptedMessage();
    void decryptText();
    
    void displayEncryptedText();
    void displayDecryptedText();
    void display();
  };
}

#endif
