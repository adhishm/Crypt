#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef CAPS_START
#define CAPS_START 65
#endif

#ifndef SMALL_START
#define SMALL_START 97
#endif

namespace Crypt
{
  /**
   * @brief Class LookupTable to represent a lookup table for the 
   */
  class LookupTable
  {
  protected:
    // Protected members
    vector<char> _sourceLetters;
    vector<char> _sourceLetters_caps;
    vector<char> _codeLetters;
    vector<char> _codeLetters_caps;
    
    // Protected functions
    void _initializeSourceVectors();
    void _initializeCodeVectors();
  public:
    LookupTable();
    
    virtual ~LookupTable();
    
    bool updateCodeLetter (char codeLetter, char sourceLetter);
    void displayLookupTable() const;
    bool getSourceLetter (char codeLetter, char &sourceLetter);
  };
}	// namespace Crypt

#endif
