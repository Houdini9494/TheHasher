#include <iostream>     // Libreria per input e output
#include <openssl/sha.h> // Libreria OpenSSL per utilizzare algoritmi di hash SHA
#include <string>        // Libreria per gestire le stringhe
#include <sstream>       // Libreria per manipolare stringstream, utile per costruire la stringa hash in formato esadecimale
#include <iomanip>       // Libreria per formattazione dell'output (esadecimale e con zeri riempitivi)

// Funzione che calcola l'hash SHA3-512 di un input di tipo stringa
std::string sha3_512(const std::string& input) {
    unsigned char hash[SHA512_DIGEST_LENGTH]; // Array per memorizzare il valore dell'hash generato (64 byte per SHA-512)
    SHA512_CTX sha3_context;                  // Contesto per memorizzare lo stato dell'algoritmo di hash durante il calcolo

    // Inizializza il contesto per SHA3-512
    SHA512_Init(&sha3_context);
    // Aggiorna il contesto con l'input, cioè i dati da hashare
    SHA512_Update(&sha3_context, input.c_str(), input.length());
    // Completa il calcolo dell'hash e lo salva nell'array 'hash'
    SHA512_Final(hash, &sha3_context);

    // Convertiamo l'hash in una stringa esadecimale
    std::stringstream ss;
    for(int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        // Ogni byte viene convertito in esadecimale e aggiunto allo stream
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return ss.str(); // Restituisce l'hash come stringa in formato esadecimale
}

int main() {
    std::string input; // Stringa per memorizzare l'input dell'utente
    std::cout << "Inserisci il testo da cifrare: \n";
    std::getline(std::cin, input); // Legge una linea di input dall'utente

    // Calcola l'hash SHA3-512 della stringa di input
    std::string hash = sha3_512(input);
    // Stampa il risultato dell'hash
    std::cout << "SHA3-512 hash of \"" << input << "\" is: \n" << hash << std::endl;
    return 0;
}
