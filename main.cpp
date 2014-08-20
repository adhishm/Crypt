#include <iostream>
#include <string>
#include "encryptedMessage.h"

using namespace std;
using namespace Crypt;

int main(int argc, char **argv)
{
    string filename;
    
    cout << endl << "Message file name: ";
    cin >> filename;
    
    if (!filename.empty())
    {
      EncryptedMessage* encryptedMessage = new EncryptedMessage(filename);
      encryptedMessage->decryptText();
    }
    
    return 0;
}
