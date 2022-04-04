/**
 * \file ciphers.cpp
 *
 * Ebben a fájlban kell megvalósítania az CaesarCipher, MyCipher, CipherQueue osztályok metódusait.
 * 
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include "memtrace.h"
#include "ciphers.h"


//CAESAR
/**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
std::string CaesarCipher::encode(const std::string& message){
    shift = shift - (shift / 26) * 26;

    std::string caesarEncoded = "";
    for (int i = 0; i < message.length(); ++i) {
        char betu = message[i];
        betu = betu + shift;
        caesarEncoded[i] = betu;
    }
    return caesarEncoded;
}

/**
 * Dekódolja a kapott stringet
 * @param   ciphertext titkosított üzenet
 * @return  a megfejtett nyílt szöveg
 */
std::string CaesarCipher::decode(const std::string &ciphertext) {

}

/**
 * Létrehoz egy másolatot dinamikusan
 * @return  a létrehozott objektumra mutató pointer
 */
Cipher* CaesarCipher::clone() const{

}

