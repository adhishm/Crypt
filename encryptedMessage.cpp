#include "encryptedMessage.h"

using namespace std;
using namespace Crypt;

EncryptedMessage::EncryptedMessage()
{
  _encryptedText.assign(1, ' ');
  _decryptedText.assign(1, ' ');
  _encryptedTextLoaded = false;
}

EncryptedMessage::EncryptedMessage(string filename)
{
  ifstream fp (filename.c_str());
  if (fp.is_open())
  {
    string line;
    _encryptedText.clear();
    while (fp.good())
    {
      getline(fp, line);
      int length = line.length();
      for (int i=0; i<length; ++i)
      {
	_encryptedText.push_back(line.at(i));
      }
      line.clear();
    }
    _encryptedTextLoaded = !(_encryptedText.empty());
    fp.close();
    _decryptedText.assign(_encryptedText.size(), '-');
  }
  else
  {
    setEncryptedMessage(" ");
    _decryptedText.assign(1, ' ');
    _encryptedTextLoaded = false;
  }
  
  _lookupTable = LookupTable();
}

void EncryptedMessage::setEncryptedMessage(string encryptedMessage)
{
  int l = encryptedMessage.length();
  _encryptedText.clear();
  for (int i=0; i<l; ++i)
  {
    _encryptedText[i] = encryptedMessage.at(i);
  }
}

string EncryptedMessage::getEncryptedMessage()
{
  string s;
  
  if (_encryptedTextLoaded)
  {
    int l = _encryptedText.size();
    for (int i=0; i<l; ++i)
    {
      s.append(1,_encryptedText[i]);
    }
  }
  else
  {
    s = " ";
  }
  
  return s;
}

EncryptedMessage::~EncryptedMessage()
{
  _encryptedText.clear();
  _decryptedText.clear();
}


string EncryptedMessage::getDecryptedMessage()
{
  string s;
  
  if (_decryptedText.size() > 0)
  {
    int l = _decryptedText.size();
    for (int i=0; i<l; ++i)
    {
      s.append(1,_decryptedText[i]);
    }
  }
  else
  {
    s = " ";
  }
  
  return s;
}

void EncryptedMessage::decryptText()
{
  char source, code;
  while (true)
  {
    display();
    cout << "\nCode letter (non-letter to quit): ";
    cin >> code;
    
    if (!_isLetter(code))
      break;
    
    cout << "\nSource letter (non-letter to quit): ";
    cin >> source;
    if (!_isLetter(source))
      break;
    
    _lookupTable.updateCodeLetter(code, source);
    _updateDecryptedText();
  }
}

void EncryptedMessage::displayEncryptedText()
{
  cout << endl << "Encrypted message:" << endl << getEncryptedMessage();
}

void EncryptedMessage::displayDecryptedText()
{
  cout << endl << "Decrypted message:" << endl << getDecryptedMessage();
}

void EncryptedMessage::display()
{
  displayEncryptedText();
  displayDecryptedText();
  _lookupTable.displayLookupTable();
}

void EncryptedMessage::_updateDecryptedText()
{
  if (_encryptedTextLoaded)
  {
    int l = _encryptedText.size();
    char c, s;
    
    for (int i=0; i<l; ++i)
    {
      c = _encryptedText[i];
      
      if (_isLetter(c))
      {
	if (_lookupTable.getSourceLetter(c, s))
	{
	  _decryptedText[i] = s;
	}
      }
      else
      {
	_decryptedText[i] = c;
      }
    }
  }
}

bool EncryptedMessage::_isLetter(char c)
{
  if ( (c >= 65) && (c <= 90) )
    return true;
  
  if ( (c >= 90) && (c <= 122) )
    return true;
  
  return false;
}



