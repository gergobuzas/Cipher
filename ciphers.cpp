/**
 * \file ciphers.cpp
 *
 * Ebben a fájlban kell megvalósítania az CaesarCipher, MyCipher, CipherQueue osztályok metódusait.
 * 
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include "memtrace.h"
#include "ciphers.h"

using std::string;
//CAESAR
/**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
std::string CaesarCipher::encode(const std::string& message){
    int ogshift = shift;
    shift = shift % 26;

    string caesarEncoded = "";
    for (int i = 0; message[i] != '\0'; ++i) {
        char betu = message[i];
        unsigned char shiftedChar = betu + shift;
        if(betu == ' ')
            caesarEncoded += betu;
        else if (betu < 'a' or betu > 'z')
            throw "E0PWAX";
        else{
            while(shiftedChar < 'a'){
                shiftedChar = shiftedChar + 'z' - 'a' + 1;
            }
            while(shiftedChar > 'z'){
                shiftedChar = shiftedChar - 'z' + 'a' - 1;
            }
            caesarEncoded += shiftedChar;
        }
    }
    shift = ogshift;
    return caesarEncoded;
}

/**
 * Dekódolja a kapott stringet
 * @param   ciphertext titkosított üzenet
 * @return  a megfejtett nyílt szöveg
 */
std::string CaesarCipher::decode(const std::string &ciphertext) {
    int ogshift = shift;
    shift = shift % 26;

    string caesarDecoded = "";
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char betu = ciphertext[i];
        unsigned char shiftedChar = betu - shift;
        if(betu == ' ')
            caesarDecoded += betu;
        else if (betu < 'a' or betu > 'z')
            throw "E0PWAX";
        else{
            while(shiftedChar < 'a'){
                shiftedChar = shiftedChar + 'z' - 'a' + 1;
            }
            while(shiftedChar > 'z'){
                shiftedChar = shiftedChar - 'z' + 'a' - 1;
            }
            caesarDecoded += shiftedChar;
        }
    }
    shift = ogshift;
    return caesarDecoded;
}

/**
 * Létrehoz egy másolatot dinamikusan
 * @return  a létrehozott objektumra mutató pointer
 */
Cipher* CaesarCipher::clone() const{
    Cipher* cloned;
    cloned = new CaesarCipher(*this);
    return cloned;
}

//MYCIPHER FÜGGVÉNYEI

string MyCipher::encode(const string& message){
    string encodedString = "";
    int keyIdx = 0, currentOffset = offset, keyShift, shift;

    for (int i = 0; message[i] != '\0'; ++i) {
        char betu = message[i];
        keyShift = this->key[keyIdx] - 'a';
        shift = keyShift + currentOffset;
        unsigned char encodedChar = betu + shift;

        if(betu == ' '){
            encodedString += ' ';
            keyIdx++; currentOffset++;
        }
        else if (betu < 'a' or betu > 'z')
            throw "E0PWAX";
        else{
            while (encodedChar > 'z'){
                encodedChar = encodedChar - 'z' + 'a' - 1;
            }

            while (encodedChar < 'a'){
                encodedChar = encodedChar + 'z' - 'a' + 1;
            }

            encodedString += encodedChar;

            keyIdx++; currentOffset++;
            if(keyIdx == key.length())
                keyIdx = 0;
            }
        }
    return encodedString;
}
string MyCipher::decode(const std::string &ciphertext) {
    string decodedString = "";
    int keyIdx = 0, currentOffset = offset, keyShift, shift;

    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char betu = ciphertext[i];
        keyShift = this->key[keyIdx] - 'a';
        shift = keyShift + currentOffset;
        unsigned char decodedChar = betu - shift;

        if(betu == ' '){
            decodedString += ' ';
            keyIdx++; currentOffset++;
        }
        else if (betu < 'a' or betu > 'z')
            throw "E0PWAX";
        else{
            while (decodedChar > 'z'){
                decodedChar = decodedChar - 'z' + 'a' - 1;
            }

            while (decodedChar < 'a'){
                decodedChar = decodedChar + 'z' - 'a' + 1;
            }
            decodedString += decodedChar;

            keyIdx++; currentOffset++;
            if(keyIdx == key.length())
                keyIdx = 0;
        }
    }
    return decodedString;
}
Cipher* MyCipher::clone() const{
    Cipher* cloned;
    cloned = new MyCipher(*this);
    return cloned;
}



