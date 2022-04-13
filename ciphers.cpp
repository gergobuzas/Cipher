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
    shift = shift - (shift / 26) * 26;

    string caesarEncoded = "";
    for (int i = 0; message[i] != '\0'; ++i) {
        char betu = message[i];
        if(betu >= 'a' and betu <= 'z'){
            int szam = int(betu) + shift;
            if(szam > 128){
                szam = szam - 128;
                betu = char('a' + szam + 5);
            }
            else{
                betu = char(int(betu) + shift);
                while(betu < 'a'){
                    betu = betu + 'z' - 'a' + 1;
                }
                while(betu > 'z'){
                    betu = betu - 'z' + 'a' - 1;
                }
            }
        }
        else{
            throw "E0PWAX";
        }
        caesarEncoded += betu;
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
    shift = shift - (shift / 26) * 26;

    string caesarDecoded = "";
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char betu = ciphertext[i];
        if(betu >= 'a' and betu <= 'z'){
            betu = betu - shift;
            if(betu < 'a'){
                betu = betu + 'z' - 'a' + 1;
            }
            if(betu > 'z'){
                betu = betu - 'z' + 'a' - 1;
            }
        }
        else{
            throw "E0PWAX";
        }
        caesarDecoded += betu;
    }
    shift = ogshift;
    return caesarDecoded;
}

/**
 * Létrehoz egy másolatot dinamikusan
 * @return  a létrehozott objektumra mutató pointer
 */
Cipher* CaesarCipher::clone() const{
    CaesarCipher* cloned;
    cloned = new CaesarCipher[1];
}

//MYCIPHER FÜGGVÉNYEI

string MyCipher::encode(const string& message){
    string encodedString = "";
    int keyIdx = 0, currentOffset = offset, shift;

    for (int i = 0; message[i] != '\0'; ++i) {
        char betu = message[i];
        shift = keyIdx + currentOffset;
        encodedString += std::to_string(betu + shift);

        keyIdx++; currentOffset++;
        if(keyIdx == key.length())
            keyIdx = 0;
    }

    return encodedString;
}
string MyCipher::decode(const std::string &ciphertext) {
    string decodedString = "";
    int keyIdx = 0, currentOffset = offset, shift;

    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char betu = ciphertext[i];
        shift = keyIdx + currentOffset;
        decodedString += std::to_string(betu - shift);

        keyIdx++; currentOffset++;
        if(keyIdx == key.length())
            keyIdx = 0;
    }

    return decodedString;
}
Cipher* MyCipher::clone() const{

}



