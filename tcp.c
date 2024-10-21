#include <stdio.h>
#include "common.h"
#include "tcp.h"

// Analyser entete TCP
void analyserTCP(char *trame, TCP *tcp) 
{
       if (trame == NULL || tcp == NULL) {
        error_exit("Fonction analyserTCP() : trame ou tcp est NULL");
    }

    // Remplir les champs de la structure TCP
    tcp->source_port = (trame[0] << 8) | trame[1]; // Port source (2 octets)
    tcp->destination_port = (trame[2] << 8) | trame[3]; // Port destination (2 octets)
    tcp->sequence_number = (trame[4] << 24) | (trame[5] << 16) | (trame[6] << 8) | trame[7]; // Numéro de séquence (4 octets)
    tcp->acknowledhment_number = (trame[8] << 24) | (trame[9] << 16) | (trame[10] << 8) | trame[11]; // Numéro d'accusé de réception (4 octets)
    
    // Data Offset (4 bits) + Reserved (3 bits) + Control Flags (9 bits)
    tcp->data_offset = (trame[12] >> 4) & 0x0F; // Décalage de données en mots de 32 bits
    tcp->reserved = (trame[12] >> 1) & 0x07; // Bits réservés
    tcp->flags = trame[13]; // Flags de contrôle

    tcp->window = (trame[14] << 8) | trame[15]; // Taille de la fenêtre (2 octets)
    tcp->checksum = (trame[16] << 8) | trame[17]; // Checksum (2 octets)
    tcp->urgent_pointer = (trame[18] << 8) | trame[19]; // Pointeur urgent (2 octets)
}

// Afficher entete TCP
void afficherTCP(TCP tcp)
{
    printf("TCP:\n");
    printf("    source_port: %d\n", tcp.source_port);
    printf("    destination_port: %d\n", tcp.destination_port);
    printf("    sequence_number: %d\n", tcp.sequence_number);
    printf("    acknowledhment_number: %d\n", tcp.acknowledhment_number);
    printf("    data_offset: %d\n", tcp.data_offset);
    printf("    reserved: %d\n", tcp.reserved);
    printf("    flags: %d\n", tcp.flags);
    printf("    window: %d\n", tcp.window);
    printf("    checksum: %d\n", tcp.checksum);
    printf("    urgent_pointer: %d\n", tcp.urgent_pointer);
}
