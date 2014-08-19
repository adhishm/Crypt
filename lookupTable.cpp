#include "lookupTable.h"

using namespace std;
using namespace Crypt;

LookupTable::LookupTable()
{
  // Initialize the vectors
  _initializeSourceVectors();
  _initializeCodeVectors();
}

LookupTable::~LookupTable()
{
  // Clear the vectors
  _sourceLetters.clear();
  _sourceLetters_caps.clear();
  _codeLetters.clear();
  _codeLetters_caps.clear();
}


void LookupTable::_initializeCodeVectors()
{
  int capsStart = CAPS_START;
  int smallStart = SMALL_START;
  int i = 0;
  
  // Allocate memory for the vectors
  _codeLetters.assign(26, capsStart);
  _codeLetters_caps.assign(26, smallStart);
  
  while (i < 26)
  {
    ++i;
    ++capsStart;
    ++smallStart;
    
    _codeLetters[i] = capsStart;
    _codeLetters_caps[i] = smallStart;
  }
}

void LookupTable::_initializeSourceVectors()
{
  char defaultChar = '_';
  
  _sourceLetters.assign(26,defaultChar);
  _sourceLetters_caps.assign(26,defaultChar);
}

bool LookupTable::updateCodeLetter(char codeLetter, char sourceLetter)
{
  bool found = false;
  
  for (int i=0; i<26; ++i)
  {
    if (codeLetter == _codeLetters[i])
    {
      found = true;
      _sourceLetters[i] = sourceLetter;
      _sourceLetters_caps[i] = sourceLetter + CAPS_START - SMALL_START;
      break;
    }
    
    if (codeLetter == _codeLetters_caps[i])
    {
      found = true;
      _sourceLetters_caps[i] = sourceLetter;
      _sourceLetters[i] = sourceLetter + SMALL_START - CAPS_START;
      break;
    }
  }
  
  return found;
}

void LookupTable::displayLookupTable() const
{
  int i;
  
  cout << "Code:   ";
  
  for (i=0; i<26; ++i)
  {
    cout << _codeLetters[i] << " ";
  }
  
  cout << "\nSource: ";
  for (i=0; i<26; ++i)
  {
    cout << _sourceLetters[i] << " ";
  }
  cout << endl;
}

bool LookupTable::getSourceLetter(char codeLetter, char& sourceLetter)
{
  bool found = false;
  
  for (int i=0; i<26; ++i)
  {
    if (codeLetter == _codeLetters[i])
    {
      found = true;
      sourceLetter = _sourceLetters[i];
      break;
    }
    
    if (codeLetter == _codeLetters_caps[i])
    {
      found = true;
      sourceLetter = _sourceLetters_caps[i];
      break;
    }
  }
  
  return found;
}

